#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define maxn 10001
typedef long long LL;
using namespace std;

int v[maxn];

struct STK{
	int v, cnt;
}stk[maxn];

int solve() {
	int E, R, n, top = 0, e;
	long long ans = 0;
	cin >> E >> R >> n;
	e = E;
	for(int i = 1; i <= n; ++i) {
		cin >> v[i];
		while(top && stk[top - 1].v < v[i] && stk[top - 1].cnt + e <= E) {
			top -= 1;
			e += stk[top].cnt;
			ans -= LL(stk[top].cnt) * stk[top].v;
		}
		if(top && stk[top - 1].v < v[i]) {
			int dat = min(stk[top - 1].cnt, E - e);
			ans -= stk[top - 1].v * LL(dat);
			e += dat;
			stk[top - 1].cnt -= dat;
			if (stk[top - 1].cnt == 0) {
				-- top;
			}
		}
		stk[top].v = v[i];
		stk[top++].cnt = e;
		ans += v[i] * LL(e);
		e = R;
	}
	cout << ans << endl;
	return ans;
}

int main() {
	int T;
	freopen("B-large.in", "r", stdin);
	freopen("b.out", "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}
}
