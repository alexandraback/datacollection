/*
 * Main.cpp
 *
 *  Created on: May 11, 2014
 *      Author: pxp943
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <climits>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int testcases, n, l;
int countflip;

bool checkBase2(unsigned long long num) {
	unsigned long long check = 1;

	while (check < num) {
		check <<= 1;
	}

	if (check == num)
		return true;
	else
		return false;
}

int gen(unsigned long long upper, unsigned long long lower) {
	int count = 0;
	while (upper < lower) {
		upper <<= 1;
		count++;
	}

	return count;
}

unsigned long long gcd ( unsigned long long  upper, unsigned long long  lower )
{
  unsigned long long  tmp;
  while ( upper != 0 ) {
	  tmp = upper; upper = lower%upper;  lower = tmp;
  }
  return lower;
}

int main() {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	ifstream inFile("A-large.in");
	ofstream outFile ("output.txt");

	string up, low;

	int index = 0;

	unsigned long long upper;
	unsigned long long lower;
	unsigned long long numgcd;

	int tmp;

	inFile >> testcases;

	for (int i = 0; i < testcases; ++i) {
		inFile >> up;

		index = up.find_first_of('/');

		low = up.substr(index + 1);
		up = up.substr(0, index);

		lower =0;
		upper = 0;

		for (int j = 0; j < low.length(); ++j) {
			tmp = low.at(j) - '0';
			lower += tmp;

			lower *= 10;
		}
		lower /= 10;

		for (int j = 0; j < up.length(); ++j) {
			tmp = up.at(j) - '0';
			upper += tmp;

			upper *= 10;
		}
		upper /= 10;



		numgcd = gcd(upper, lower);

		upper /= numgcd;
		lower /= numgcd;

		//cout << upper << " / " << lower << endl;

		outFile << "Case #" << (i+1) << ": " ;

		if(checkBase2(lower))
		{
			outFile << gen(upper,lower) << endl;
		}
		else
		{
			outFile << "impossible" << endl;
		}
	}
	inFile.close();
	outFile.close();

	return 0;
}

