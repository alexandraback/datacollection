#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <ctime>
#include <sstream>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define MP make_pair

const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-9;
const int INF = (1 << 31) - 1;
const long long LLINF = (1LL << 63) - 1;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int xx = 1; xx <= t; ++xx) {
		int n;
		cin >> n;
		vector<int> a(n);
		cout << "Case #"<<xx<<": ";
		for (int i = 0; i< n; ++i) {
			scanf("%d", &a[i]);
		}
		int x = accumulate(all(a), 0);
		for(int i = 0; i < n; ++i) {
			double l = 0.0;
			double u = 1.0;
			for (int it = 0; it < 120; ++it) {
				double m = 0.5 * (l + u);
				double score = a[i] + m * x;
				double rem = 1.0 - m;
				for (int j = 0; j < n; ++j) {
					if (j == i)
						continue;
					if (a[j] > score)
						continue;
					double req = fabs(1.0 * a[j] - score) / x;
					rem -= req;
				}
				if (rem > -1e-9)
					l = m;
				else
					u = m;
			}
			printf("%0.18lf ", 50.0*(l+u));
		}
		cout << "\n";

	}

	return 0;
}