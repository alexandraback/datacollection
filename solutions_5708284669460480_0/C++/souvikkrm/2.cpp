#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <utility>
#include <functional>
#include <queue>
#include <cmath>
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
#define st string
#define ffo find_first_of
#define su substr
#define vs vector<st>
#define ub upper_bound
#define lb lower_bound
#define bs binary_search
#define li list<int>
#define em empty
#define mems(x) memset(x,0,sizeof(x))
#define memc(x,y) memcpy(x,y,sizeof(y))
#define MAX 8
#define qi queue<pii >
using namespace std;
char x[MAX],y[MAX],z[MAX];
int a[MAX];
void basek(int i,int k,int s)
{
  REP(l,0,s)
  {
    a[l]=i%k;
    i/=k;
  }
}
int occ(int s,int l)
{
  int v=0;
  REP(i,0,s) v+=(strncmp(z+i,y,l)==0);
  return v;
}
int my_pow(int a,int b)
{
  int x=1,y=a;
  while(b)
  {
    if(b%2) x*=y;
    y*=y; b>>=1;
  }
  return x;
}
int main()
{
  int tc; scanf("%d",&tc);
  REP(t,0,tc)
  {
    int k,l,s; scanf("%d %d %d",&k,&l,&s);
    scanf("%s %s",x,y);
    int m=my_pow(k,s),mo=0,so=0;
    REP(i,0,m)
    {
     basek(i,k,s);
     REP(j,0,s) z[j]=x[a[j]];
     z[s]='\0';
     int oc=occ(s,l);
     so+=oc;
     mo=max(mo,oc);
    }
    double eb=(double)so/m;
    printf("Case #%d: %.6lf\n",t+1,mo-eb);
  }
  return 0;
}
