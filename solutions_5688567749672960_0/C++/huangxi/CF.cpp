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
#define  N   1234567
#define  eps 1e-8
#define  pi  acos(-1.0)
#define  inf 0XFFFFFFFFFFFFFFll
#define  mod 100007ll
#define  LL  long long
#define  ULL unsigned long long


LL rev(LL x) {
	LL ret = 0;
	if (x % 10 == 0)
		return ret;
	while (x) {
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	return ret;
}

int dp[N];
void update(int x, int y) {
	if (x >= N || x <= 1)
		return;
	if (dp[x] == 0)
		dp[x] = y;
	dp[x] = min(dp[x], y);
}

int Main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);


	dp[1] = 1;
	FOR(i, N-1) {
		update(i + 1, dp[i] + 1);
		update(rev(i), dp[i] + 1);
	}
	int T;
	cin >> T;

	FOR(_T, T) {

		int n;
		cin >> n;

		cout << "Case #" << _T << ": " << dp[n] << endl;



	}

	return 0;

}

int main() {
	return Main();
}
