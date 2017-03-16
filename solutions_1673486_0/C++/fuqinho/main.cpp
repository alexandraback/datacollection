#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a)  (a).begin(),(a).end()
#define REP(i,n) for(int i=0;i<(n);++i)
const double EPS = 1e-10;
const double PI  = acos(-1.0);
#define dump(x) cerr << "  (L" << __LINE__ << ") " << #x << " = " << (x) << endl;
#define dumpv(x) cerr << "  (L" << __LINE__ << ") " << #x << " = "; REP(q,(x).size()) cerr << (x)[q] << " "; cerr << endl;
template<typename T1, typename T2>
ostream& operator<<(ostream& s, const pair<T1, T2>& d) {return s << "(" << d.first << "," << d.second << ")";}

double solve(int A, int B, vector<double>& P) {
  double E0 = B + 1;
  double e = E0;

  double totalp = 1.0;
  vector<double> et(A);
  REP(i, A) {
    int stroke = i+1;
    totalp *= P[i];
    et[i] = totalp * (B - stroke + 1) + (1-totalp) * (B - stroke + 1 + B + 1);
  }
  REP(i, A) {
    double e1 = e + 1;
    double e2 = E0 + 1;
    e = min(min(e1, e2), et[i]);
  }
  return e;
}

int main() {
  int T; cin >> T;
  REP(t, T) {
    int A, B; cin >> A >> B;
    vector<double> P(A);
    REP(i, A) cin >> P[i];

    double ans = solve(A, B, P);
    printf("Case #%d: %.6f\n", t+1, ans);
    //cout << "Case #" << (t+1) << ": " << ans << endl;
  }
}

