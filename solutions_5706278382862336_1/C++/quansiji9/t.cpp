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

int main() {
	int T;
	long long P, Q;
	char tc;

	cin >> T;

	for (int j = 1; j <= T; j++) {
		cin >> P >> tc >> Q;

		long long tempq = Q;
		while (tempq % 2 == 0)
			tempq /= 2;

		if (P % tempq == 0) {
			P /= tempq;
			Q /= tempq;
		}
		else {
			cout << "Case #" << j << ": impossible\n";
			continue;
		}

		/*
		while (P % 2 == 0) {
			P /= 2;
			Q /= 2;
		}*/

		int count = 0;
		long long pp = P;
		while (pp < Q) {
			pp *= 2;
			++count;
		}

		cout << "Case #" << j << ": " << count << endl;
	}

	return 0;
}
