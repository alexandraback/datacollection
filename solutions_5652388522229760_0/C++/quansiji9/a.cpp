#include <iostream>
#include "stdio.h"

using namespace std;

int main() {
	int t;
	cin >> t;

	int s, tp;
	for (int tcount = 1; tcount <= t; ++tcount) {
		bool mk[10] = {true,true,true,true,true,true,true,true,true,true};
		int mkcount = 0;
		cin >> s;

		tp = 0;

		if (s == 0) {
			cout << "Case #" << tcount << ": INSOMNIA" << endl;
			continue;
		}
		while (mkcount < 10) {
			tp += s;

			int temp = tp;

			do {
				if (mk[temp % 10]) {
					mk[temp % 10] = false;
					mkcount ++;
				}
				temp /= 10;
			}
			while (temp > 0);
		}

		cout << "Case #" << tcount << ": " << tp << endl;
	}

	return 0;
}