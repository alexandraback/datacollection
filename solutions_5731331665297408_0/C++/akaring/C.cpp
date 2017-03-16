#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void checkMin(T &a, T b) { if(b<a) a=b; }
template<typename T> inline void checkMax(T &a, T b) { if(a<b) a=b; }
#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for (int i=0;i<int(n);++i)
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int MAX_N = 10;

int n, m;
int mp[MAX_N][MAX_N];
int ed[MAX_N][MAX_N];
bool vis[MAX_N];

int perm[MAX_N];

bool dfs(int i, int u) {
  if (i == n) {
    return true;
  }
  REP (v, n) {
    if (ed[u][v] == 1 && !vis[v] && v == perm[i]) {
      ed[u][v] = 0;
      ed[v][u] = 2;
      vis[v] = true;
      if (dfs(i + 1, v)) {
        return true;
      }
      vis[v] = false;
      ed[u][v] = 1;
      ed[v][u] = 1;
    } else if (ed[u][v] == 2 && vis[v]) {
      ed[u][v] = 0;
      if (dfs(i, v)) {
        return true;
      }
      ed[u][v] = 2;
    }
  }
  return false;
}

string zip[MAX_N];

void work() {
  scanf("%d%d", &n, &m);
  REP (i, n) {
    char s[8];
    scanf("%s", s);
    zip[i] = s;
  }
  fill(mp[0], mp[MAX_N], 0);
  REP (i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    u -= 1, v -= 1;
    mp[u][v] = 1;
    mp[v][u] = 1;
  }

  if (n == 1) {
    printf("%s\n", zip[0].c_str());
    return;
  }

  REP (i, MAX_N) {
    perm[i] = i;
  }

  string ans;
  REP (i, 5 * n + 1) {
    ans += "9";
  }
  do {
    copy(mp[0], mp[n], ed[0]);
    fill(vis, vis + n, false);
    vis[perm[0]] = true;
    if (dfs(1, perm[0])) {
      string t;
      REP (i, n) {
        t += zip[perm[i]];
      }
      checkMin(ans, t);
    }
  } while (next_permutation(perm, perm + n));
  printf("%s\n", ans.c_str());
}

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d: ", index);
    work();
  }
  return 0;
}
