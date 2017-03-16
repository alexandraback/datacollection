#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <utility>
#include <functional>
#define LL long long
#define vi vector<int>
#define pb push_back
#define sz size
#define all(x) (x).begin(),(x).end()
#define it iterator
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define REPX(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define DEP(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define REX(i,x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end();i++)
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define spii stack<pii >
#define ub upper_bound
#define lb lower_bound
#define bs binary_search
#define em empty
#define mems(x) memset(x,0,sizeof(x))
#define memc(x,y) memcpy(x,y,sizeof(y))
#define MAX 10010
using namespace std;
char x[MAX]; int y[5][5],lm[MAX],rm[MAX],z[4][4];
inline int val(char c)
{
  if(c=='i') return 2;
  if(c=='j') return 3;
  return 4;
}
void init()
{
  REP(i,1,5) y[1][i]=y[i][1]=i;
  REP(i,2,5) y[i][i]=-1;
  REP(i,2,5)
  {
    int j=(i+1)%5;
    if(!j) j=2;
    int k=(j+1)%5;
    if(!k) k=2;
    y[i][j]=k;
    y[j][i]=-k;
  }
}
inline int my_pow(int a,int b)
{
  if(a==1) return 1;
  if(a==-1)
  {
    if(b%2==0) return 1;
    return -1;
  }
  if(b%2==0)
  {
    if(b%4==0) return 1;
    return -1;
  }
  if((b-1)%4==0) return a;
  return -a;
}
inline int mult(int p,int q)
{
  int v=y[abs(p)][abs(q)];
  if(p<0) v=-v;
  if(q<0) v=-v;
  return v;
}
int get_li(int p,int q,int n)
{
   REP(i,1,n+1) if(mult(p,lm[i])==q) return i;
   return -1;
}
int get_ri(int p,int q,int n)
{
  DEP(i,n+1,1) if(mult(rm[i],p)==q) return i;
  return -1;
}
int main()
{
  init();
  int tc; scanf("%d",&tc);
  REP(t,0,tc)
  {
    int n; LL k;
    scanf("%d %lld",&n,&k);
    scanf("%s",x+1);
    lm[0]=rm[n+1]=1;
    REP(i,1,n+1) lm[i]=mult(lm[i-1],val(x[i]));
    DEP(i,n+1,1) rm[i]=mult(rm[i+1],val(x[i]));
    int v=my_pow(lm[n],k);
    printf("Case #%d: ",t+1);
    if(v!=-1) printf("NO\n");
    else
    {
       int f=0;
       REP(i,0,4) REP(j,0,4)
       {
         int li=get_li(my_pow(lm[n],i),2,n);
         int ri=get_ri(my_pow(lm[n],j),4,n);
         if(li==-1 || ri==-1 || k<=i+j) continue;
         if(k==i+j+1) f|=(ri>li);
         else f=1;
       }
       if(f) printf("YES\n");
       else printf("NO\n");
    }
  }
  return 0;
}
