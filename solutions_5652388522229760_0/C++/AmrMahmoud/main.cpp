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

int main()
{
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t;
  cin >> t;
  for(int tt=1;tt<=t;tt++)
  {
    int n;
    scanf("%d", &n);
    printf("Case #%d: ", tt);
    if(n == 0)
    {
      printf("INSOMNIA\n");
      continue;
    }
    bool v[15];
    setzero(v);
    int cnt = 0;
    LL m = n;
    while(cnt != 10)
    {
      LL tmp = n;
      while(tmp)
      {
        if(!v[tmp % 10])
          cnt++, v[tmp % 10] = true;
        tmp /= 10;
      }
      if(cnt != 10) n += m;
    }
    printf("%d\n", n);
  }
  return 0;
}
