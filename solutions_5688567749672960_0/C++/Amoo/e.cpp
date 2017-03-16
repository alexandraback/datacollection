//ITNOG
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i, s, e) for(int i = s; i < e; i ++)

const int maxN = 1000*1000 + 5;
const int mod = 1000*1000*1000 + 7;
int dp[maxN];
int ch(int x)
{
    int res = 0;
    while(x)
    {
	  res *= 10; res += x % 10;
	  x /= 10;
    }
    return res;
}

main()
{
    ios::sync_with_stdio(0); cin.tie();

    memset(dp, 63, sizeof dp);
    dp[1] = 1;
    rep(i,1,maxN)
    {
	  
	  dp[i + 1] = min(dp[i + 1], dp[i] + 1);
	  if(ch(i) < maxN) dp[ch(i)] = min(dp[ch(i)], dp[i] + 1);
    }


    int T; cin >> T;
    rep(i,1,T+1)
    {
	  int x; cin >> x;
	  cout << "Case #" << i << ": " << dp[x] << endl; 
    }
    
    return 0;
}
