#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define intl long long
using namespace std;

intl ans[101000];
int top;
intl k,c,s;

intl solve(int n,int u) {
	int res = c;
	intl ans = 1;
	for (int i = u; i < u + n; i++) {
		ans = (ans - 1LL) * k + (intl) i;
		res--;
	}
	for (; res; res--) ans = (ans - 1LL) * k + (intl) u;
	return ans;
}

int main() {
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	int T,t;
	for (scanf("%d",&T), t = 1; t <= T; t++) {
		printf("Case #%d: ",t);
		cin >> k >> c >> s;
		if (c * s < k) { printf("IMPOSSIBLE\n"); continue; }
		top = 0;
		for (int i = 1; i <= k; i += c) {
			int n = min(k - i + 1, c);
			ans[++top] = solve(n,i);
		}
		for (int i = 1; i < top; i++) cout << ans[i] << " ";
		cout << ans[top] << endl;
	}
	return 0;
}
