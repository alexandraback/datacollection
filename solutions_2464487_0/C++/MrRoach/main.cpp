// Problem 1, Round 1A, GCJ 2013
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int T;
double t, r;

int main() {
	cin >> T;
	for (int caseNum = 0; caseNum < T; ++caseNum) {
		cin >> r >> t;
		long long n = (long long)(((1.0 - 2.0 * r) + sqrt((2.0 * r) * (2.0 * r) + 8 * t)) / 4.0) + 1;
		while (2.0 * n * n + (2.0 * r - 1.0) * n - t > 1e-9) {
			-- n;
		}
		cout << "Case #" << caseNum + 1 << ": " << n << endl;
	}
	return 0;
}