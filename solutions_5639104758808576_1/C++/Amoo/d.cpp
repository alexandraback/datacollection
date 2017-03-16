//ITNOG
#include<bits/stdc++.h>

using namespace std;

#define rep(i, s, e) for(int i = s; i < e; i ++)

const int maxN = 100*1000 + 5;
const int mod = 1000*1000*1000 + 7;

void solve()
{
    int n; cin >> n; n ++;
    string s; cin >> s;

    int lo = -1, hi = mod;
    while(hi - lo > 1)
    {
	  int mid = (hi + lo) >> 1;
	  
	  int cnt = mid, fl = 1;
	  rep(i, 0, s.size())
	  {
		if(cnt < i) { fl = 0; break; }
		cnt += s[i] - '0';
	  }
	  
	  if(fl) hi = mid;
	  else lo = mid;
    }
    cout << hi << endl;
}

main()
{
    ios::sync_with_stdio(0); cin.tie();
    int T; cin >> T;
    rep(i, 0, T)
    {
	  cout << "Case #" << i + 1 << ": ";
	  solve();
    }
}
