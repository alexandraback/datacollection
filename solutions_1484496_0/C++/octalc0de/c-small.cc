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

set<int> lookup[2000001];
int T;
int N;
int S[21];

int main() {
  cin >> T;
  rep(t, T) {
    rep(n, 2000001) {
      lookup[n].clear();
    }
    cin >> N;
    rep (n, N) {
      cin >> S[n];
    }

    printf("Case #%d:\n", t+1);
    rep(i, 1<<(N)) {
      if (i == 0) continue;
      int sum = 0;
      set<int> lol;
      rep(j, N) {
        if ( (1 << j) & i ) {
          sum += S[j];
          lol.insert(S[j]);
        }
      }
      if (lookup[sum].size()) {
        for (auto it = lol.begin(); it != lol.end(); ++it) {
          cout << *it << " ";
        }
        cout << endl;

        for (auto it = lookup[sum].begin(); it != lookup[sum].end(); ++it) {
          cout << *it << " ";
        }
        cout << endl;
        goto done;
      } else {
        lookup[sum].insert(lol.begin(), lol.end());
      }
    }

    printf("Impossible\n");
done: 
    ;
  }
}
