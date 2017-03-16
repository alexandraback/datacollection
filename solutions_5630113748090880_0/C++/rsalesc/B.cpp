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

const int INF = 1e9;
int g[150][55];
bool used[150];
vector<int> ans[55], ans2[55], ans3[55];

void solve(int tn) {
  int n;
  cin >> n;

  for (int i = 0; i < 2 * n - 1; i++) {
    used[i] = 0;
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
  }

  int miss = -1;
  for (int i = 0; i < n; i++) {
    int best = INF;
    vector<int> cand;

    for (int j = 0; j < 2 * n - 1; j++) {
      if (!used[j]) {
        if (g[j][i] < best)
          best = g[j][i], cand.clear();
        if (g[j][i] <= best)
          cand.push_back(j);
      }
    }

    // assert(cand.size() == 2);
    // cout << cand.size() << endl;
    if (cand.size() == 1)
      miss = i;

    for (int x : cand)
      used[x] = 1;
    ans[i] = cand;
  }

  assert(miss != -1);

  for (int i = 0; i < n; i++) {
    ans2[i].clear();
    if (i == miss) {
      ans2[i].push_back(g[ans[i][0]][miss]);
      ans2[i].push_back(g[ans[i][0]][miss]);
      continue;
    }

    ans2[i].push_back(g[ans[i][0]][miss]);
    ans2[i].push_back(g[ans[i][1]][miss]);
  }

  printf("Case #%lld:", tn);
  for (int i = 0; i < n; i++) {
    if (ans2[i][0] != g[ans[miss][0]][i])
      swap(ans2[i][0], ans2[i][1]);

    printf(" %lld", ans2[i][1]);
  }
  puts("");
}

i32 main() {
  // YOU SHALL CLEAR DAMN VARIABLES BEFORE EACH TEST
  // WITH MEMSET
  int T = RI;
  for (int tn = 1; tn <= T; tn++)
    solve(tn);
}
