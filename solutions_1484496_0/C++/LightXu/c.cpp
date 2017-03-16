#include <cstdio>
#include <cstdlib>

int N;
int a[20];
int sum[20];
int set1[20], set1_cnt;
int set2[20], set2_cnt;
bool find_answer;

void dfs(int sum1, int sum2, int now)
{
  if (sum1 == sum2 && now)
  {
    find_answer = true;
    set1_cnt = 0;
    set2_cnt = 0;
    //printf("%d %d\n", sum1, sum2);
    return;
  }
  if (now >= N) return;
  if (labs(sum1 - sum2) > sum[N - 1] - sum[now - 1]) return;
  dfs(sum1 + a[now], sum2, now + 1);
  if (find_answer)
  {
    set1[set1_cnt++] = a[now];
    //printf("sum1 %d\n", a[now]);
  }
  else
  {
    dfs(sum1, sum2 + a[now], now + 1);
    if (find_answer)
    {
      set2[set2_cnt++] = a[now];
      //printf("sum2 %d %d\n", a[now], now);
    }
    else
      dfs(sum1, sum2, now + 1);
  }
}

int main()
{
  int T, ca;
  scanf("%d", &T);
  for (ca = 1; ca <= T; ca++)
  {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
      scanf("%d", &a[i]);
    sum[0] = a[0];
    for (int i = 1; i < N; i++)
      sum[i] = sum[i - 1] + a[i];
      
    find_answer = false;
    dfs(0, 0, 0);
    printf("Case #%d:\n", ca);
    if (find_answer)
    {
      for (int i = 0; i < set1_cnt; i++)
        printf("%d%c", set1[i], i < set1_cnt - 1 ? ' ' : '\n');
      for (int i = 0; i < set2_cnt; i++)
        printf("%d%c", set2[i], i < set2_cnt - 1 ? ' ' : '\n');
    }
    else
      puts("Impossible");
  }
  return 0;
}