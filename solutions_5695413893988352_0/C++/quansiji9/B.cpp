#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include "stdio.h"

using namespace std;

long long diff[50];
string aa[50];
string bb[50];
int pt;
int len;

void doit (string a, string b, int i, char aval, char bval) {
	a[i] = aval;
	b[i] = bval;

	if (aval > bval) {
		// Case a > b
		// a to min; b to max
		for (int j = i+1; j < len; ++j) {
			if (a[j] == '?')
				a[j] = '0';
			if (b[j] == '?')
				b[j] = '9';
		}
	}

	if (aval < bval) {
		// Case a < b
		// a to max; b to min
		for (int j = i+1; j < len; ++j) {
			if (a[j] == '?')
				a[j] = '9';
			if (b[j] == '?')
				b[j] = '0';
		}
	}

	aa[pt] = a;
	bb[pt] = b;
	++pt;
}

int main() {
	int t;
	cin >> t;

	string a, b;
	for (int tcount = 1; tcount <= t; ++tcount) {
		cin >> a >> b;

		len = a.length();
		
		pt = 0;

		for (int i = 0; i < len; ++i) {
			if (a[i] == '?' && b[i] == '?') {
				// Case a > b
				doit (a, b, i, '1', '0');
				// Case a < b
				doit (a, b, i, '0', '1');
				// Case a = b
				a[i] = b[i] = '0';
				continue;
			}
			if (a[i] == '?' && b[i] != '?') {
				// Case a > b
				if (b[i] < '9')
					doit (a, b, i, b[i] + 1, b[i]);
				// Case a < b
				if (b[i] > '0')
					doit (a, b, i, b[i] - 1, b[i]);
				// Case a = b
				a[i] = b[i];
				continue;
			}
			if (a[i] != '?' && b[i] == '?') {
				// Case a < b
				if (a[i] < '9')
					doit (a, b, i, a[i], a[i] + 1);
				// Case a > b
				if (a[i] > '0')
					doit (a, b, i, a[i], a[i] - 1);
				// Case a = b
				b[i] = a[i];
				continue;
			}

			// Digit vs Digit
			if (a[i] == b[i])
				continue;
			if (a[i] > b[i]) {
				// a to min; b to max
				for (int j = i+1; j < len; ++j) {
					if (a[j] == '?')
						a[j] = '0';
					if (b[j] == '?')
						b[j] = '9';
				}
			}
			if (a[i] < b[i]) {
				// a to max; b to min
				for (int j = i+1; j < len; ++j) {
					if (a[j] == '?')
						a[j] = '9';
					if (b[j] == '?')
						b[j] = '0';
				}
			}
			break;
		}
		aa[pt] = a;
		bb[pt] = b;
		++pt;

		for (int i = 0; i < pt; ++i) {
			long long aval = stoll(aa[i]);
			long long bval = stoll(bb[i]);
			diff[i] = aval - bval;
			if (diff[i] < 0)
				diff[i] = -diff[i];
		}

		long long minval = diff[0];
		long long minaval = stoll(aa[0]);
		long long minbval = stoll(bb[0]);
		int minpt = 0;
		for (int i = 1; i < pt; ++i) {
			if ((diff[i] < minval) || (diff[i] == minval && stoll(aa[i]) < minaval) || 
				(diff[i] == minval && stoll(aa[i]) == minaval && stoll(bb[i]) < minbval)) {
				minpt = i;
				minval = diff[i];
				minaval = stoll(aa[i]);
				minbval = stoll(bb[i]);
			}
		}

		cout << "Case #" << tcount << ": ";
		cout << aa[minpt] << " " << bb[minpt];
		cout << endl;
	}

	return 0;
}