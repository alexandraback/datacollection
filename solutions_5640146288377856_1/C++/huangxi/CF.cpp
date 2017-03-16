#include <bits/stdc++.h>
#define  RD(x)      scanf("%d", &x)
#define  REP(i, n)  for (int i=0; i<int(n); ++i)
#define  FOR(i, n)  for (int i=1; i<=int(n); ++i)
#define  pii        pair<int, int>
#define  piL        pair<int, long long>
#define  mp         make_pair
#define  pb         push_back
#define  whatis(x)  cout << #x << ": " << x << endl;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

using namespace std;
#define  N   123
#define  eps 1e-8
#define  pi  acos(-1.0)
#define  inf 0XFFFFFll
#define  mod 1000000007ll
#define  LL  long long
#define  ULL unsigned long long

int dp[N][N];
int nothave(int c, int w) {
	return c / w;
}

int have(int c, int w) {
	if (dp[c][w] != -1)
		return dp[c][w];
	int &ret = dp[c][w];
	if (c < w)
		return ret = inf;
	if (c == w)
		return ret = w;

	ret = inf;
	for (int i = 1; i <= c; i++) {
		int t1 = (i == 1 || i == c) ? w : w + 1;
		int t2 = 1 + have(i - 1, w) + nothave(c - i, w);
		int t3 = 1 + nothave(i - 1, w) + have(c - i, w);
		if (t2 < inf)
			t1 = max(t1, t2);
		if (t3 < inf)
			t1 = max(t1, t3);
		ret = min(ret, t1);
	}

	return ret;
}


int Main() {
	freopen("A-large.in", "r", stdin);
//	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);


	memset(dp, -1, sizeof dp);

	int T;
	cin >> T;

	FOR(_T, T) {
		int r, c, w;
		cin >> r >> c >> w;
		int ans = have(c, w) + nothave(c, w) * (r - 1);
		cout << "Case #" << _T << ": " << ans << endl;
	}



	return 0;
}

int main() {
	return Main();
}
