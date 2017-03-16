
#include<cstdio>
#include<set>
#include<map>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<ctime>
#define read freopen("in.txt","r",stdin)
#define maxlongint 2147483647
typedef  long long LL;
typedef  unsigned long long ULL;
#define fori for(i=1;i<=n;i++)
#define forj for(j=1;j<=n;j++)
#define fork for(k=1;k<=n;k++)
#define FOR(i,n) for(i=1;i<=n;i++)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define DREP(i,a,b) for(i=a;i>=b;i--)
#define DOWN(i,n) for(i=n;i>=1;i--)
#define enter cout<<endl;
#define in push_back
#define out pop_back
#define lson 2*k
#define rson 2*k+1
#define offcin ios::sync_with_stdio(false)

#define s(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define sd(x,y) scanf("%d%d",&x,&y)
#define sch(s) scanf("%s",s)
#define fillfalse(v) memset(v,false,sizeof(v))
#define filltrue(v) memset(v,true,sizeof(v))
#define Fill0(a)    memset(a,0,sizeof(a))
#define Fillplus(a)    memset(a,-1,sizeof(a))
#define lowbit(x) x&(-x)
using namespace std;
const int maxn=100005;
const double pi=2*acos(0);
LL k,T,ii,i,j,n,m,l,sum;
LL a[50][50];
int b[100];
LL po(LL x)
{
 LL i,k;
 k=1;
 FOR(i,x) k*=2;
 return k;
}
int main()
{
 freopen("B-small-attempt0.in","r",stdin);
 freopen("out.txt","w",stdout);
 cin>>T;
 FOR(ii,T)
 {


  Fill0(a);
  cin>>n>>m;
  cout<<"Case #"<<ii<<": ";
  if (m<=po(n-2)) cout<<"POSSIBLE"<<endl;
  else {cout<<"IMPOSSIBLE"<<endl; continue;}
  REP(i,2,n-1)
  REP(j,i+1,n) a[i][j]=1;
  if (m==po(n-2)) REP(i,2,n) a[1][i]=1;
  else
  {
   k=n-1;
   while(m!=0) {a[1][k]=m%2; m=m/2; k--;}
  }
  fori {forj cout<<a[i][j]; cout<<endl;}
 }
}
