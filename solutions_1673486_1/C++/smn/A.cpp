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
#include <cstring>
using namespace std;

typedef long long LL;
#define REP(i,e) for (int (i) = 0; (i) < (e); ++(i))
#define foreach(__my_iterator,__my_object) for (typeof((__my_object).begin()) __my_iterator = (__my_object).begin(); __my_iterator!= (__my_object).end(); __my_iterator++)


double P[100000];
void solve(int A, int B){
  double ans = 2.0 + B;

  double suc = 1.0;
  for(int i=1;i<=A;i++){
    suc *= P[i-1];
    int need = 2.0*(A-i) + (B - A) + 1;
    ans = min(ans, suc*need + (1.0-suc)*(need + B + 1) );
  }

  printf("%lf\n", ans);
}
int main(){
  int T,A,B;
  cin >> T;
  REP(i, T){
    cin >> A >> B;
    REP(j, A){
      cin >> P[j];
    }
    printf("Case #%d: ", i+1);
    solve(A, B);
  }

  return 0;
}
/*

 */
