#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < int(b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define D(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
  cout << "Case #" << tc << ": ";
  string s;
  cin >> s;
  s += '+';
  int ans = 0;
  rep(i,0,sz(s)-1) {
    ans += s[i] != s[i+1];
  }
  cout << ans << endl;
}

int main() {
  int N;
  cin >> N;
  rep(i,1,N+1) solve(i);
}
