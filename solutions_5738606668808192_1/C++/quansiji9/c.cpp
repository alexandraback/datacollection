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

		cout << "Case #" << tcount << ": " << endl;

		//n = 16; jj = 50;
		//cout << "1000000000000001 3 4 5 6 7 8 9 10 11\n";

		//for (int i = 0; i < 7; ++i)
		//	for (int j = 0; j < 7; ++j) {
		//		cout << "1";
		//		for (int t = 0; t < 14; ++t)
		//			if (t == 2 * i || t == 2 * j + 1)
		//				cout << "1";
		//			else
		//				cout << "0";
		//		cout << "1 3 4 5 6 7 8 9 10 11\n";
		//	}


		//n = 32; jj = 500;
		cout << "10000000000000000000000000000001 3 4 5 6 7 8 9 10 11\n";
		int count = 1;
		for (int i1 = 0; i1 < 15; ++i1)
			for (int j1 = 0; j1 < 15; ++j1) 
				for (int i2 = i1 + 1; i2 < 15; ++i2)
					for (int j2 = j1 + 1; j2 < 15; ++j2)
						{
							cout << "1";
							for (int t = 0; t < 30; ++t)
								if (t == 2 * i1 || t == 2 * i2 || t == 2 * j1 + 1 || t == 2 * j2 + 1)
									cout << "1";
								else
									cout << "0";
							cout << "1 3 4 5 6 7 8 9 10 11\n";

							++ count;
							if (count >= 500)
								return 0;
						}
	}

	return 0;
}