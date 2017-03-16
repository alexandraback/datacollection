#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
typedef long long int Number;
const int MAXN = 1000007;

int dist[MAXN];
int solve(int ini) {
  memset(dist, -1, sizeof(dist));
  queue<int> q;
  q.push(ini);
  dist[ini] = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    int v;
    v = u + 1;
    if (v < MAXN && dist[v] == -1) {
      dist[v] = dist[u] + 1;
      q.push(v);
    }
    int uu = u;
    v = 0;
    while (u > 0) {
      v = v * 10 + (u % 10);
      u /= 10;
    }
    u = uu;
    if (v < MAXN && dist[v] == -1) {
      dist[v] = dist[u] + 1;
      q.push(v);
    }
  }
  return dist[ini];
}
int main() {
  int t;
  scanf("%d", &t);
  solve(1);
  for (int caso = 1; caso <= t; caso++) {
    int n;
    scanf("%d", &n);
    printf("Case #%d: %d\n", caso, dist[n]);
  }
  return 0;
}
