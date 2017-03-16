#include <iostream>
#include "stdio.h"

using namespace std;

int main() {
	int t;
	cin >> t;

	char n[20];
	long long kcount[20];

	kcount[0] = 0;
	kcount[1] = 10;
	for (int i = 2; i < 20; ++i) {
		//len = i, 99..,9
		if (i%2 == 0)
			kcount[i] = kcount[i-1] + (pow(10, i/2) - 1) * 2 + 1;
		else
			kcount[i] = kcount[i-1] + (pow(10, i/2) - 1) + (pow(10, i/2 + 1) - 1) + 1;
	}

	for (int tcount = 1; tcount <= t; ++tcount) {
		cin >> n;

		int len = strlen(n);

		if (len == 1) {

			cout << "Case #" << tcount << ": " << n[0] - '0' << endl;
			continue;
		}

		bool ifPreMinusOne = false;

		if (n[len-1] == '0') {
			bool ifeee = true;
			int i;
			for (i = len - 1; i > 0; --i)
				if (n[i] != '0') {
					ifeee = false;
					break;
				}
			if (i == 0 && n[0] == '1')
				ifeee = true;
			else
				ifeee = false;

			if (!ifeee) {
				int tt = len - 1;
				while(n[tt] == '0') {
					n[tt] = '9';
					tt--;
				}
				n[tt] -= 1;

				ifPreMinusOne = true;
			}
		}

		long long count = kcount[len-1];

		//First, 1e(len-1) ~ n

		int sp;
		if (len % 2 == 0)
			sp = len / 2;
		else
			sp = len / 2;

		int clow = n[sp] - '0';
		for (int i = sp + 1; i < len; ++i) {
			clow *= 10;
			clow += n[i] - '0';
		}

		int chigh = n[sp-1] - '0';
		for (int i = sp - 2; i >= 0; --i) {
			chigh *= 10;
			chigh += n[i] - '0';
		}

		if (chigh == 1)
			count += clow;
		else {
			count += chigh + 1 + (clow - 1);
		}
		
		if (ifPreMinusOne)
			count++;

		cout << "Case #" << tcount << ": " << count << endl;
		//cout << "---------- " << count - kcount[len-1] << endl;
	}

	return 0;
}