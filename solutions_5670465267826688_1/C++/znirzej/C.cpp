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
int n,a,b;
LL m;
char ch;
enum mult{A,I,J,K,mA,mI,mJ,mK};
mult t[][8]={
  {A,I,J,K,mA,mI,mJ,mK},
  {I,mA,K,mJ,A,mJ,mK,J},
  {J,mK,mA,I,mJ,K,A,mI},
  {K,J,mI,mA,mK,mJ,I,A},
  {mA,mI,mJ,mK,A,I,J,K},
  {mI,A,mK,J,mA,J,K,mJ},
  {mJ,K,A,mI,J,mK,mA,I},
  {mK,mJ,I,A,K,J,mI,mA}
  };
mult operator*(mult a,mult b)
  {
  return t[a][b];
  }
const int MXN=1e4+4;
const int R=20;
mult in[MXN*(R+5)];

void solve()
  {
  scanf("%d%lld",&n,&m);
  int razy=0;
  if(m<=R)razy=m;
  else razy=R+m%4;
  FOR(i,1,n)
    {
    scanf(" %c",&ch);
    if(ch=='i')in[i]=I;
    if(ch=='j')in[i]=J;
    if(ch=='k')in[i]=K;
    }
  FOR(i,1,n*(razy-1))
    {
    in[i+n]=in[i];
    }
  n*=razy;
  mult val=A;
  bool ok1=0,ok2=0,ok3=0;
  FOR(i,1,n)
    {
    val=val*in[i];
    if(val==I)ok1=1;
    if(val==K&&ok1)ok2=1;
    }
  if(val==mA&&ok1&&ok2)ok3=1;
  puts(ok3?"YES":"NO");
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
