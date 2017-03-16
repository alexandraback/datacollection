#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <stack>
using namespace std;
#define V vector
#define tD typedef
tD long long ll;
tD V<int> vi;
tD V<vi> vii;
tD V<ll> vll;
tD V<string> vs;
tD long double ld;
tD pair<int, int> pii;
#define prr make_pair
#define fr(x,y) for(int x=0;x<(y); ++x)
#define fi(n) fr(i,n)
#define fj(n) fr(j,n)
#define fk(n) fr(k,n)
#define pb push_back
#define sz size()
#define DEBUG 0

int N;
vi friends;

int largest() {
  int best = 0;
  fi(1<<N) {
    vi ppl;
    fj(N) {
      if ((1<<j)&i) {
	ppl.pb(j);
      }
    }
    if (ppl.sz < 2) continue;
    do {
      bool works = true;
      fj(ppl.sz) {
	int before = j - 1; if (before < 0) before = ppl.sz - 1;
	int after = (j + 1) % ppl.sz;
	if (friends[ppl[j]] == ppl[before] ||
	    friends[ppl[j]] == ppl[after]) {
	} else {
	  works = false;
	  break;
	}
      }
      if (works) best = max(best, int(ppl.sz));
    } while (next_permutation(ppl.begin(), ppl.end()));
  }
  return best;
}


int main() {
  int T; cin >> T;
  for (int qw = 1; qw <= T; qw++) {
    cin >> N;
    friends = vi();
    fi(N) { int a; cin >> a; friends.pb(a-1); }
    cout << "Case #" << qw << ": " << largest() << endl;
  }
}
