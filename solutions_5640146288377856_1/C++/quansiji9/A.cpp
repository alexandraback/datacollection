#include <iostream>
#include "stdio.h"

using namespace std;

int main() {
	int t;
	cin >> t;

	int r,c,w;

	for (int tcount = 1; tcount <= t; ++tcount) {
		cin >> r >> c >> w;

		int count = 0;

		if (w == 1)
			count += (r-1) * c;
		else {
			int num2 = c / w;
			count += (r-1) * num2;
		}

		

		if (w == 1)
			count += c;
		else {
			int num = c / w;
			count += num - 1;
			if (c % w == 0)
				count += w;
			else
				count += w + 1;
		}

		cout << "Case #" << tcount << ": " << count << endl;
	}

	return 0;
}