#include <assert.h>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string>
#include <list>
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <list>
#define INF 0x3fffffff
#define LINF 0x3fffffffffffffffll
#define DINF 1e100
#define EPS 0.000000000001

typedef long long ll;
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define PIL pair<int, ll>
#define PLI pair<ll, int>
#define PID pair<int, double>
#define PDI pair<double, int>
#define PLD pair<ll, double>
#define PDL pair<double, ll>

#define NUL(x) memset(x, 0, sizeof(x))
#define MINUS(x) memset(x, 0xff, sizeof(x))
#define PQ(x) priority_queue< x >  //highest first
#define PQR(x) priority_queue< x , vector< x > , greater < x > > //lowest first
#define MP make_pair
#define PB push_back
#define IT(x) for (typeof((x).begin()) it = (x).begin() ; it != (x).end() ; it++)
#define IT2(x) for (typeof((x).begin()) it2 = (x).begin() ; it2 != (x).end() ; it2++)
#define FOR(i, a, b) for (int i = (a) ; i< (b) ; i++)
#define DEB(x...) fprintf(stderr,x)
//#define DEB

using namespace std;
#define MAXN 1005
list<int> adjlist[MAXN];
bool testc(int tc=0)
{
  int N,M,a,e = 0;
  scanf("%i ", &N);
  FOR(i,0,N) {
    scanf("%i ", &M);
    adjlist[i].clear();
    FOR(j,0,M) {
      scanf("%i ", &a);
      e++;
      a--;
      adjlist[i].PB(a);
    }
  }

  FOR(i,0,N) {
    vector<bool> visit(N, false);
    queue<int> q;
    q.push(i);
    visit[i] = true;
    while(!q.empty()) {
      int cur = q.front(); q.pop();
      IT(adjlist[cur])
        if (visit[*it]) {
          printf("Case #%i: Yes\n", tc);
          return true;
        } else {
          visit[*it] = true;
          q.push(*it);
        }
    }
  }
  printf("Case #%i: No\n", tc);
}


int main()
{
  int t;
  scanf("%i ",&t);
  FOR(i,0,t)
    testc(i+1);

  /*
    while(testc());
  */
  
  return 0;
}
