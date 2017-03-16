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
#define MAX 21
using namespace std;
int x[MAX][MAX][MAX];
char y[][10]={"RICHARD","GABRIEL"};
int main()
{
  REP(i,1,MAX) REP(j,1,MAX) REP(k,1,MAX)
  {
    int m=min(j,k);
    int d=(j%i==0 || k%i==0);
    x[i][j][k]=(d && m>=i-1);
  }
  int tc; scanf("%d",&tc);
  REP(t,0,tc)
  {
    int k,r,c; scanf("%d %d %d\n",&k,&r,&c);
    printf("Case #%d: %s\n",t+1,y[x[k][r][c]]);
  }
  return 0;
}
