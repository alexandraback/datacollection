#include <stdio.h>
#include <string.h>

using namespace std;

const int MAXL = 20;

int n;
char a[MAXL], b[MAXL];
char baka[MAXL], bakb[MAXL];
char smallans_a[MAXL], smallans_b[MAXL];
char bigans_a[MAXL], bigans_b[MAXL];
char ans_a[MAXL], ans_b[MAXL];
long long mindiff, ans_inta, ans_intb;

long long abs(long long a)
{
  return (a < 0) ? -a : a;
}

// status 0: daiding, 1: =, 2 a < b, 3 a > b
void dfs(int cnt, int status)
{
  if (cnt == n)
  {
    long long inta = 0, intb = 0;
    for (int i = 0; i < n; ++i) inta = inta * 10 + a[i] - '0';
    for (int i = 0; i < n; ++i) intb = intb * 10 + b[i] - '0';
    long long diff = abs(intb - inta);
    if ((diff < mindiff) || ((diff == mindiff) && (inta < ans_inta)) || ((diff == mindiff) && (inta == ans_inta) && (intb < ans_intb)))
    {
      mindiff = diff;
      strcpy(ans_a, a);
      strcpy(ans_b, b);
      ans_inta = inta, ans_intb = intb;
//      fprintf(stderr, "mindiff =%lld\n", mindiff);
    }
    return;
  }
//  fprintf(stderr, "cnt = %d, %c-%c\n", cnt, a[cnt], b[cnt]);


  if (a[cnt] == '?' && b[cnt] == '?')
  {
    if (status == 0)
    {
      a[cnt] = b[cnt] = '0';
      dfs(cnt + 1, 0);
      a[cnt] = '0', b[cnt] = '1';
      dfs(cnt + 1, 2);
      a[cnt] = '1', b[cnt] = '0';
      dfs(cnt + 1, 3);
    }
    if (status == 2)
    {
      a[cnt] = '9', b[cnt] = '0';
      dfs(cnt + 1, 2);
    }
    if (status == 3)
    {
      a[cnt] = '0', b[cnt] = '9';
      dfs(cnt + 1, 3);
    }
    a[cnt] = baka[cnt], b[cnt] = bakb[cnt];
  }
  else if (a[cnt] == '?' && b[cnt] != '?')
  {
    if (status == 0)
    {
      a[cnt] = b[cnt];
      dfs(cnt + 1, 0);
      if (b[cnt] > '0')
      {
        a[cnt] = b[cnt] - 1;
        dfs(cnt + 1, 2);
      }
      if (b[cnt] < '9')
      {
        a[cnt] = b[cnt] + 1;
        dfs(cnt + 1, 3);
      }
    }
    if (status == 2)
    {
      a[cnt] = '9';
      dfs(cnt + 1, 2);
    }
    if (status == 3)
    {
      a[cnt] = '0';
      dfs(cnt + 1, 3);
    }
    a[cnt] = baka[cnt], b[cnt] = bakb[cnt];
  }
  else if (a[cnt] != '?' && b[cnt] == '?')
  {
    if (status == 0)
    {
      b[cnt] = a[cnt];
      dfs(cnt + 1, 0);
      if (a[cnt] < '9')
      {
//        fprintf(stderr, "~~~~\n");
        b[cnt] = a[cnt] + 1;
        dfs(cnt + 1, 2);
      }
      if (a[cnt] > '0')
      {
        b[cnt] = a[cnt] - 1;
        dfs(cnt + 1, 3);
      }
    }
    if (status == 2)
    {
      b[cnt] = '0';
      dfs(cnt + 1, 2);
    }
    if (status == 3)
    {
      b[cnt] = '9';
      dfs(cnt + 1, 3);
    }
    a[cnt] = baka[cnt], b[cnt] = bakb[cnt];
  }
  else
  {
    if (status == 0)
    {
      if (a[cnt] < b[cnt])
        dfs(cnt + 1, 2);
      else if (a[cnt] > b[cnt])
        dfs(cnt + 1, 3);
      else
        dfs(cnt + 1, 0);
    }
    if (status == 2)
      dfs(cnt + 1, 2);
    if (status == 3)
      dfs(cnt + 1, 3);
  }
}

int main()
{
  int cases;
  scanf("%d", &cases);
  for (int k = 1; k <= cases; ++k)
  {
    printf("Case #%d: ", k);
    scanf("%s%s", a, b);
    mindiff = 1000000000000000000ll;
    n = strlen(a);

    strcpy(baka, a);
    strcpy(bakb, b);

    dfs(0, 0);

    printf("%s %s\n", ans_a, ans_b);
  }
  return 0;
}
