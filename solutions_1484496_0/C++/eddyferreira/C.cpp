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

int N;
int S[500];

int main() {
  int tt;
  cin >> tt;
  FOR(t,1,tt+1) {
    printf("Case #%d:\n", t);
    cin >> N;
    FOR(i,0,N) cin >> S[i];
    map<int,int> sums;
    bool possible = false;
    FOR(i,0,1<<N) {
      int sum = 0;
      FOR(j,0,N) {
        if (i & (1 << j)) sum += S[j];
      }
      if (sums.count(sum)) {
        int other = sums[sum];
        int inter = other & i;
        other ^= inter;
        i ^= inter;
        bool first = true;
        FOR(j,0,N) {
          if (i & (1 << j)) {
            if (!first) cout << " ";
            first = false;
            cout << S[j];
          }
        }
        cout << endl;
        first = true;
        FOR(j,0,N) {
          if (other & (1 << j)) {
            if (!first) cout << " ";
            first = false;
            cout << S[j];
          }
        }
        cout << endl;
        possible = true;
        break;
      }
      sums[sum] = i;
    }
    if (!possible) cout << "Impossible" << endl;
  }
  return 0;
}
