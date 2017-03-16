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

int n, T, x;
int cnt[3000];

int main() {
  #ifndef ONLINE_JUDGE
  freopen("B-small-attempt0 (1).in", "r", stdin);
  freopen("B-small-attempt0 (1).out", "w", stdout);
  #endif
    scanf("%d", &T);
    for(int it = 1; it <= T; ++it) {
      scanf("%d", &n);
      memset(cnt, 0, sizeof cnt);
      forn(i, n + n - 1) forn(j, n) {
        cin >> x;
        cnt[x]++;
      }
      printf("Case #%d: ", it);
      forn(i, 2500) {
        if(cnt[i] > 0 && (cnt[i] & 1)) {
          printf("%d ", i);
        }
      }
      printf("\n");
    }
  return 0;
}
