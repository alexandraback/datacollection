//#pragma comment(linker, "/STACK:512000000")
#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define LL long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

using namespace std;

const int N = 1e5 + 7;
const int mod = 1e9 + 7;

void solve() {
  string s, t;
  cin >> s >> t;
  int n = sz(s);
  int mn = INT_MAX;
  int x, y;
  int v1, v2;
  if(n == 1) {
    forn(i, 10) 
      forn(j, 10) {
        v1 = s[0] == '?' ? i : s[0] - '0';
        v2 = t[0] == '?' ? j : t[0] - '0';
        if(abs(v1-v2) < mn) {
          mn = abs(v1-v2);
          x = v1, y = v2;
        }
      }
    printf("%d %d\n", x, y);
  }
  else if(n == 2) {
    forn(i, 10) forn(j, 10)
      forn(ii, 10) forn(jj, 10) {
        v1 = (s[0] == '?' ? i : s[0] - '0') * 10 + (s[1] == '?' ? j : s[1] - '0');
        v2 = (t[0] == '?' ? ii : t[0] - '0') * 10 + (t[1] == '?' ? jj : t[1] - '0');
        if(abs(v1-v2) < mn) {
          mn = abs(v1-v2);
          x = v1, y = v2;
        }
     }
     printf("%d%d %d%d\n", (x/10), x%10, (y/10), y%10);
  }
  else {
    forn(i, 10) forn(j, 10) forn(k, 10) 
      forn(ii, 10) forn(jj, 10) forn(kk, 10) {
        v1 = (s[0] == '?' ? i : s[0] - '0') * 100 + (s[1] == '?' ? j : s[1] - '0') * 10 + (s[2] == '?' ? k : s[2] - '0');
        v2 = (t[0] == '?' ? ii : t[0] - '0') * 100 + (t[1] == '?' ? jj : t[1] - '0') * 10 + (t[2] == '?' ? kk : t[2] - '0');
        if(abs(v1-v2) < mn) {
          mn = abs(v1-v2);
          x = v1, y = v2;
        }
     }
     printf("%d%d%d %d%d%d\n", x/100, (x/10)%10, x%10, y/100, (y/10)%10, y%10);
  }
}


int main() {
  #ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
      printf("Case #%d: ", i);
      solve();
    }
  return 0;
}
