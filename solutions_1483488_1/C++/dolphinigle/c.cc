// Authored by dolphinigle
// Codeforces #115
// 14 April 2012
// Author: Gerald, undef, ashmelev

#include <vector>
#include <list>
#include <map>
#include <set>

#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <assert.h>

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))

#define SZ(Z) ((int)(Z).size())
#define ALL(W) W.begin(), W.end()
#define PB push_back

#define MP make_pair
#define A first
#define B second

#define INF 1023123123
#define EPS 1e-11

#define MX(Z,Y) Z = max((Z),(Y))
#define MN(X,Y) X = min((X),(Y))

#define FORIT(X,Y) for(typeof((Y).begin()) X = (Y).begin();X!=(Y).end();X++)

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vint;

vector< pair<int,int> > rec;

vector<ll> GetDigits(ll number) {
  if (number == 0LL) return vector<ll>(0);
  vector<ll> ret;
  while (number) {
    ret.PB(number%10LL);
    number /= 10LL;
  }
  reverse(ALL(ret));
  return ret;
}
//GetDigits(123) = {1,2,3}

int main() {
  
  REP(i, 1, 2000001) {
    // if (i % 1000 == 0) cout << i << endl;
    vector<ll> v = GetDigits(i);
    FORN(j, SZ(v)) {
      rotate(v.begin(), v.begin()+1, v.end());
      int no = 0;
      FORN(j, SZ(v)) {
        no *= 10;
        no += v[j];
      }
      if (SZ(GetDigits(no)) == SZ(v) && no > i) rec.PB(MP(i, no));
    }
    
  }
  
  sort(ALL(rec));
  rec.erase(unique(ALL(rec)), rec.end());
  
  int ntc;
  cin >> ntc;
  
  FORN(itc, ntc) {
    cout << "Case #" << (itc+1) << ": ";
    
    int a, b;
    cin >> a >> b;
    int ret = 0;
    FORN(i, SZ(rec)) if (rec[i].A >= a && rec[i].B <= b) {
      ++ret;
    }
    cout << ret << endl;
  }
  
}
