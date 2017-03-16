#define DEBUG 0
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int INF = 2000000001;
#define PQ priority_queue
#define FOR(x,b,e) for(int x=(b);x<=(e);++x)
#define FORD(x,b,e) for(int x=(b);x>=(e);--x)
#define REP(x,n) for(int x=0;x<(n);++x)
#define ALL(c) c.begin(),c.end()
#define VAR(x,c) __typeof(c) x=(c)
#define FOREACH(x,c) for(VAR(x,(c).begin());x!=(c).end();++x)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define dbg(...) \
  do { if (DEBUG) fprintf(stderr, __VA_ARGS__); } while (0)
const int MAXN = 1000;

int N;
int state[MAXN+1];
PII req[MAXN+1];
int result, stars;

struct cmp2 { bool operator()(const int a, const int b) const { return req[a].ND > req[b].ND; } };
struct cmp11 { bool operator()(const int a, const int b) const { return req[a].ND > req[b].ND; } };
struct cmp1 { bool operator()(const int a, const int b) const {
  PII X = MP(req[a].ST, -req[a].ND);
  PII Y = MP(req[b].ST, -req[b].ND);
  return X > Y;
} };

PQ<int,VI,cmp2> S2;
PQ<int,VI,cmp11> S11;
PQ<int,VI,cmp1> S1;

int main() {
  int T;
  scanf("%d", &T);
  FOR (Z,1,T) {

    result = stars = 0;
    while (! S1.empty()) { S1.pop(); }
    while (! S11.empty()) { S11.pop(); }
    while (! S2.empty()) { S2.pop(); }

    scanf("%d", &N);

    int a, b;
    FOR (i,1,N) {
      state[i] = 0;
      scanf("%d%d", &a, &b);
      req[i] = MP(a,b);
      S1.push(i);
      S2.push(i);
    }
    bool changes = true;

    while (changes) {
      changes = false;
      if (! S2.empty() && req[S2.top()].ND <= stars) {
        int i = S2.top(); S2.pop();
        if (state[i] < 2) {
          result++;
          stars += 2-state[i];
          state[i] = 2;
          dbg("odwiedzam lvl %d z %d gwiazdek\n", i, 2);
        }
        changes = true;
      } else if (! S11.empty() && req[S11.top()].ND <= stars) {
        int i = S11.top(); S11.pop();
        if (state[i] < 2) {
          result++;
          stars += 2-state[i];
          state[i] = 2;
          dbg("odwiedzam lvl %d z %d gwiazdek\n", i, 2);
        }
        changes = true;
      } else if (! S1.empty() && req[S1.top()].ST <= stars) {
        int i = S1.top(); S1.pop();
        if (state[i] < 1) {
          result++;
          stars += 1-state[i];
          state[i] = 1;
            S11.push(i);
        }
        dbg("odwiedzam lvl %d z %d gwiazdek\n", i, 1);
        changes = true;
      }
    }


    bool flag = true;
    FOR (i,1,N) {
      if (state[i] != 2) { flag = false; break; }
    }

    printf("Case #%d: ", Z);
    if (flag) { printf("%d\n", result); }
    else { printf("Too Bad\n"); }
  }
  return 0;
}
