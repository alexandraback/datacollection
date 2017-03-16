#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

typedef long long ll;

const int MAX_N = 6;
int N;
ll M;
int adj[MAX_N][MAX_N];
bool seen[MAX_N];

ll count(int n) {
  if (n == N - 1) return 1LL;
  ll c = 0;
  seen[n] = true;
  for (int i = 0; i < N; ++i) {
    if (adj[n][i]) {
      if (seen[i]) return LLONG_MIN;
      ll val = count(i);
      if (val == LLONG_MIN) return val;
      c += val;
    }
  }
  seen[n] = false;
  return c;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d %lld", &N, &M);

    int total = N * N - 2 * N + 1;
    int m[MAX_N][MAX_N] = {};
    int idx = 1;
    for (int a = 0; a < N; ++a) {
      for (int b = 0; b < N; ++b) {
        if (a == b) continue;
        if (a == N - 1) continue;
        m[a][b] = idx++;
      }
    }

    bool doable = false;
    printf("Case #%d:", t);
    for (int i = 0; i < (1 << total); ++i) {
      for (int a = 0; a < N; ++a) {
        seen[a] = false;
        for (int b = 0; b < N; ++b) {
          adj[a][b] = m[a][b] ? i & (1 << (m[a][b] - 1)) : 0;
        }
      }
      for (int a = 0; a < N; ++a) {
        for (int b = 0; b < N; ++b) {
          if (adj[a][b] && adj[b][a]) goto end;
        }
      }
      if (count(0) == M) {
        doable = true;
        printf(" POSSIBLE\n");
        for (int a = 0; a < N; ++a) {
          for (int b = 0; b < N; ++b) {
            printf("%d", adj[a][b] ? 1 : 0);
          }
          printf("\n");
        }
        break;
      }
      end:;
    }
    if (!doable) {
      printf(" IMPOSSIBLE\n");
    }
  }
}
