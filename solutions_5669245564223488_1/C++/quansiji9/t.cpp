#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <time.h>
using namespace std;

long long jiecheng (int n) {
	if (n == 0)
		return 1;
	long long tp = 1;
	for (int i = n; i >= 1; --i) {
		tp *= i;
		tp %= 1000000007;
	}

	return tp;
}

int main() {
	int T;
	int N;
	char cars[110][110];

	cin >> T;

	for (int j = 1; j <= T; j++) {
		cin >> N;

		for (int i = 0; i < N; ++i)
			cin >> cars[i];

		int ctimes = 0;
		long long posi = 1;
		bool impossible = false;

		for (char c = 'a'; c <= 'z'; ++c) {
			int inc = 0;
			int allc = 0;
			int leftc = 0;
			int rightc = 0;
			for (int i = 0; i < N; ++i) {
				int tp = 0;
				while (cars[i][tp] != '\0' && cars[i][tp] != c) {
					++tp;
				}
				if (cars[i][tp] == '\0') {
					// no c here
					continue;
				}

				//have c here & tp is first c
				int stpt = tp;

				int length = strlen(cars[i]);
				tp = length;
				while (tp >= 0 && cars[i][tp] != c) {
					--tp;
				}
				// tp is last c
				int edpt = tp;

				for (int k = stpt; k <= edpt; ++k) {
					if (cars[i][k] != c) {
						inc += 2;
						break;
					}
				}
				if (inc >= 2)
					break;

				if (stpt == 0 && edpt == (length-1))
					++allc;
				else if (stpt == 0 && edpt < (length-1))
					++leftc;
				else if (stpt > 0 && edpt == (length-1))
					++rightc;
				else
					++inc;
			}

			if (inc >= 2) {
				impossible = true;
				break;
			}
			else if (inc == 1) {
				if (allc + leftc + rightc > 0) {
					impossible = true;
					break;
				}
			}
			else { //no inc
				if (allc + leftc + rightc == 0)
					continue;

				if (leftc > 1 || rightc > 1) {
					impossible = true;
					break;
				}
				posi *= jiecheng(allc);
				posi %= 1000000007;

				ctimes += (allc + leftc + rightc - 1);

			}
		}

		if (impossible || ctimes >= N)
			cout << "Case #" << j << ": 0"  << endl;
		else {
			posi *= jiecheng(N - ctimes);
			posi %= 1000000007;
			cout << "Case #" << j << ": " << posi << endl;
		}
	}

	return 0;
}
