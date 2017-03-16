#pragma comment(linker,"/STACK:100000000000,100000000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
#include <functional>
#include <list>
#include <sstream>
#include <ctime>
#include <climits>
#include <bitset>
#include <list>
#include <cassert>
#include <complex>

using namespace std;

/* Constants begin */
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-7;
const double PI = 2*acos(0.0);
const double E = 2.71828;
/* Constants end */

/* Defines begin */
#define pb push_back
#define mp make_pair
#define ll long long
#define double long double
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define forn(i,n) for (int (i)=0; (i)<(n); ++(i))
#define random (rand()<<16|rand())
#define sqr(x) (x)*(x)
#define base complex<double>
/* Defines end */

ll f[45][2][2][2];

int x[105], y[105], z[105];

void Solve(){
  ll a, b, c; cin >> a >> b >> c;
  int s1 = 0, s2 = 0, s3 = 0;
  forn(i, 40) x[i] = y[i] = z[i] = 0;
  memset(f, 0, sizeof f);
  while(a){
    x[s1++] = a & 1LL;
    a >>= 1LL;
  }
  while(b){
    y[s2++] = b & 1LL;
    b >>= 1LL;
  }
  while(c){
    z[s3++] = c & 1LL;
    c >>= 1LL;
  }
  int sz = max(s1, s2);
  sz = max(sz, s3);
  reverse(x, x + sz);
  reverse(y, y + sz);
  reverse(z, z + sz);
  f[0][0][0][0] = 1;
  for(int i = 0; i < sz; ++i){
    for(int w = 0; w < 2; ++w){
      for(int q = 0; q < 2; ++q){
        for(int e = 0; e < 2; ++e){
          if(!f[i][w][q][e]) continue;
          for(int b1 = 0; b1 < 2; ++b1){
            for(int b2 = 0; b2 < 2; ++b2){
              int b3 = b1 & b2;
              if(b1 > x[i] && !w) continue;
              if(b2 > y[i] && !q) continue;
              if(b3 > z[i] && !e) continue;
              f[i + 1][w | (b1 < x[i])][q | (b2 < y[i])][e | (b3 < z[i])] += f[i][w][q][e];
            }
          }
        }
      }
    }
  }
  cout << f[sz][1][1][1] << "\n";
}

int main(void){
  #ifdef nobik
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  forn(i, t){
    cout << "Case #" << i + 1 << ": ";
    Solve();
  }
  return 0;
}
