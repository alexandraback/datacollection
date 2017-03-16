#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

template <typename T> inline T set_bit(const T &x, int index) {
  return x | ((T)1 << index);
}
#define repeat(n) for ( int repc = (n); repc > 0; --repc )
template <typename T> inline int get_bit(const T &x, int index) {
  return (int)((x >> index) & 1);
}
#define foreach(i,c) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i )
#define ZERO(v) memset(v, 0, sizeof v)
#define MINUSONE(v) memset(v, -1, sizeof v)

const int MAXN = 20;

int N;
int nkeys[201];
int needs[MAXN];
vector<int> provides[MAXN];
signed char memo[1<<MAXN];

int rek(int state) {
  if (state == (1<<N)-1) {
    return 1;
  }
  signed char &ret = memo[state];
  if (ret != -1) {
    return ret;
  }

  ret = -2;
  for (int i=0; i<N; ++i) {
    if (get_bit(state, i) ||
        nkeys[needs[i]] == 0) {
      continue;
    }
    --nkeys[needs[i]];
    foreach (it, provides[i]) ++nkeys[*it];
    int nstate = set_bit(state, i);
    bool can = rek(nstate) >= 0;
    foreach (it, provides[i]) --nkeys[*it];
    ++nkeys[needs[i]];
    if (can) {
      ret = i;
      break;
    }
  }
  return ret;
}

int main() {
  cin.sync_with_stdio(0);

  int T; cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    cout << "Case #" << tt << ":";

    int K;
    cin >> K >> N;
    assert(N <= MAXN);
    ZERO(nkeys);
    repeat (K) {
      int x;
      cin >> x;
      ++nkeys[x];
    }

    for (int i=0; i<N; ++i) {
      cin >> needs[i];
      int K;
      cin >> K;
      provides[i].resize(K);
      for (int j=0; j<K; ++j) {
        cin >> provides[i][j];
      }
    }

    MINUSONE(memo);
    rek(0);
    int state = 0;
    if (rek(state) < 0) {
      cout << " IMPOSSIBLE\n";
      continue;
    }

    repeat (N) {
      int next = rek(state);
      cout << ' ' << next+1;
      state = set_bit(state, next);
    }
    cout << '\n';
  }
  
  return 0;
}
