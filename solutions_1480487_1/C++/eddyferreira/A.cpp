#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>

#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FORZ(i,b) FOR(i,0,(b))
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )
using namespace std;

template <class T> void out( T a, T b ) { bool first = true; for( T i = a; i != b; ++ i ) { if( !first ) printf( " " ); first = false; cout << * i; } printf( "\n" ); }
template <class T> void outl( T a, T b ) { for( T i = a; i != b; ++ i ) { cout << * i << "\n"; } }
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;

int N, X;
int s[200];

bool good(int i, double x) {
  double score = s[i] + x*X;
  double c = 1 - x;
  FOR(j,0,N) {
    if (j == i) continue;
    double cj = max((score - s[j])/X, 0.0);
    if (cj > c) return true;
    c -= cj;
  }
  return false;
}

int main() {
  int tt;
  cin >> tt;
  cout.precision(10);
  FOR(t,1,tt+1) {
    printf("Case #%d:", t);
    
    cin >> N;
    X = 0;
    FOR(i,0,N) {
      cin >> s[i];
      X += s[i];
    }
    FOR(i,0,N) {
      double lo = 0, hi = 1;
      while (hi - lo > 1e-10) {
        double mid = (hi+lo)/2;
        if (good(i,mid)) {
          hi = mid;
        } else {
          lo = mid;
        }
      }
      printf(" %.7f", 100*hi);
    }
    putchar('\n');
  }
  return 0;
}
