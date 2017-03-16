#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int inf = 1e9;
const double eps = 1e-7;
const int maxn = 1001000;
const int mod = 1000000007;

int rev(int x) {
	int ret = 0;
	while (x) {
		ret = ret * 10 + (x % 10);
		x /= 10;
	}
	return ret;
}

int main() 
{
#ifdef DEBUG
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	vi f(maxn, inf);
	f[0] = 0;
	for (int i = 0; i < maxn - 1; ++i) {
		f[i + 1] = min(f[i + 1], f[i] + 1);
		int r = rev(i);
		if (r < maxn) {
			f[r] = min(f[r], f[i] + 1);
		}
	}
	
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int x;
		scanf("%d", &x);
		printf("Case #%d: %d\n", t + 1, f[x]);
	}
	return 0;
}
