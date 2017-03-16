#include <iostream>
#include <iomanip>
#include "stdio.h"

using namespace std;

int main() {
	int t;
	cin >> t;

	int c,d,v;
	int mon[30];
	bool isok[100];


	for (int tcount = 1; tcount <= t; ++tcount) {
		cin >> c >> d >> v;

		// c = 1

		for (int i = 0; i < 100; ++i)
			isok[i] = false;
		isok[0] = true;
		
		for(int i = 0; i < d; ++i) {
			cin >> mon[i];
			for (int j = 30; j >= 0; --j) {
				if (isok[j]) {
					if (j + mon[i] <= 30)
						isok[j + mon[i]] = true;
				}
			}
		}

		int count = 0;
		int monpt = d;

		int pt = 0;

		while (true) {
			for ( ; pt <= v; ++pt)
				if (!isok[pt])
					break;

			if (pt > v)
				break;

			mon[monpt++] = pt;
			++count;

			for (int j = 30; j >= 0; --j) {
				if (isok[j]) {
					if (j + pt <= 30)
						isok[j + pt] = true;
				}
			}
		}

		cout << "Case #" << tcount << ": " << count << endl;
	}

	return 0;
}