#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <stack>
#include <queue>
#include <cstring>
#include <assert.h>
using namespace std;

typedef long long LL;
#define REP(i,e) for (int (i) = 0; (i) < (e); ++(i))
#define foreach(__my_iterator,__my_object) for (typeof((__my_object).begin()) __my_iterator = (__my_object).begin(); __my_iterator!= (__my_object).end(); __my_iterator++)

double J[210];
double SUM;
const int ITERN = 500;
void solve(int N){
  double lo,hi;

  REP(i, N){
    lo = 0.0;
    hi = 1.0;
    REP(iter, ITERN){
      double mid = (lo + hi) / 2.0;
      double cur = J[i] + mid * SUM;
      double tot = 1.0 - mid;
      bool ok = true;
      REP(j, N){
	if(j==i) continue;
	if(J[j] >= cur) continue;
	double tmp = (cur - J[j]) / SUM;
	if(tmp > tot){
	  ok = false;
	  break;
	}
	tot -= tmp;
      }

      if(ok) lo = mid;
      else hi = mid;
      //      printf("%lf %lf \n", lo, hi);
    }
    printf("%lf ", lo*100.0);
  }
}


int main(){
  int T,N;
  cin >> T; 

  REP(i, T){
    cin >> N;
    SUM = 0.0;
    REP(j, N){
      cin >> J[j];
      SUM += J[j];
    }
    printf("Case #%d: ", i+1);
    solve(N);
    printf("\n");
  }

  return 0;
}
/*
echo "4
2 20 10
2 10 0
4 25 25 25 25
3 24 30 21" | ./a.out
*/
