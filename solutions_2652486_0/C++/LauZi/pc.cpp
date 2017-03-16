#include <cstdio>

int r, n, m, k;

int arr[5];
int guess[7];
int guess_cnt[7];

int ans, Mcnt;

int dfs_2(int i, int prd) {
  if (i == n) {
    for (int j = 0; j < k; ++j)
      if (prd == guess[j])
	guess_cnt[j] += 1;
    return 0;
  }

  return dfs_2(i + 1, prd) * dfs_2(i + 1, prd * arr[i]);
}

void dfs(int i) {
  if (i == n) {
    for(int j = 0; j < k; ++j)
      guess_cnt[j] = 0;
    dfs_2(0, 1);
    int jizz = 1;
    for (int j = 0;j <k;++j)
      jizz *= guess_cnt[j];
    if (jizz > Mcnt) {
      Mcnt = jizz;
      ans = 0;
      for (int j = 0; j < n; ++j)
	ans = ans * 10 + arr[j];
    }
    return;
  }

  for (int j = 2; j <= m; ++j) {
    arr[i] = j;
    dfs(i + 1);
  }
}

void jizz() {
  for (int i = 0; i < k; ++i)
    scanf("%d", &guess[i]);

  Mcnt = 0;
  dfs(0);

  printf("%d\n", ans);
}

int main() {
  scanf("%*d");
  scanf("%d%d%d%d", &r, &n, &m, &k);

  puts("Case #1:");

  for (int i = 0; i < r; ++i) {
    jizz();
  }
  return 0;
}
