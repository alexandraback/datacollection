#include <bits/stdc++.h>

using namespace std;

#ifdef ACMTUYO
struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#else
struct RTC{};
#define DBG(X)
#endif

#define fast_io() ios_base::sync_with_stdio(false)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
typedef long long int number;
const int maxn = 51;
const int maxpaths = 21;
int n;
bool g[maxn][maxn];
number paths[maxn];
vector<int> memo[maxn][maxpaths];

int main() {
  fast_io();
  for (int N = 2; N <= 6; N++) {
    vector<pair<int, int> > arcos;
    forn (u, N)
      for (int v = u + 1; v < N; v++)
        arcos.eb(u, v);

    for (int mask = 0, lim = (1 << sz(arcos)); mask < lim; mask++) {
      memset(g, false, sizeof(g));
      forn (i, sz(arcos))
        if (mask & (1 << i))
          g[arcos[i].first][arcos[i].second] = true;
      paths[N - 1] = 1LL;
      for (int i = N - 2; i >= 0; i--) {
        paths[i] = 0;
        for (int j = 0; j < N; j++)
          if (g[i][j])
            paths[i] += paths[j];
      }
      if (paths[0] <= 20) {
        vector<int> tmp;
        forn (i, N) {
          int mask = 0;
          forn (j, N)
            if (g[i][j])
              mask |= (1 << j);
          tmp.pb(mask);
        }
        memo[N][paths[0]] = tmp;
      }
    }
  }
   int casos;
  cin >> casos;
  for (int caso = 1; caso <= casos; caso++) {
    int caminos;
    cin >> n >> caminos;
    printf("Case #%d: ", caso);
    if (sz(memo[n][caminos]) > 0) {
      printf("POSSIBLE\n");
      for (int mask: memo[n][caminos]) {
        forn (i, n)
          if (mask & (1 << i))
            printf("1");
          else
            printf("0");
        printf("\n");
      }
    } else {
      printf("IMPOSSIBLE\n");
    }
    
  }
  return 0;
}

