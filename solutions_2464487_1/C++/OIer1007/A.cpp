#include <iostream>

#include <fstream>

#include <cstring>

#include <string>

#include <iomanip>

#include <cmath>

#include <climits>

#include <algorithm>

#include <cstdio>

#include <cstdlib>

using namespace std;



long long r, t;

bool calcu(int tm) {

	double tmp = (double)tm * tm * 2 + 2 * (double)tm * (double)r - (double)tm;

	if (tmp > (long long)8000000000000000000) return true;

	long long tmp2 = (long long)tm * tm * 2 + 2 * (long long)tm * (long long)r - (long long)tm;

	if (tmp2 > t) return true;

	else return false;

}



int main() {

	freopen("A.in", "r", stdin);

	freopen("A.out","w", stdout);

	int number;

	cin >> number;

	for (int k = 1; k <= number; k++) {

	cin >> r >> t;

	int st, ed;

	st = 1;

	ed = 707106781;

	int res;

	while (st < ed) {

		if (ed - st == 1) {

			if (calcu(ed)) res = st;

			else res = ed;

			break;

		}

		int mid = (st + ed) >> 1;

		if (calcu(mid)) ed = mid;

		else st = mid;

	}

	cout << "Case #" << k << ": " << res << "\n";

	} 	



	return 0;

}

