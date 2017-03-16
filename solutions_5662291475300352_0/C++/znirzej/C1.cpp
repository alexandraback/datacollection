#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<set>
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
using namespace std;
int n,m,a,b,c,d;
char ch;
VPII ziomki;
void solve()
  {
  scanf("%d",&n);
  FOR(i,1,n)
    {
    scanf("%d%d%d",&a,&b,&c);
    FOR(i,c,b+c-1)
      {
      ziomki.PB(MP(a,i));
      }
    }
  if(ziomki.size()!=2||ziomki[0].s==ziomki[1].s)
    {
    puts("0");
    return;
    }
  if(ziomki[0].s>ziomki[1].s)swap(ziomki[0],ziomki[1]);
  
  
  int p1=ziomki[0].f;
  int p2=ziomki[1].f;
  int v1=ziomki[0].s;
  int v2=ziomki[1].s;
  p1-=360;
  LD czas=-((LD)p1-p2)/360.0/(v2-v1);
  LD wolniejszy=(1.0-p2/360.0)*v2;
  
//  cerr<<czas<<" "<<wolniejszy<<endl;
  if(czas-1e8<wolniejszy)
    {
    puts("1");
    }
  else
    puts("0");
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
