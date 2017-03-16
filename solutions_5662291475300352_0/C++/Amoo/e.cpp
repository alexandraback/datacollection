//ITNOG
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i, s, e) for(int i = s; i < e; i ++)

const int maxN = 1000*1000 + 5;
const int mod = 1000*1000*1000 + 7;


int d[maxN], h[maxN], m[maxN];
int  solve()
{
    int n; cin >> n;
    rep(i,0,n) cin >> d[i] >> h[i] >> m[i];
    if(n == 1 && h[0] == 1)
    {
	  return 0;
    }
 
    if(n == 1) m[1] = m[0] + 1, d[1] = d[0];
    
    if(m[0] > m[1]) swap(d[0], d[1]), swap(m[0], m[1]);

    int dis = (360 - d[1]) + d[0];
    int dt = m[1] - m[0];
    if(dt * 360 < m[0] * dis) return 0;
    return 1;
    
    
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
