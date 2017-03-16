#include <iostream>
#include <iomanip>
#include "stdio.h"

using namespace std;

int main() {
	int t;
	cin >> t;

	int k,l,s;
	char key[10];
	char target[10];
	char now[10];
	int ct[10];


	for (int tcount = 1; tcount <= t; ++tcount) {
		cin >> k >> l >> s;

		cin >> key;
		cin >> target;

		for (int i = 0; i < s; ++i)
			ct[i] = 0;

		int inst = 0, max = 0, banaCount = 0;
		while (ct[s-1] < k) {
			for (int i = 0; i < s; ++i)
				now[i] = key[ct[i]];
			now[s] = 0;

			int banaThis = 0;

			for (int i = 0; i <= s-l; ++i) {
				int j = 0;
				for (; j < l; ++j) {
					if (now[i+j] != target[j])
						break;
				}

				if (j >= l)
					banaThis ++;
			}

			++ inst;
			banaCount += banaThis;
			if (banaThis > max)
				max = banaThis;

			ct[0] ++;

			for (int i = 0; i < s-1; ++i) {
				if (ct[i] >= k) {
					ct[i+1] ++;
					ct[i] = 0;
				}
				else
					break;
			}
		}

		double avg = (double) banaCount / (double) inst;

		cout << "Case #" << tcount << ": ";
		cout << setprecision(15) << max - avg << endl;
	}

	return 0;
}