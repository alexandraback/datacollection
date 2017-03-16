#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <valarray>
#include <vector>
#include <ext/algorithm>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/numeric>
using namespace std;
using namespace __gnu_cxx;

#define F(i,a,b)for(int i=a;i<b;++i)
#define rep(i,n)F(i,0,n)
#define all(a)a.begin(),a.end()
template<class T>vector<T>&operator<<(vector<T>& v,T t){v.push_back(t);return v;} 
int s[201];
int N;
int T;
int X;


bool ok(int idx, double val) {
  double score = val * X + s[idx];
  double reqVotes = val;
  rep(n, N) {
    if (n == idx) continue;
    // vote such that reqVote * X + s[n] = score
    double reqVote = ((double)(score - s[n])) / X;
    if (reqVote < 0) continue;
    reqVotes += reqVote;
  }
  return reqVotes > 1.0;
}

int main() {
  cin >> T;
  rep(t, T) {
    X = 0;
    cin >> N;
    rep(n, N) {
      cin >> s[n];
      X += s[n];
    }
    printf("Case #%d: ", t+1);
    rep(n, N) {
      double mn = 0.0;
      double mx = 1.0;
      while (mx - mn > 1e-12) {
        double q = mn + mx;
        q *= .5;
        if (ok(n, q)) {
          mx = q;
        } else {
          mn = q;
        }
      }
      printf("%.12g ", (mx+mn)*50);
    }
    printf("\n");
  }
}
