//mishraiiit
#include<bits/stdc++.h>
#define ll long long int
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
typedef pair <ll, ll> pll;

#ifdef TRACE
  #include "trace.h"
#else
  #define trace1(x)
  #define trace2(x, y)
  #define trace3(x, y, z)
  #define trace4(a, b, c, d)
  #define trace5(a, b, c, d, e)
  #define trace6(a, b, c, d, e, f)
  #define myassert(a, b)
#endif

int main() {
    fastScan;

    ll t;
    cin >> t;
    for(int ii = 1; ii <= t; ii++) {
      ll b, m;
      cin >> b >> m;
      cout << "Case #" << ii << ": ";
      ll max_ways = 1LL << (b - 2LL);
      vector < vector < ll > > matrix (b, vector<ll> (b, 0));
      for(int i = 0; i < b; i++) {
        for(int j = i + 1; j < b; j++) {
          matrix[i][j] = 1;
        }
      }
      if(m > max_ways) {
        cout << "IMPOSSIBLE" << endl;
      } else {
        cout << "POSSIBLE" << endl;
        ll diff = max_ways - m;
        for(ll i = 0; i < 55; i++) {
          if((diff & (1LL << i))) {
            matrix[i + 1][b - 1] = 0;
          }
        }
        for(int i = 0; i < b; i++) {
          for(int j = 0; j < b; j++) {
            cout << matrix[i][j];;
          }
          cout << endl;
        }
      }
    }

    return 0;
}

