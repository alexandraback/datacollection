#include <utility>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef long long i64;
typedef unsigned long long ui64;

typedef i64 nkr_int;

typedef pair<i64, i64> pi;

typedef vector<nkr_int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define iter(T) T::iterator
#define sz(a) i64((a).size())
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(std::identity<decltype((c).begin())>::type i = (c).begin(); i != (c).end(); ++i)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(s, e, n)  for(n = (s); n < (e); ++n)

class Solver {
public:
  Solver() {}
  ~Solver() {}

  void solve();
};

void Solver::solve() {
	ui64 A, B, K;
	cin >> A >> B >> K;
	if(B > A) {
		swap(A, B);
	}
	
	ui64 ans = 0;
	// K >= A >= B
	ui64 a, b;
	REP(0, A, a) {
		REP(0, B, b) {
			ui64 test = a & b;
			if(test < K) {
				++ans;
			}
		}
	}
	cout << ans << endl;
}

int main(int argc, char *argv[]){

  i64 N;
  cin >> N;
  i64 n;

  Solver s;

  REP(0, N, n) {
    cout << "Case #" << n + 1 << ": ";

    s.solve();
  }

  return 0;
}

