#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <list>
#include <iterator>
#include <functional>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cassert>
#include <climits>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pnt;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int t;

string solve() {
	int n, m;
	cin >> n >> m;
	int a[100][100];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			bool vOk = true;
			for (int l = 0; l < n; ++l)
				if (a[l][j] > a[i][j])
					vOk = false;
			bool hOk = true;
			for (int l = 0; l < m; ++l)
				if (a[i][l] > a[i][j])
					hOk = false;
			if (!vOk && !hOk)
				return "NO";
		}
	return "YES";
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> t;
	for (int k = 0; k < t; ++k)
		cout << "Case #" << (k + 1) << ": " << solve() << "\n";
	return 0;
}