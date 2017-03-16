#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <sstream>
#include <ctime>
#include <functional>
#define pi 3.14159265358979323846264338327950288
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define LL long long
#define LD long double
#define INF 1000000000
#define INFll 1000000000000000000ll
#define Vi vector<int>
#define VI Vi::iterator
#define Mi map<int, int>
#define MI Mi::iterator
#define Si set<int>
#define SI Si::iterator
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define SZ(x) ((int)x.size())
#define mid (l + r) / 2
#define Left k * 2, l, mid
#define Right k * 2 + 1, mid + 1, r
#define N 1111
using namespace std;
typedef pair<string, string> strp;
int cas, cases;
strp a[N];
int n;
int ans;
int ones(int x) {
	int ans = 0;
	while (x) {
		ans += x & 1;
		x >>= 1;
	}
	return ans;
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	scanf("%d", &cas);
	for (cases = 1; cases <= cas; cases ++) {
		scanf("%d", &n);
		ans = 0;
		for (int i = 0; i < n; i++)
            cin >> a[i].X >> a[i].Y;
		for (int mask = 0; mask < (1 << n); mask++) {
			map<string, int> tX, tY;
			for (int i = 0; i < n; i++) {
				bool flag = (mask >> i) & 1;
				if (!flag) continue;
				tX[a[i].X] = 1;
				tY[a[i].Y] = 1;
			}
			bool valid = true;
			for (int i = 0; i < n; i++) {
				if (tX.find(a[i].X) == tX.end()) valid = false;
				if (tY.find(a[i].Y) == tY.end()) valid = false;
			}
			if (valid) ans = max(ans, n - ones(mask));
		}
		printf("Case #%d: %d\n", cases, ans);
	}
}
