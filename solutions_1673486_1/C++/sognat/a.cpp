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

const int MAXN = 100000;

int A, B;
double result;

int main() {
  int Z;
  scanf("%d", &Z);
  FOR (T,1,Z) {
    scanf("%d%d", &A, &B);
    result = B + 2;

    double prob = 1;
    double x, y;
    int bck;

    bck = A;
    y = bck + B + 1;
    result = min(result, y);

    FOR (i,1,A) {
      scanf("%lf", &x);
      prob *= x;
      bck = A-i;
      y =  (prob*(bck+bck+1+B-A)) + ((1-prob)*(bck+bck+2+B+B-A));
      //printf("BCK %d: %lf\n", i, y);
      result = min(result, y);
    }

    printf("Case #%d: ", T);
    printf("%.6lf\n", result);
  }
  return 0;
}
