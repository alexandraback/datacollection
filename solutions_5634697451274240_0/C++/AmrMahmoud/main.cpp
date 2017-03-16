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

char s[105];

int main()
{
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t;
  cin >> t;
  for(int tt=1;tt<=t;tt++)
  {
    int n;
    scanf("%s", s);
    n = strlen(s);
    printf("Case #%d: ", tt);
    int ans = 0;
    for(int i=n - 1;i>=0;i--)
    {
      if(s[i] == '+') continue;
      if(s[0] == '+')
      {
        ans++;
        for(int j=0;j<=i;j++)
        {
          if(s[j] == '+')
            s[j] = '-';
          else break;
        }
        if(i == 0) break;
      }
      ans++;
      reverse(s, s + i + 1);
      for(int j=0;j<=i;j++)
      {
        if(s[j] == '+')
          s[j] = '-';
        else s[j] = '+';
      }
      //printf("%s\n", s);
    }
    printf("%d\n", ans);
  }
  return 0;
}
