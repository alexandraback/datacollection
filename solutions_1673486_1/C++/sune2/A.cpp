#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

double p[100000];
int main() {
  int T;
  cin >> T;
  REP(t,T) {
    int A, B;
    cin >> A >> B;
    REP(i,A) cin>>p[i];
    // keep typing
    double q = 1;
    REP(i,A) q*=p[i];
    double ans = q*(B-A+1) + (1-q)*(B-A+1 + B+1);
    //cout << q*(B-A+1) + (1-q)*(B-A+1 + B+1) << endl;
    // press backspace
    q = 1;
    for (int i=0; i<A; ++i) {  // A-i times
      int num = A-i + B-i+1;
      // cout << q << " " << num << endl;
      ans = min(ans, q*num + (1-q)*(num+B+1));
      //cout << q*num + (1-q)*(num+B+1) << endl;
      q *= p[i];
    }
    // press enter right away
    ans = min(ans, (double)B+2);
    printf("Case #%d: %.6f\n", t+1, ans);
  }
}
