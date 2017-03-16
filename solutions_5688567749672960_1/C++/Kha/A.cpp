#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define rep(i,s,e) for (int i=(s);i<(e);++i)
#define pb push_back
#define mk make_pair
#define fst first
#define snd second
#define all(x) (x).begin(),(x).end()
#define clr(x,y) memset(x,y,sizeof x)
#define contains(x,y) (x).find(y)!=(x).end()
#define endl "\n"

int dx[]={0,0,1,-1,1,-1,1,-1}, dy[]={-1,1,0,0,1,-1,-1,1};
const int mod = 1e9+7;

ll poww(ll x, ll y) {
  ll res = 1;
  rep(i,0,y)
    res *= x;
  return res;
}

int main() {
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(16);

	int t;
	cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		cout << "Case #" << ti << ": ";
    ll n; cin >> n;
    string s_n = to_string(n);
    ll l = s_n.size();
    ll i = 1;
    ll steps = 1;
    if (s_n.size() == 1)
      cout << n << endl;
    else {
      ll steps = 10;
      rep(e,2,l)
        steps += poww(10, e/2)-1 + 1 + poww(10, e-e/2)-1;
      string s1 = s_n.substr(0, l/2), s2 = s_n.substr(l/2);
      ll steps2 = 0;
      if (n != poww(10, l-1)) {
        if (stoi(s2) == 0) {
          s1 = to_string(stoi(s1)-1);
          s2 = to_string(poww(10, s2.size())-1);
          steps += 1;
        }
        if (s1 != to_string(poww(10, l/2-1))) {
          string s = s1;
          reverse(all(s));
          steps2 += stoi(s);
        }
        steps2 += stoi(s2);
      }
      cout << steps + min(steps2, n - poww(10, l-1)) << endl;
    }
	}
}
