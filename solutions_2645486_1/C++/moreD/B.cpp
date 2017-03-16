#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = 10010;
int T, E, R, N, ep[16];
LL v[maxn], ans;
pair<LL, int> s[maxn][16];

void init() {
	int m = log(N) / log(2);
	for (int e = ep[0] = 1; e <= m; e++) {
		ep[e] = ep[e - 1] * 2;
		for (int i = 1; i <= N - ep[e] + 1; i++)
			s[i][e] = min(s[i][e - 1], s[i + ep[e - 1]][e - 1]);
	}
}

pair<LL, int> query(int l, int r) {
	int e = log(r - l + 1) / log(2);
	return min(s[l][e], s[r - ep[e] + 1][e]);
}

pair<int, LL> solve2(int l, int r, int En) {
	if ((r - l + 1) * (LL)R + En <= E) return make_pair((r - l + 1) * R + En, 0);

	LL re = (r - l + 1) * (LL)R + En - E, ret = 0;
	while (re > 0 && l <= r) {
		pair<LL, int> p = query(l, r);
		LL tmp = (p.second - l) * (LL)R + En;
		if (tmp <= E) {
			ret += min(re, tmp) * (-p.first);
			l = p.second + 1;
			En = R;
			re -= min(re, tmp);
		} else {
			pair<int, LL> x = solve2(l, p.second - 1, En);
			re -= tmp - E;
			ret += x.second + min(re, (LL)E) * (-p.first);
			l = p.second + 1;
			En = R;
			re -= min(re, (LL)E);
		}
	}
	
	return make_pair(E, ret);
}

void solve(int l, int r, int En) {
	if (l > r) return;
	pair<LL, int> p = query(l, r);

	pair<int, LL> ret = solve2(l, p.second - 1, En);
	ans += ret.second + ret.first * (-p.first);

	solve(p.second + 1, r, R);
}

int main() {
	scanf("%d", &T);
	for (int Test = 1; Test <= T; Test++) {
		scanf("%d%d%d", &E, &R, &N);
		for (int i = 1; i <= N; i++)
			scanf("%I64d", v + i), 
			s[i][0] = make_pair(-v[i], i);
		init();
		
		ans = 0;
		solve(1, N, E);
		printf("Case #%d: %I64d\n", Test, ans);
	}
}
