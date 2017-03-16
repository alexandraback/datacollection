//ITNOG
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i, s, e) for(int i = s; i < e; i ++)

const int maxN = 1000*1000 + 5;
const int mod = 1000*1000*1000 + 7;

int ch(int x)
{
    int res = 0;
    while(x)
    {
	  res *= 10, res += x % 10;
	  x /= 10;
    }
    return res;
}

int  solve()
{
    int n; cin >> n;
    int cur = n, cnt = 0;
    while(cur)
    {
	  if(cur % 10 == 0) { cur --; cnt ++; continue; }
	  cur = min(cur - 1, ch(cur));
	  cnt ++;
    }
    return cnt;
}

main()
{
    ios::sync_with_stdio(0); cin.tie();

    int T; cin >> T;
    rep(i,1,T+1)
    {
	  cout << "Case #" << i << ": " << solve() << endl;
    }
    
    return 0;
}
