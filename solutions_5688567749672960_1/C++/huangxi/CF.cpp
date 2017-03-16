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
#define  N   12345679
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
LL cao(LL x) {
	static LL bit[20];
	LL r = x;
	int cnt = 0;
	while (r) {
		bit[cnt++] = r % 10;
		r /= 10;
	}
	REP(i, (cnt + 1) / 2) {
		bit[i] = 0;
	}
	bit[0] = 1;
	LL ret = 0;
	REP(i, cnt) {
		ret = ret * 10 + bit[cnt-1-i];
	}
	return ret;
}
LL fuck(LL n) {
	if (n <= 9)
		return n;
	if (n % 10 == 0)
		return fuck(n - 1) + 1;
	LL an = cao(n);
	LL need = n - an;
	LL bn = rev(an);
	if (an == bn)
		return need + 1 + fuck(an - 1);

	return need + 1 + fuck(bn);
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
	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);

//	dp[1] = 1;
//	FOR(i, N-1) {
//		update(i + 1, dp[i] + 1);
//		update(rev(i), dp[i] + 1);
//		if (i % 10 != 1 && dp[i] != dp[i-1] + 1) {
//			cout << i << endl;
//		}
//		if (dp[i] != fuck(i)) {
//			cout << i << endl;
//			break;
//		}
//	}
	int T;
	cin >> T;

	FOR(_T, T) {

		int n;
		cin >> n;

		cout << "Case #" << _T << ": " << fuck(n) << endl;



	}

	return 0;

}

int main() {
	return Main();
}
