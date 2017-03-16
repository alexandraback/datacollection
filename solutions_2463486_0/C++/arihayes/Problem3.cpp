#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <math.h>
#include "ttmath/ttmath.h"//A bigint library
using namespace std;

int main(int argc, char ** argv) {
	ttmath::UInt<40> squares[46228];
	ifstream roots;
	roots.open("roots");//precomputed with Problem3Precomp.cpp
	for(int x = 0; x < 46228; x++) {
		roots >> squares[x];
		squares[x] *= squares[x];
	}
	roots.close();
	
	int numCases;
	cin >> numCases;
	for(int c = 0; c < numCases; c++) {
		ttmath::UInt<40> lower;
		ttmath::UInt<40> higher;
		ttmath::UInt<40> num;
		cin >> lower;
		cin >> higher;
		int fairs = 0;
		for(int index = 0; index < 46228; index++) {
			num = squares[index];
			if(num > higher) {
				break;
			}
			else if(num >= lower) {
				fairs++;
			}
		}
		
		cout << "Case #" << (c+1) << ": ";
		cout << fairs;
		cout << "\n";
	}
}
