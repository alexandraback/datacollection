#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include <math.h>
#include "ttmath/ttmath.h"//A bigint library
using namespace std;

void printValue(char str[]) {
	ttmath::UInt<40> counter;
	counter = str;
	counter *= counter;
	stringstream ss2;
	ss2 << counter;
	string str2 = ss2.str();
	int len = str2.length() - 1;
	int limit = str2.length() >> 1;
	bool palin = true;
	for(int z = 0; z < limit && palin; z++) {
		if(str2[z] != str2[len-z]) {
			palin = false;
		}
	}
	if(palin) {
		cout << str;
		cout << '\n';
	}
}

int main(int argc, char ** argv) {
	char str[50];
	unsigned int val;
	unsigned int min;
	
	cout << "1\n";
	cout << "2\n";
	cout << "3\n";
	
	for(int x = 1; x <= 5; x++) {
		val = 1 << x;
		min = (val-1) >> 1;
		min++;
		
		while(val > min) {
			for(int digit = 0; digit < x; digit++) {
				if(min & (1 << digit)) {
					str[x - digit - 1] = '1';
					str[x + digit] = '1';
				}
				else {
					str[x - digit - 1] = '0';
					str[x + digit] = '0';
				}
			}
			str[2*x] = 0;
			printValue(str);
			
			min++;
		}
		
		
		str[0] = '2';
		str[2*x - 1] = '2';
		for(int z = 1; z < 2*x - 1; z++) {
			str[z] = '0';
		}
		printValue(str);
		
		min = (val-1) >> 1;
		min++;
		
		while(val > min) {
			for(int digit = 0; digit < x; digit++) {
				if(min & (1 << digit)) {
					str[x - digit - 1] = '1';
					str[x + digit + 1] = '1';
				}
				else {
					str[x - digit - 1] = '0';
					str[x + digit + 1] = '0';
				}
			}
			
			str[x] = '0';
			str[2*x + 1] = 0;
			if(str[0] != '0') {
				printValue(str);
			}
			
			str[x] = '1';
			if(str[0] != '0') {
				printValue(str);
			}
			
			str[x] = '2';
			if(str[0] != '0') {
				printValue(str);
			}
			
			min++;
		}
		
		str[0] = '2';
		str[x] = '0';
		str[2*x] = '2';
		str[2*x + 1] = 0;
		for(int z = 1; z < 2*x; z++) {
			str[z] = '0';
		}
		printValue(str);
		str[x] = '1';
		printValue(str);
	}
	
	return 0;
}
