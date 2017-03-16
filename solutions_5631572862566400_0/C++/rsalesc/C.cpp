#include <bits/stdc++.h>

// clang-format off
using namespace std;
typedef int i32;
#define int long long
#define all(a) (a).begin(), (a).end()
#define ms(a,v) memset(a, v, sizeof(a))
#define mp make_pair
#define pb push_back
#define prev franga_de_sunga
#define next tio_de_sueter
#define index bora_baea
#define left ahsiha19as
#define VAR(i, x) __typeof(x) i=(x)
#define R32 ({i32 x; scanf("%d", &x); x;})
#define RL ({long long x; scanf("%lld", &x); x;})
#define RC ({char x; scanf(" %c", &x); x;})
#define foreach(i, x) for(VAR(i, (x).begin()); i != (x).end(); ++(i))
#define RI RL
typedef pair<int, int> ii;
typedef long long ll;
// clang-format on

const int N = 1010;
int p[N], inc[N], from[N], best[N][N];
int vis[N];

bool dfs(int u) {
  if (vis[u] == 1) {
    from[u] = u;
    inc[from[u]] = 0;
    return true;
  } else if (vis[u] == 2)
    return false;

  vis[u] = 1;
  if (dfs(p[u])) {
    from[u] = from[p[u]];
    inc[from[u]]++;
  } else {
    vis[u] = 2;
    return false;
  }

  vis[u] = 2;
  return from[u] != u;
}

void solve(int tn) {
  int n = RI;

  // init
  for (int i = 1; i <= n; i++) {
    p[i] = RI;
    inc[i] = vis[i] = from[i] = 0;
    for (int j = 1; j <= n; j++)
      best[i][j] = 0;
  }

  for (int i = 1; i <= n; i++) {
    if (!vis[i])
      dfs(i);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int u = i;

    int len = 0;
    while (!from[u]) {
      u = p[u];
      len++;
    }

    // cout << len << " from " << from[u] << " " << inc[from[u]] << endl;
    best[from[u]][u] = max(best[from[u]][u], len);
    ans = max(ans, inc[from[u]]);
  }

  set<int> used;

  int acc = 0;
  for (int i = 1; i <= n; i++) {

    if (inc[i] == 2 && !used.count(i)) {
      int as = inc[i];
      for (int j = 1; j <= n; j++) {
        if (from[j] == i)
          as += best[i][j];
      }

      acc += as;
      used.insert(i);
    }
  }

  // cout << acc << " " << ans << endl;
  ans = max(ans, acc);
  printf("Case #%lld: %lld\n", tn, ans);
}

i32 main() {
  // YOU SHALL CLEAR DAMN VARIABLES BEFORE EACH TEST
  // WITH MEMSET
  int T = RI;
  for (int tn = 1; tn <= T; tn++)
    solve(tn);
}
