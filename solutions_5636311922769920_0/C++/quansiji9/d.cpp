#include <iostream>
#include <string>
#include "stdio.h"

using namespace std;

int main() {
	int t;
	cin >> t;

	int k, c, s;
	for (int tcount = 1; tcount <= t; ++tcount) {
		cin >> k >> c >> s;

		cout << "Case #" << tcount << ": ";
		for (int i = 1; i <= s; ++i)
			cout << i << " ";
		cout << endl;
		continue;

		if (c * s < k) {
			cout << "Case #" << tcount << ": IMPOSSIBLE\n";
			continue;
		}

		cout << "Case #" << tcount << ": ";

		int start = 1;
		while (start <= k) {
			// Position at {start, ..., start + c - 1}
			// Namely (start - 1) * k ^ (c - 1) + ... + (start + c - 2) * k ^ 0 + 1
			long long temp = 0;
			if (start + c > k)
				start = k - c + 1;
			for (int i = 0; i < c; ++i) {
				long long thisOffset = (start + i - 1) * (long long)pow((long long)k, (c-1-i));
				if (start + i - 1 > 0)
					temp += thisOffset;
			}

			++ temp;

			cout << temp << " ";

			start += c;
		}
		cout << endl;
	}

	return 0;
}