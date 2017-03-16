#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define VVI vector<VI>
using namespace std;
int n,m,a,b,c,d;
const int MXN = 20;
char buf1[MXN];
char buf2[MXN];
bool pasuje(int x,char *buf)
  {
  FORD(i,n,1)
    {
    if(buf[i] != '?' && buf[i] - '0' != x%10)
      {
//      cerr<<x<<" "<<buf+1<<" "<<i<<endl;
      return 0;
      }
    x/=10;
    }
//  cerr<<x<<" "<<buf+1<<endl;
  return 1;
  }
void solve()
  {
  scanf("%s",buf1+1);
  scanf("%s",buf2+1);
  n = strlen(buf1+1);
  int MX = 1;
  REP(i, n)MX*=10;
  PII best;
  best.f = 1e9;
  FOR(i,0,MX-1)
    {
    if(!pasuje(i, buf1))continue;
    FOR(j,0,MX-1)
      {
      if(!pasuje(j, buf2))continue;
      if(abs(i - j) < abs(best.f - best.s))
        {
        best = MP(i, j);
        }
      if(abs(i - j) == abs(best.f - best.s))
        {
        mini(best, MP(i, j));
        }
      }
    }
  printf("%0*d %0*d\n",n,best.f,n,best.s);
  }
main()
{
int z;
scanf("%d",&z);
FOR(iii,1,z)
  {
  printf("Case #%d: ",iii);
  solve();
  }
}
