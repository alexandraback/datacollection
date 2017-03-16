//ITNOG
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i, s, e) for(int i = s; i < e; i ++)

const int maxN = 1000 + 5;
const int mod = 1000*1000*1000 + 7;

void bad() { cout << "RICHARD" << endl; }
void good() { cout << "GABRIEL" << endl; }


void solve()
{
    int x, r, c; cin >> x >> r >> c;

    if(x == 1) { good(); return; }
    if(x == 2) 
    {
	  if(r % 2 && c % 2) bad();
	  else good();
	  return;
    }
    if(x == 3)
    {
	  if(r % 3 && c % 3) { bad(); return; }
	  if(min(r, c) == 1) bad();
	  else good();
	  return;
    }
    
    if(x == 4)
    {
	  if(max(r, c) < 4) bad();
	  else
	  {
		if(min(r, c) > 2) good();
		else bad();
	  }
    }
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
