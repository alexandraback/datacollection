//Tadrion
#include <cstdio>
#include <vector>
#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define CLEAR(x) (memset(x,0,sizeof(x)))
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define VAR(v, n) __typeof(n) v = (n)
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define FOREACH(i, c) for(VAR(i,(c).begin()); i != (c).end(); ++i)
#define DBG(v) cout<<#v<<" = "<<v<<endl;
#define IN(x,y) ((y).find(x)!=(y).end())
#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
int T;
int M,N;

int a[110][110];
int row[110],col[110];
int ok;
int main() {
  scanf("%d",&T);
  FOR(tttt,1,T) {
    ok=1;
    scanf("%d %d",&N,&M);
    CLEAR(row); CLEAR(col);
    FOR(i,1,N) FOR(j,1,M) scanf("%d",&a[i][j]);
    FOR(i,1,N) FOR(j,1,M) {col[j] = MAX(col[j],a[i][j]); row[i] = MAX(row[i],a[i][j]);}
    FOR(i,1,N) FOR(j,1,M) if(a[i][j] < col[j] && a[i][j] < row[i]) ok=0;
    printf("Case #%d: %s\n",tttt,ok ? "YES" : "NO");
  }
  return 0;
}
