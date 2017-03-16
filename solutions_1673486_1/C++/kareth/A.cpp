#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#define INF 2000000000
#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define PI pair<int, int>
#define ST first
#define ND second
#define CLR(a, b) memset(a, b, sizeof(a))
#ifdef DEBUG
  #define DBG printf
#else
  #define DBG 
#endif
using namespace std;

int main(){
  int d, a, b;
  double x;
  scanf("%d",&d);
  int casenum = 0;
  while(d--){
    casenum++;
    scanf("%d %d",&a, &b);
    double best = b + 2;
    double last = 1;
    double res;
    REP(i, a){
      res = 0;
      scanf("%lf",&x);
      last *= x;
      res += last * ((a - i - 1) * 2 + b - a + 1);
      res += (1.0 - last) * ((a - i - 1) * 2 + b - a + 1 + b + 1);
      best = min( best, res);
    }
    printf("Case #%d: %lf\n", casenum, best);
  }

  return 0;
}
