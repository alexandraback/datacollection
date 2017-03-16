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
using namespace std;
int x[5][5][5];
char y[][10]={"RICHARD","GABRIEL"};
int main()
{
  REP(i,1,5) REP(j,1,5)
  {
    x[1][i][j]=1;
    x[2][i][j]=(i%2==0 || j%2==0);
  }
  REP(i,1,5) REP(j,1,5)
  {
    int m=min(i,j);
    int k=(i==3 || j==3);
    x[3][i][j]=(k && m>=2);
  }
  REP(i,1,5) REP(j,1,5)
  {
    int m=min(i,j);
    int k=(i==4 || j==4);
    x[4][i][j]=(k && m>=3);
  }
  int tc; scanf("%d",&tc);
  REP(t,0,tc)
  {
    int k,r,c; scanf("%d %d %d\n",&k,&r,&c);
    printf("Case #%d: %s\n",t+1,y[x[k][r][c]]);
  }
  return 0;
}
