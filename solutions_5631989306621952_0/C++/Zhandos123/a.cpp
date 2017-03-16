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

int T, n;
char s[1010];
string t;

int main() {
  #ifndef ONLINE_JUDGE
  freopen("A-small-attempt0 (1).in", "r", stdin);
  freopen("A-small-attempt0 (1).out", "w", stdout);
  #endif
    scanf("%d", &T);
    for(int it = 1; it <= T; ++it) {
      scanf("\n%s", s);
      n = strlen(s);
      t = "";
      forn(i, n) {
        if(i == 0) 
          t += s[i];
        else {
          if(s[i] >= t[0]) 
            t.insert(t.begin() + 0, s[i]);
          else
            t += s[i];
        }
      }
      printf("Case #%d: %s\n", it, t.c_str());
    }
  return 0;
}
