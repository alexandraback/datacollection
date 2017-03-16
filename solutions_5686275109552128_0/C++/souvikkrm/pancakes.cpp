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
#define MAX 1010
using namespace std;
int x[MAX],y[MAX];
int func()
{
  int im=0;
  REP(i,1,MAX) if(y[i]) im=max(im,i);
  if(im<=3) return im;
  int v=im;
  REP(i,2,im+1)
  {
    int l=im/i,r=(im+i-1)/i,q=im%i;
    int oc=y[im];
    y[im]=0;
    y[l]+=oc*(i-q);
    y[r]+=oc*q;
    v=min(v,oc*(i-1)+func());
    y[im]=oc;
    y[l]-=oc*(i-q);
    y[r]-=oc*q;
  }
  return v;
}

int main()
{
  int tc; scanf("%d",&tc);
  REP(t,0,tc)
  {
    int n; scanf("%d",&n);
    REP(i,0,n) scanf("%d",&x[i]);
    REP(i,0,n) y[x[i]]++;
    printf("Case #%d: %d\n",t+1,func());
    mems(y);
  }
  return 0;
}
