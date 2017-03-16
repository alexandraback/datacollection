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

typedef pair<i64, i64> pi;
typedef pair<pi, pi> attack;
// day strength west east

void Solver::solve() {
  i64 N;
  cin >> N;

  vi d(N), n(N), w(N), e(N), s(N), dd(N), dp(N), ds(N);
  i64 i, j;
  i64 na = 0;
  REP(0, N, i) {
    cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i] >> ds[i];
    na += n[i];
  }

  vector<attack> attacks(na);
  i64 ia = 0;
  REP(0, N, i) {
    attack at;
    at.first.first = d[i];
    at.first.second = s[i];
    at.second.first = w[i];
    at.second.second = e[i];
    REP(0, n[i], j) {
      if(s[i] <= 0) {
	break;
      }

      attacks[ia] = at;
      ++ia;
      
      at.first.first += dd[i];
      at.first.second += ds[i];
      at.second.first += dp[i];
      at.second.second += dp[i];
    }
  }

  sort(all(attacks));

  const i64 MAX_X = 250;
  const i64 OFFSET = MAX_X;
  const i64 WALL_SIZE = MAX_X * 2 + 1;
  vi wall(WALL_SIZE, 0);

  i64 result = 0;
  vector<attack>::iterator atk0 = attacks.begin();
  while(atk0 != attacks.end()) {
    vector<attack>::iterator atk = atk0;
    int day = atk0->first.first;
    while(atk != attacks.end() && atk->first.first == day) {
      for(i64 s = atk->second.first; s < atk->second.second; ++s) {
	if(wall[s + OFFSET] < atk->first.second) {
	  result++;
	  break;
	}
      }
      atk++;
    }

    atk = atk0;
    while(atk != attacks.end() && atk->first.first == day) {
      for(i64 s = atk->second.first; s < atk->second.second; ++s) {
	if(wall[s + OFFSET] < atk->first.second) {
	  wall[s + OFFSET] = atk->first.second;
	}
      }
      atk++;
    }

    atk0 = atk;
  }

  cout << result;
  cout << endl;
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
