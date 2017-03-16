// BEGIN CUT HERE
// headers begin
// END CUT HERE
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <utility>
#include <vector>
// BEGIN CUT HERE
// headers end
// END CUT HERE

using namespace std;

// BEGIN CUT HERE 
// helper functions begin
// END CUT HERE
#define repeat(n) for ( int repc = (n); repc > 0; --repc )
// BEGIN CUT HERE 
// helper functions end
template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }
template<> ostream& operator<<( ostream &os, const vector<string> &v ) { os << "{"; for ( vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }
template<typename T, typename U> ostream& operator<<( ostream &os, const pair<T, U> &P ) { return os << "(" << P.first << ", " << P.second << ")"; }
template<typename T> ostream& operator<<( ostream &os, const set<T> &S ) { return os << vector<T>( S.begin(), S.end() ); }
template<typename T, typename U> ostream& operator<<( ostream &os, const map<T, U> &M ) { for ( typename map<T, U>::const_iterator mi=M.begin(); mi!=M.end(); ++mi ) { os << mi->first << " => " << mi->second << endl; } return os; }
// END CUT HERE

double solve(const vector<int> &pts, const int pos) {
  int n = (int)pts.size();
  const int X = accumulate(pts.begin(), pts.end(), 0);
  double lo = 0, hi = 1;
  repeat (100) {
    double mid = (lo + hi) / 2;
    double target_score = pts[pos] + X * mid;
    double left = 1.0;
    for (int i=0; i<n; ++i) {
      left -= max(0.0, target_score - pts[i]) / X;
    }
    if (left > 0) lo = mid;
    else hi = mid;
  }
  return lo;
}

int main() {
  cin.sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    int N;
    cin >> N;
    vector<int> pts(N);
    for (int i=0; i<N; ++i) {
      cin >> pts[i];
    }

    printf("Case #%d:", tt);
    for (int i=0; i<N; ++i) {
      printf(" %.6f", 100 * solve(pts, i));
    }
    puts("");
  }
  
  return 0;
}
