// coin.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
using namespace std;

// base starts at 2
unsigned long powerTable[9][10] = { 0 };
void initializePowerTable();
unsigned long pow(int base, int exp);
void listJamCoins(int n, int j);
void displayJamCoin(unsigned long value, int n, int j);
void displayDivisors(unsigned long value);
void displayDivisorBase10(unsigned long value, int j);

int main()
{
	int t;
	// string str;

	cin >> t;

	// getline(cin, str); // read until end of line (needed if getline is used)
	initializePowerTable();

	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ":\n";

		int n, j;

		cin >> n >> j;

		listJamCoins(n, j);
		// cin >> str;
		// getline(cin, str);

		//cout << "\n";
	}

	return 0;
}

void listJamCoins(int n, int j)
{
	unsigned long  top = 1024;

	if (j == 50) {
		top = pow(2, 6+1);
	}
	else if (j == 500) {
		top = pow(2, 9+1);
	}
	else if (j == 3) {
		top = pow(2, 2+1);
	}
	unsigned long  value;
	for (unsigned long  i = 0; i < j; i++) {
		unsigned long value = 2 * i + 1 + top;

		//cout << value << "\n";

		displayJamCoin(value, n, j);
		displayDivisors(value);
		displayDivisorBase10(value, j);

		cout << "\n";
	}
}

void displayJamCoin(unsigned long  value, int n, int j)
{
	bitset<4> d4(value);
	bitset<8> d8(value);
	bitset<11> d11(value);

	switch (j) {
	case 3:
		// 4 digits
		cout << d4;
		for (int i = 0; i < n - 2 * 4; i++) {
			cout << "0";
		}
		cout << d4;
		break;

	case 50:
		// 8 digits
		cout << d8;
		for (int i = 0; i < n - 2 * 8; i++) {
			cout << "0";
		}
		cout << d8;
		break;

	case 500:
		// 1 digits
		cout << d11;
		for (int i = 0; i < n - 2 * 11; i++) {
			cout << "0";
		}
		cout << d11;
		break;

	default: 
		cout << "unsupported J (number of requested sample)";
		break;
	}
}

// assume max value == 11 digits binary
// dispaly base 2 to 10
void displayDivisors(unsigned long value)
{
	for (int base = 2; base < 10; base++) {
		unsigned long converted = 0;
		unsigned long mask = 1;

		// assume 11 bin digits only
		for (int i = 0; i < 11; i++) {
			if (value & mask) {
				converted += pow(base, i);
			}
			mask = mask << 1;
		}

		cout << " " << converted;
	}
}

void displayDivisorBase10(unsigned long value, int j)
{
	bitset<4> d4(value);
	bitset<8> d8(value);
	bitset<11> d11(value);

	cout << " ";
	switch (j) {
	case 3:
		// 4 digits
		cout << d4;
		break;

	case 50:
		// 8 digits
		cout << d8;
		break;

	case 500:
		// 1 digits
		cout << d11;
		break;

	default:
		cout << "unsupported J (number of requested sample)";
		break;
	}
}

//unsigned long powerTable[9][10] = { 0 };
void initializePowerTable()
{
	unsigned long runVal;

	for (int base = 2; base <= 10; base++) {
		runVal = base;

		//cout << "Base " << base << ": ";

		for (int exp = 1; exp <= 10; exp++) {

			//cout << runVal << " - ";

			powerTable[base - 2][exp - 1] = runVal;
			runVal *= base;
		}

		//cout << "\n";
	}
}


unsigned long pow(int base, int exp)
{
	if (base > 10 || exp > 10) {
		cout << "unexpected value\n";
		return -1;
	}
	if (base == 10 && exp == 10) {
		cout << "unsupported value\n";
		return -1;
	}
	if (base == 1 || exp == 0) {
		return 1;
	}

	return powerTable[base - 2][exp - 1];
}

