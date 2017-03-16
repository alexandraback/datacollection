#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main() {
	int numCases;
	cin >> numCases;
	
	char * buffer = (char *) malloc(32);
	
	for(int x = 1; x <= numCases; x++) {
		cin >> buffer;
		char * target = buffer;
		int length = strlen(target);
		
		int steps = 0;
		while(steps < 20) {
			int lastDigit = target[length - 1] - '0';
			
			if(length == 1 || (length == 2 && target[0] == '1')) {
				steps += atoi(target);
				break;
			}
			
			if(length > 3 && target[length - 2] > target[1]) {
				int i = 0;
				int j = length - 1;
				while(i < j) {
					char temp = target[i];
					target[i] = target[j];
					target[j] = temp;
					i++;
					j--;
				}
				steps++;
			} else if(lastDigit > 1) {
				steps += lastDigit - 1;
				target[length - 1] = '1';
			} else if(lastDigit == 1 && target[0] != '1') {
				int i = 0;
				int j = length - 1;
				while(i < j) {
					char temp = target[i];
					target[i] = target[j];
					target[j] = temp;
					i++;
					j--;
				}
				steps++;
			} else {
				for(int d = length - 1; d >= 0; d--) {
					int digit = target[d] - '0';
					if(digit == 0) {
						target[d] = '9';
					} else {
						target[d] = (digit - 1) + '0';
						break;
					}
				}
				target = target + 1;
				length--;
				steps++;
			}
		}
		
		cout << "Case #" << x << ": "; 
		cout << steps;
		cout << "\n";
	}
}
