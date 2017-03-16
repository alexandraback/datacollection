#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int cmax = 26 + 18 + 'a', nmax = 100 + 18, lmax = 100 + 18, mo = 1000000000 + 7;

int n;
char word[nmax][lmax];
int connect[cmax], total[cmax], midpa[cmax];
int ind[cmax], oud[cmax];
int exist[cmax];
bool ed[cmax];
// int linknum;
bool cur[cmax];

void read(int i)
{
  scanf("%s", word[i] + 1);
  int m = strlen(word[i] + 1);
  char l = word[i][1], r = word[i][m];
  int lc, rc;
  for (lc = 1; word[i][lc] == l && lc <= m; ++lc);
  for (rc = m; word[i][rc] == r && rc >= 1; --rc);
  if (rc - lc + 1 > 0) {
    for (int j = lc; j <= rc; ++j) {
      int c = word[i][j];
      ++exist[c];
      while (word[i][j + 1] == c && j + 1 <= rc) ++j;
    }
    connect[l] = r;
    ++ind[r];
    ++oud[l];
  }
  else if (l == r) 
    ++total[l]; 
  else {
    connect[l] = r;
    ++ind[r];
    ++oud[l];
  }
  cur[l] = cur[r] = 1;
}

int fact(int k)
{
  int rnt = 1;
  for (int i = 1; i <= k; ++i)
    rnt = (long long)rnt * i % mo;
  return rnt;
}

int calccircle()
{
  int sum = 1, rnt = 1;
  rnt = (long long)rnt * midpa['a'] % mo;
  for (int i = connect['a']; i; i = connect[i]) {
    ++sum;
    rnt = (long long)rnt * midpa[i] % mo;
  }
  for (int i = 'a'; i <= 'z'; ++i)
    if (cur[i])
      --sum;
  if (sum != 0) return 0;
  return rnt;
}

int calc()
{
  for (int i = 'a'; i <= 'z'; ++i)
    if (connect[i] == i || exist[i] > 1 || (exist[i] == 1 && (total[i] > 0 || ind[i] > 0 || oud[i] > 0)) || ind[i] > 1 || oud[i] > 1)
      return 0;
  for (int i = 'a'; i <= 'z'; ++i)
    midpa[i] = fact(total[i]);
  bool circle = 1;
  for (int i = 'a'; i <= 'z'; ++i)
    if (cur[i] && (ind[i] != 1 || oud[i] != 1)) {
      circle = 0;
      break;
    }
  if (circle) 
    return 0;
    // return calccircle();
  int sum = 0, rnt = 1;
  for (int i = 'a'; i <= 'z'; ++i)
    if (cur[i] && ind[i] == 0) {
      ++sum;
      rnt = (long long) rnt * midpa[i] % mo;
      for (int j = connect[i]; j; j = connect[j])
	if (j == i)
	  return 0;
	else
	  rnt = (long long) rnt * midpa[j] % mo;
    }
  return (long long)rnt * fact(sum) % mo;
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int cases = 1; cases <= T; ++cases) {
    printf("Case #%d: ", cases);
    memset(ind, 0, sizeof(ind));
    memset(oud, 0, sizeof(oud));
    memset(total, 0, sizeof(total));
    memset(exist, 0, sizeof(exist));
    memset(ed, 0, sizeof(ed));
    memset(cur, 0, sizeof(cur));
    memset(connect, 0, sizeof(connect));
    // linknum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      read(i);
    // printf("\n");
    // for (int i = 1; i <= n; ++i)
    //   printf("%s\n", word[i] + 1);
    printf("%d\n", calc());
  }
  return 0;
}

