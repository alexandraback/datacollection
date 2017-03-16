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

  // optimalt att spela ut i storleksordning?
  int res2 = 0;
  set<double> ken2( ken );

  for (const double d : naomi) {
    auto it = ken2.upper_bound(d);
    
    if (it == ken2.end()) {
      ken2.erase(ken2.begin());
      ++res2;
    }
    else {
      ken2.erase(it);
    }
  }
  
  return res2;
}



int deceitfulWar(const set<double> &naomi, const set<double> &ken) {
  assert( naomi.size() == ken.size() );
  if (naomi.empty()) return 0;
  
  if ( naomi.size() == 1 ) {
    return (*naomi.begin() > *ken.begin() ? 1: 0);
  }

  int res = 0;
  set<double> naomi2(naomi);
  set<double> ken2(ken);
    
  while (!naomi2.empty()) {
    assert(!ken2.empty());

    const double smallKen = *ken2.begin();
    auto it = naomi2.upper_bound(smallKen);
    
    // kan inte vinna
    if (it == naomi2.end()) {
      naomi2.erase(naomi2.begin()); // spela ut minsta
      ken2.erase(--ken2.end());     // spela ut största (lur)
    }
    else {
      ken2.erase(ken2.begin());   // spela ut minsta
      naomi2.erase(it);          // spela ut lagom stort (lur)
      res += 1;
    }
  }

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
