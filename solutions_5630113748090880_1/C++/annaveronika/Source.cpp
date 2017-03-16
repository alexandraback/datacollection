#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <time.h>

#define M_PI           3.14159265358979323846

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "1"

#pragma comment(linker, "/STACK:56777216")

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;

int main() {
	freopen(PROBLEM_ID".in", "r", stdin);
	freopen(PROBLEM_ID".out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		vi x;
		for (int i = 0; i < 2 * n - 1; ++i) {
			for (int j = 0; j < n; ++j) {
				int val;
				cin >> val;
				x.push_back(val);
			}
		}

		sort(x.begin(), x.end());

		vi result;

		int count = 1;
		int val = x[0];
		for (int i = 1; i < x.size(); ++i) {
			if (x[i] == val) {
				count++;
			}
			else {
				if (count % 2 != 0) {
					result.push_back(val);
				}
				count = 1;
				val = x[i];
			}
		}
		if (count % 2 != 0) {
			result.push_back(val);
		}

		cout << "Case #" << i + 1 << ": ";
		for (auto v : result) {
			cout << v << " ";
		}
		cout << endl;
	}

	return 0;
}