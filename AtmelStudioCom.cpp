#include "IRremote.h"

/*
 * AtmelStudioCom.cpp
 *
 * Created: 11/10/2015 7:54:03 μμ
 *  Author: VFXCode
 * 
 * This makes a few functions to make IRremote 
 * compatible with Atmel Studio.
 * Tested on Atmel Studio 7.
 *
 */ 
#ifdef ATMEL_STUDIO
void IRdigitalWrite(volatile uint8_t *port, uint8_t portpin, uint8_t set) {
	if (set) {
		*port |= (1<<portpin);
	} else {
		*port &= (~(1<<portpin));
	}
}

void IRpinMode(volatile uint8_t *port, uint8_t portpin, uint8_t set){
	if (set) {
		*(port-1) |= (1<<portpin);
	} else {
		*(port-1) &= (~(1<<portpin));
	}
}

uint8_t IRdigitalRead(volatile uint8_t *port, uint8_t portpin) {
	return ((*(port-2)>>portpin)&0x01);
}

#endif