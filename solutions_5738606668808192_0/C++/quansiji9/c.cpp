#include <iostream>
#include <string>
#include "stdio.h"

using namespace std;

int main() {
	int t;
	cin >> t;

	int n ,jj;
	for (int tcount = 1; tcount <= t; ++tcount) {
		cin >> n >> jj;

		n = 16;
		jj = 50;

		cout << "Case #" << tcount << ": " << endl;

		cout << "1000000000000001 3 4 5 6 7 8 9 10 11\n";

		for (int i = 0; i < 7; ++i)
			for (int j = 0; j < 7; ++j) {
				cout << "1";
				for (int t = 0; t < 14; ++t)
					if (t == 2 * i || t == 2 * j + 1)
						cout << "1";
					else
						cout << "0";
				cout << "1 3 4 5 6 7 8 9 10 11\n";
			}
	}

	return 0;
}