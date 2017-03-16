#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <iterator>
#include <utility>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VP;
typedef map<int, int> MII;

int canon(int v) {
  VI digs;
  while (v) {
    digs.push_back(v % 10); v /= 10;
    }
  sort(digs.begin(), digs.end());
  for (VI::const_iterator i = digs.begin(); i != digs.end(); ++i)
    v = 10*v + *i;
  return v;
  }

void allSetsR(int n, int m, MII &ret, int cur=0, int k=0) {
  if (k == n)
    ++ret[canon(cur)];
  else for (int d = 2; d <= m; ++d)
    allSetsR(n, m, ret, 10*cur+d, k+1);
  }

MII allSets(int n, int m) {
  MII ret;
  allSetsR(n, m, ret);
  return ret;
  }

int ssProd(const VI &digs, int mask) {
  int ret = 1;
  for (int i = 0; (1 << i) <= mask; ++i)
    if (mask & (1 << i))
      ret *= digs[i];
  return ret;
  }

int score(int k, const VI &prods, int v) {
  VI digs;
  while (v) {
    digs.push_back(v % 10); v /= 10;
    }
  int n = digs.size();
  MII pCount;
  for (int i = 0; i < (1 << n); ++i)
    ++pCount[ssProd(digs, i)];

  int ret = 1;
  for (int i = 0; i < k; ++i)
    if (!pCount.count(prods[i])) return -1;
    else ret *= pCount[prods[i]];

  return ret;
  }

int main() {
  int nc; cin >> nc;
  for (int cur = 1; cur <= nc; ++cur) {
    cout << "Case #" << cur << ":\n";

    int r, n, m, k; cin >> r >> n >> m >> k;

    MII universe = allSets(n, m);
    while (r--) {
      VI prods(k);
      for (int i = 0; i < k; ++i)
        cin >> prods[i];

      int best = 222, bestS = -1;
      for (MII::const_iterator i = universe.begin(); i != universe.end(); ++i) {
        int tS = score(k, prods, i->first) * i->second;
        if (tS > bestS)
          best = i->first;
        }

      cout << best << '\n';
      }
    }
  }

