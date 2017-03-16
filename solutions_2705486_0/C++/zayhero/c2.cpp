#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

const int N = 521200;
const int M = 100;
const int K = 4100;
const int dic_size = 521196;
const int INF = 1 << 28;

char dic[N][13];
int dict_len[N];
char str[K];
int n, ans, dp[M][M];

void prep()
{
  FILE *f = fopen("garbled_email_dictionary.txt", "r");
  for(int i = 0; i < dic_size; i++)
  {
    fscanf(f, "%s", dic[i]);
    dict_len[i] = strlen(dic[i]);
  }
  fclose(f);
}

void init()
{
  scanf("%s", str+1);
  n = strlen(str+1);
  memset(dp, -1, sizeof(dp));
}

pii cal(int st, int k, int val)
{
  int pre, ret = 0;
  if(!val) pre = -100; else pre = val;

  for (int i = st, j = 0; j < dict_len[k]; i++, j++)
  {
    if (str[i] != dic[k][j])
    {
      if (i - pre < 5) return mp(-1, 0);
      ret++;
      pre = i;
    }
  }
  if (pre == -100) pre = 0;
  return mp(ret, pre);
}

int dfs(int p, int pre)
{
  if (p >= n+1) return 0;
  if (dp[p][pre] != -1) return dp[p][pre];
  dp[p][pre] = INF;
  for(int i = 0; i < dic_size; i++)
  {
    if (p + dict_len[i] > n + 1) continue;
    pii tmp = cal(p, i, pre);
    if(tmp.fst == -1) continue;
    int mid = dfs(p + dict_len[i], tmp.snd) + tmp.fst;
    dp[p][pre] = min(dp[p][pre], mid);
  }
  return dp[p][pre];
}

void solve(int tcase)
{
  int ans = dfs(1, 0);
  printf("Case #%d: %d\n", tcase, ans);
}

int main()
{
    int T;
    prep();
    scanf("%d", &T);
    for(int i = 1; i <= T; i++)
    {
      init();
      solve(i);
    }
}

