#include <cstdio>

typedef long long ll;

int arr[10], n;
int e, r;

ll dfs(int j, int lc, ll acc) {
  if (j == n) return acc;
  ll M = 0;
  int i = lc + r - e;
  if (i < 0) i = 0;
  for (; i <= lc; ++i) {
    ll na = dfs(j + 1, lc - i + r, acc + (ll)i * arr[j]);
    if (na > M) M = na;
  }
  return M;
}

ll jizz() {
  scanf("%d%d%d", &e, &r, &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);

  if (e - r <= 0) {
    ll sum = 0;
    for (int i = 0; i < n; ++i)
      sum += arr[i];
    return sum * e;
  }

  return dfs(0, e, 0);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; ++i)
    printf("Case #%d: %I64d\n", i, jizz());

  return 0;
}
