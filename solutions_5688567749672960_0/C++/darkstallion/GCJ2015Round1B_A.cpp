//darkstallion's template

#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define del erase
#define sz size
#define ins insert
#define FOR(a,b,c) for(int a = b; a < c; a++)
#define FORS(a,b,c) for(int a = b; a <= c; a++)
#define FORN(a,b) for(int a = 0; a < b; a++)
#define FORD(a,b,c) for (int a = b; a >= c; a--)
#define RES(a,b) memset(a,b,sizeof(a))
#define LL long long
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define PDD pair<double,double>
#define PCC pair<char,char>
#define PSS pair<string,string>
#define PI acos(-1)
#define eps 1e-9
#define MOD 1000000007
using namespace std;

int rev(int n)
{
  int ret = 0;
  while (n > 0)
  {
    ret *= 10;
    ret += n%10;
    n /= 10;
  }
  return ret;
}

int main()
{
  int t;
  scanf("%d",&t);
  FORN(i,t)
  {
    LL n;
    scanf("%lld",&n);
    if (n <= 20LL)
      printf("Case #%d: %lld\n",i+1,n);
    else
    {
      LL z = n, ans = 1LL, mult = 1LL, fmult = 1LL;
      int count = 0;
      while (z > 0LL)
      {
        z /= 10LL;
        count++;
      }
      FORN(j,(count+1)/2)
        mult *= 10LL;
      FORN(j,count-1)
        fmult *= 10LL;
      while (n > 1LL)
      {
        ans += n-(n/mult*mult);
        n = n/mult*mult+1LL;
        n = rev(n);
        ans += n-(fmult-9LL);
        n = fmult-9LL;
        count--;
        fmult /= 10LL;
        if (count % 2 == 0)
          mult /= 10LL;
      }
      printf("Case #%d: %lld\n",i+1,ans);
    }
  }
}