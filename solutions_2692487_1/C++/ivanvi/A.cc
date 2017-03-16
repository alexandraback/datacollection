#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_M 1000005
#define MAX_N 105
#define MAX_VALUE 1000002

void input(void);
void solve(void);
int dp(int i, int sum);

int n, m;
int V[MAX_N];
short F[MAX_N][MAX_M];
int case_cnt = 1;

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    input();
    solve();
  }
  return 0;
}

void input(void) {
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; i++) scanf("%d", &V[i]);
}

void solve(void) {
  sort(V, V + n);
  memset(F, -1, sizeof(F));
  printf("Case #%d: %d\n", case_cnt++, dp(0, m));
}

int dp(int i, int sum) {
  if (i == n)          return 0;
  if (sum > MAX_VALUE) return dp(i, MAX_VALUE);
  if (F[i][sum] != -1) return F[i][sum];

  int best = MAX_N;
  if (sum > V[i]) {
    best = dp(i + 1, sum + V[i]);
  } else {
    if (sum > 1) {
      best = min(best, 1 + dp(i, sum + sum - 1));
    }
    best = min(best, 1 + dp(i + 1, sum));
  }

  return F[i][sum] = best;
}


