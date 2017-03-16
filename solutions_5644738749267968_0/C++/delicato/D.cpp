#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cassert>
#include <map>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define all(c) (c).begin(), (c).end()


int war(const set<double> &naomi, const set<double> &ken) {
  assert( naomi.size() == ken.size() );
  if (naomi.empty()) return 0;
  
  if ( naomi.size() == 1 ) {
    return (*naomi.begin() > *ken.begin() ? 1: 0);
  }

  // ------------- memoization ----------------
  static map< pair< set<double>, set<double> >, int > memo;
  const pair< set<double>, set<double> > key(naomi, ken);

  {
    auto findIt = memo.find(key);
    if (findIt != memo.end()) {
      return findIt->second;
    }
  }
  // ----------------------------------------

  vector<double> vKen( all(ken) );
  sort( all(vKen) );

  const double minKen = vKen.front();
  const double maxKen = vKen.back();

  int res = 0;

  for (const double d : naomi) {
    set<double> naomi2( naomi );
    naomi2.erase(d);

    if (d > maxKen) {
      set<double> ken2( ken );
      ken2.erase(minKen);

      res = max(res, 1 + war(naomi2, ken2));
    }
    else {
      auto it = ken.upper_bound(d);
      assert(it != ken.end());

      set<double> ken2( ken );
      ken2.erase(*it);
      
      res = max(res, 0 + war(naomi2, ken2));
    }
  }
  

  memo.insert( make_pair(key, res) );
  return res;
}



int deceitfulWar(const set<double> &naomi, const set<double> &ken) {
  assert( naomi.size() == ken.size() );
  if (naomi.empty()) return 0;
  
  if ( naomi.size() == 1 ) {
    return (*naomi.begin() > *ken.begin() ? 1: 0);
  }

  // ------------- memoization ----------------
  static map< pair< set<double>, set<double> >, int > memo;
  const pair< set<double>, set<double> > key(naomi, ken);

  {
    auto findIt = memo.find(key);
    if (findIt != memo.end()) {
      return findIt->second;
    }
  }
  // ----------------------------------------

  vector<double> vKen( all(ken) );
  sort( all(vKen) );

  const double minKen = vKen.front();
  const double maxKen = vKen.back();

  int res;

  // naomi kan antingen lura ken att välja sitt minsta, dvs välja sitt minsta som är större än kens minsta
  {
    set<double> naomi2( naomi );
    set<double> ken2( ken );

    naomi2.erase( *naomi.begin() ); // take naomi's smallest
    ken2.erase(maxKen);             // take ken's biggest

    res = 0 + deceitfulWar(naomi2, ken2);
  }
  
  // eller så väljer naomi sitt minsta och säger att den är strax under ken's största
  auto it = naomi.upper_bound( minKen );
  if (it != naomi.end()) {  // naomi has element bigger than ken's smallest
    set<double> naomi2( naomi );
    set<double> ken2( ken );

    ken2.erase(minKen);    // take ken's smallest
    naomi2.erase( *it );   // take naomi's smallest bigger than ken's smallest

    res = 1 + deceitfulWar(naomi2, ken2);
  }
  

  memo.insert( make_pair(key, res) );
  return res;
}




void solve(const int testcaseIndex) {
  int n;
  cin >> n;

  set<double> naomi;
  set<double> ken;

  rep(i, n) {
    double d;
    cin >> d;
    naomi.insert(d);
  }

  rep(i, n) {
    double d;
    cin >> d;
    ken.insert(d);
  }

  cout << deceitfulWar(naomi, ken) << " " << war(naomi, ken) << endl;
}


int main() {

  int T;
  cin >> T;

  rep(i, T) {
    cout << "Case #" << i + 1 << ": ";
    solve(i);
  }

  return 0;
}
