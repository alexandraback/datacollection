#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
#define REP(I,N) for(int I=0;I<(N);++I)
#define FOR(I,A,B) for(int I=(A);I<=(B);++I)
#define FORD(I,A,B) for(int I=(A);I>=(B);--I)
#define FOREACH(I,C) for(__typeof((C.begin())) I=(C).begin();I!=(C).end();++I)
#define st first
#define nd second
#define mp make_pair
#define pb push_back

void solve() {
  int a,b;
  const int enter = 1;
  scanf("%d%d",&a,&b);  
  double best = min(enter + b + enter, a + b + enter);
  double p = 1.0;
  FOR(i,1,a) {
    double curp;
    scanf("%le",&curp);
    p *= curp;    
    int cost = a - i + b - i + enter;
    double ex = (p) * cost + (1.0 - p) * (cost + b + enter);
//    printf("%d: %lf (%lf %d %d)\n",i,ex,p,cost,cost + b + enter);
    best = min(best, ex);
  }
  printf("%.9lf\n",best);    		
}

int main() {
	int tests;
	scanf("%d\n",&tests);
	FOR(test,1,tests) {
		printf("Case #%d: ", test);
		solve();
	}
	return 0;
}

















