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

char s[1005];

int main()
{
  freopen("A-large.in", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t;
  cin >> t;
  for(int tt=1;tt<=t;tt++)
  {
    int n;
    scanf("%s", s);
    n = strlen(s);
    printf("Case #%d: ", tt);
    string res;
    for(int i=0;i<n;i++)
    {
      string s1, s2;
      s1 += s[i];
      s1 += res;
      s2 = res;
      s2 += s[i];
      res = max(s1, s2);
    }
    printf("%s\n", res.c_str());
  }
  return 0;
}
