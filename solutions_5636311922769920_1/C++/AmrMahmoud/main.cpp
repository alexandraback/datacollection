#include <bits/stdc++.h>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 1000000000
#define PI acos(-1)
#define EPS 1e-8
#define LL long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))
#define bits(a) __builtin_popcount(a)

using namespace std;

LL power(int a, int b)
{
  if(b == 0) return 1;
  LL tmp = power(a, b / 2);
  tmp *= tmp;
  if(b & 1) tmp *= a;
  return tmp;
}

int main()
{
  freopen("D-large.in", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t;
  cin >> t;
  for(int tt=1;tt<=t;tt++)
  {
    int k, c, s;
    cin >> k >> c >> s;
    printf("Case #%d:", tt);
    if((k + c - 1) / c > s)
    {
      printf(" IMPOSSIBLE\n");
      continue;
    }
    for(int i=1;i<=k;i+=c)
    {
      LL x = 1, p = power(k, c - 1);
      for(int j=i;j<=min(k, i + c);j++)
      {
        x += p * (j - 1);
        p /= k;
      }
      printf(" %I64d", x);
    }
    printf("\n");
  }
  return 0;
}
