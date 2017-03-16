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
#define MAX 5
#define MAX_V 30
using namespace std;
int x[MAX],y[MAX],v[2][MAX_V+1];
int main()
{
  int tc; scanf("%d",&tc);
  REP(t,0,tc)
  {
    int c,d,n; scanf("%d %d %d",&c,&d,&n);
    REP(i,0,d) 
    {
      scanf("%d",&x[i]);
      y[x[i]]=1;
    }
    v[0][0]=1;
    REP(i,0,d) 
    {
      REP(j,0,n+1) v[1][j]=v[0][j] || (j>=x[i] && v[0][j-x[i]]);
      REP(j,0,n+1) { v[0][j]=v[1][j]; v[1][j]=0; }
    }
    int ans=0;
    REP(i,1,n+1)
    {
      int f=1;
      REP(j,1,n+1) if(!v[0][j]) { f=0; break; }
      if(f) break;
      if(!y[i])
      {
        ans++;
        REP(j,1,n+1) v[1][j]=v[0][j] || (j>=i && v[0][j-i]);
        REP(j,1,n+1) { v[0][j]=v[1][j]; v[1][j]=0; }
      }
    }
    printf("Case #%d: %d\n",t+1,ans);
    mems(y);
    mems(v);
  }
  return 0;
} 
