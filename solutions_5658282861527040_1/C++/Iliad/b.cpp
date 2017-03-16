#include <bits/stdc++.h>
using namespace std;


#define Size(s) ((int)s.size())
#define rep(i, n) for(int i=0; i<n; ++i)
#define Foreach(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define F first
#define S second
#define X real()
#define Y imag()

template<class P, class Q> inline void mmin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void mmax(P &a, Q b) { if (a < b) a = b; }

typedef long long LL;
typedef pair<int, int> pii;

const int MAXn = 100*1000;
int a, b, k;
LL dp[40][8];
int num[3];

int solve()
{
	int ret = 0;
	rep(i, a) rep(j, b)
		ret += (i&j) < k;
	return ret;
}

int solve2()
{
	num[0] = a;
	num[1] = b;
	num[2] = k;

	dp[32][7] = 1;
	rep(i, 32) rep(j, 8)
		dp[i][j] = 0;

	for(int i=31; i>=0; --i) rep(x, 8) rep(y, 8) {
		if(((y & 1) & (y>>1 & 1)) != (y>>2 & 1))
			continue;
		int mask = 0;
		bool ok = true;
		rep(z, 3) {
			if((x>>z & 1) && (y>>z & 1) && !(num[z]>>i & 1)) ok = false;
			if((x>>z & 1) && ((y>>z & 1) == (num[z]>>i & 1))) mask |= 1<<z;
		}
		if(ok)
			dp[i][mask] += dp[i+1][x];
	}

	return dp[0][0];
}

int main()
{
	ios_base::sync_with_stdio(false);

	int nt;
	cin >> nt;
	for(int i=1; i<=nt; ++i) {
		cin >> a >> b >> k;
		cout << "Case #" << i << ": " << solve2() << endl;
	}
	return 0;
}
