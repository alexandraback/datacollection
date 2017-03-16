#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

int TC, K, N, type[20], tab[1 << 20];
vi start_keys, get_keys[20];

void init() {
  cin >> K >> N;
  start_keys.clear();
  FOR(i, 0, K) {
    int k;
    cin >> k;
    start_keys.push_back(k);
  }
  FOR(i, 0, N) {
    int n;
    cin >> type[i] >> n;
    get_keys[i].clear();
    FOR(j, 0, n) {
      int k;
      cin >> k;
      get_keys[i].push_back(k);
    }
  }
  memset(tab, -1, sizeof(tab));
}

int rek(int mask) {
  if (mask == (1 << N) - 1) return 0;
  int &res = tab[mask];
  if (res != -1) return res;
  map<int, int> keys;
  FOR(i, 0, sz(start_keys)) keys[start_keys[i]]++;
  FOR(i, 0, N) {
    if (mask & (1 << i)) {
      keys[type[i]]--;
      FOR(j, 0, sz(get_keys[i])) keys[get_keys[i][j]]++;
    }
  }
  FOR(i, 0, N) {
    if (mask & (1 << i)) continue;
    if (keys[type[i]] > 0) {
      int v = rek(mask + (1 << i));
      if (v != N) return res = i;
    }
  }
  return res = N;
}

int main() {
  cin >> TC;
  FOR(cs, 1, TC+1) {
    init();
    cout << "Case #" << cs << ":";
    if (rek(0) == N) {
      cout << " IMPOSSIBLE" << endl;
    } else {
      int mask = 0;
      FOR(i, 0, N) {
        int nxt = rek(mask);
        cout << " " << nxt+1;
        mask += (1 << nxt);
      }
      cout << endl;
    }
  }
	return 0;
}
