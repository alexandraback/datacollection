#include <functional>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

int factorial(int n) {
	return !n ? 1 : factorial(n - 1) * n;
}

int main(int const argc, char const* const* const argv)
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		vector <string> cars;
		long long r = 0;
		int c;
		cin >> c;
		for (int i = 0; i < c; ++i) {
    	string t;
    	cin >> t;
    	cars.push_back(t);
    }
		for (int i = 0; i < factorial(cars.size()); ++i, next_permutation(cars.begin(), cars.end())) {
			bool ok = true;
			string t = "";
			int seen[256] = {0};
			for (int j = 0; j < cars.size(); ++j) {
				t += cars[j];
			}
			seen[t[0]] = 1;
			for (int j = 1; j < t.size(); ++j) {
				if (t[j] != t[j - 1] && seen[t[j]]) {
					ok = false;
					break;
				}
				seen[t[j]] = true;
			}
			r += ok;
		}
		cout << "Case #" << i << ": " << r << endl;
	}
	return 0;
}
