//ITNOG
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i, s, e) for(int i = s; i < e; i ++)

const int maxN = 1000 + 5;
const int mod = 1000*1000*1000 + 7;

int dp[4][4] = { {0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0}};
int cn[4][4] = { {0, 0, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 0, 1, 1}};

map<char, int> mp;


bool check1(string s)
{
    int ps = 0, cnt = 0;
    rep(i, 0, s.size())
    {
	  int tmp = dp[ps][mp[s[i]]];
	  int te = cn[ps][mp[s[i]]];
	  
	  ps = tmp;
	  cnt += te; cnt %= 2;
//	  cout << ps << ' ' << cnt << endl;
	  if(ps == 1 && cnt == 0) return true;
    }
    return false;
}

bool check2(string s)
{
    reverse(s.begin(), s.end());
    int ps = 0, cnt = 0;
    rep(i, 0, s.size())
    {
	  int tmp = dp[mp[s[i]]][ps];
	  int te = cn[mp[s[i]]][ps];
	  
	  ps = tmp;
	  cnt += te; cnt %= 2;
	  if(ps == 3 && cnt == 0) return true;
    }
    return false;
}


bool check(string s)
{
    int plc = -1;

    int ps = 0, cnt = 0;
    rep(i, 0, s.size())
    {
	  int tmp = dp[ps][mp[s[i]]];
	  int te = cn[ps][mp[s[i]]];
	  
	  ps = tmp;
	  cnt += te; cnt %= 2;
	  if(ps == 1 && cnt == 0) { plc = i; break; }
    }

    if(plc == -1) return false;

    ps = 0; cnt = 0;
    
    reverse(s.begin(), s.end());
    rep(i, 0, s.size())
    {
	  int tmp = dp[mp[s[i]]][ps];
	  int te = cn[mp[s[i]]][ps];
	  
	  ps = tmp;
	  cnt += te; cnt %= 2;
	  if(ps == 3 && cnt == 0) 
	  {
		if(plc < s.size() - i - 1) return true;
		return false;
	  }
    }

    return false;
}

void solve()
{
    int n, x; cin >> n >> x;
    string s; cin >> s;
    
    int ps = 0, cnt = 0;
    rep(i, 0, s.size())
    {
	  int tmp = dp[ps][mp[s[i]]];
	  int te = cn[ps][mp[s[i]]];
	  
	  ps = tmp;
	  cnt += te; cnt %= 2;
    }
//    cout << ps << ' ' << cnt << endl;

    
    if(ps == 0) 
    {
	  if(cnt == 0) { cout << "NO" << endl; return; }
	  else if(x % 2 == 0) { cout << "NO" << endl; return; }
	  
	  if(x > 15)
	  {
		string t; rep(i, 0, 7) t += s;
		
		if(check1(t) && check2(t)) cout << "YES" << endl;
		else cout << "NO" << endl;
	  }
	  else
	  {
		string t;
		rep(i, 0, x) t += s;
		if(check(t)) cout << "YES" << endl;
		else cout << "NO" << endl;
	  }
	  return;
    }
    
    if(x % 2) { cout << "NO" << endl; return; }

    x /= 2;
    if(x % 2) 
    {
	  x *= 2;
	  if(x > 15)
	  {
		string t; rep(i, 0, 7) t += s; 		
		if(check1(t) && check2(t)) cout << "YES" << endl;
		else cout << "NO" << endl;
	  }
	  else
	  {
		string t;
		rep(i, 0, x) t += s;
		
		if(check(t)) cout << "YES" << endl;
		else cout << "NO" << endl;
	  }
    }
    else cout << "NO" << endl;
    
}

main()
{
    ios::sync_with_stdio(0); cin.tie();
    mp['i'] = 1; mp['j'] = 2; mp['k'] = 3;
    int T; cin >> T;
    rep(i, 0, T)
    {
	  cout << "Case #" << i + 1 << ": ";
	  solve();
    }
}
