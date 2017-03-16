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
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

int T;
int N;
int a;
vector<int> g[1010];
int paths[1010][1010];
int M;

void dfs(int s,int fath) {
  if(s!=fath)
    paths[s][fath]++;
  for(int i = 0; i < SZ(g[s]); i++) {
    dfs(g[s][i],fath);
  }
}

int main() {
  scanf("%d",&T);
  
  FOR(tttt,1,T) {
    for(int i = 0; i <= 1000; i++) {
      CLEAR(paths[i]);
      g[i].clear();
    }
  
    scanf("%d",&N);
    for(int i = 1; i <= N; i++) {
      scanf("%d",&M);
      for(int j = 1; j<=M; j++) {
	scanf("%d",&a);
	g[i].PB(a);
      }
    }
    int ok=0;
    for(int i = 1; i <= N; i++) {
      dfs(i,i);
    }
    for(int i = 1; i <= N; i++)
      for(int j = 1; j <= N; j++) {
	if(paths[i][j] >= 2) {ok=1;}
      }
    printf("Case #%d: ",tttt);
    if(ok) printf("Yes\n");
    else printf("No\n");
  }
  
  return 0;
}
