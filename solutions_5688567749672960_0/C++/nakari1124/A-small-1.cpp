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
typedef i64 nkr_int;
typedef pair<i64, i64> pi;

typedef vector<nkr_int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define iter(T) T::iterator
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(s, e, n)  for(n = (s); n < (e); ++n)

class Solver {
public:
  Solver() {}
  ~Solver() {}

  void solve();
};

i64 solve2(i64 N) {
  i64 ans = 0;
  
  if(N > 20) {
    if(N % 10 == 0) {
      ans += 9;
      N -= 9;
    }

    if(N % 10 != 1) {
      i64 d = (N % 10) - 1;
      ans += d;
      N -= d;
    }

    ans += 1;
    N = 10 + (N / 10);
  }

  ans += N;

  return ans;
}

inline i64 atoi2(const string &str) {
  i64 ans = 0;
  i64 i;
  REP(0, sz(str), i) {
    ans *= 10;
    ans += str[i] - '0';
  }
  return ans;
}

void Solver::solve() {

  string N;
  cin >> N;

  i64 ans = 0;
 
  i64 Ni = atoi2(N);
  if(Ni % 10 == 0) {
    Ni -= 1;
    ans += 1;
  }

  char buf[1000];
  sprintf(buf, "%I64d", Ni);
  N.clear();
  N = buf;
  
  if(sz(N) <= 2) {
    ans += solve2(atoi(N.c_str()));
  }
  else{
    string N0, N1;
    N0 = N.substr(0, sz(N)/2);
    N1 = N.substr(sz(N)/2, string::npos);
    reverse(all(N0));
    while(sz(N0) != 1 || sz(N1) != 1) {
      if(atoi(N0.c_str()) != 1) {
	// need flip
	ans += atoi(N0.c_str()) - 1;
	ans += 1;
      }
      
      ans += atoi(N1.c_str()) - 1;
      ans += 2;

      i64 len = sz(N0) + sz(N1) - 1;
      N0.clear(); N0.append(len / 2, '9');
      N1.clear(); N1.append(len - sz(N0), '9');
    }
    
    ans += solve2(atoi((N0 + N1).c_str()));
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

