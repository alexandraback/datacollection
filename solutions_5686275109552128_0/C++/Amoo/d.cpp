//ITNOG
#include<bits/stdc++.h>

using namespace std;

#define rep(i, s, e) for(int i = s; i < e; i ++)

const int maxN = 1000 + 5;
const int mod = 1000*1000*1000 + 7;

int a[maxN];
int dp[maxN][maxN];

void solve()
{
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];
    
    int cnt = mod;
    rep(i, 1, 1001)
    {
	  int te = i;
	  rep(j, 0, n)
	  {
		te += dp[a[j]][i];
	  }
	  cnt = min(cnt, te);
    }

    cout << cnt << endl;
}

main()
{
    ios::sync_with_stdio(0); cin.tie();

    rep(i, 1, maxN) rep(j, 1, maxN)
    {
	  if(i <= j) continue;
	  dp[i][j] = mod;
	  rep(k, 1, i + 1)
	  {
		int te = dp[k][j] + dp[i - k][j] + 1;
		dp[i][j] = min(dp[i][j], te);
	  }
    }

    
    int T; cin >> T;
    rep(i, 0, T)
    {
	  cout << "Case #" << i + 1 << ": ";
	  solve();
    }
}
