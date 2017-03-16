#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define DEBUG(x) cout << ">>> " << #x << " : " << x << endl
#define MP make_pair
#define PB push_back
#define REP(i,b) for ( int i = 0; i < int(b); ++i )
#define FOR(i,a,b) for ( int i = int(a); i <= int(b); ++i )
#define FORD(i,a,b) for ( int i = int(a); i >= int(b); --i )
#define RI(a) scanf("%d", &a)
#define RII(a,b) scanf("%d%d", &a, &b)
#define RIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define RIIII(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define MM(x,b) memset( x, b, sizeof( x ) )
const int INF = 1<<29;
typedef long long ll;

int main( ) {
  ll caseCnt, a, b, k;
  cin >> caseCnt;
  FOR( caseNr, 1, caseCnt ) {
    cin >> a >> b >> k;
    if ( b > a )
      swap( a, b );
    if ( b <= k ) {
      cout << "Case #" << caseNr << ": " << a * b << endl;
      continue;
    }
    ll cnt = a * k;
    REP( A, a )
      FOR( B, k, b-1 )
        if ( (A & B) < k )
          ++cnt;
    // ll cnt = 0;
    // REP( A, a ) {
    //   int res = 0;
    //   REP( B, b ) {
    //     if ( (A & B) < k) {
    //       ++cnt;
    //       ++res;
    //     }
    //   }
    //   cout << A << " " << res << endl;
    // }
    cout << "Case #" << caseNr << ": " << cnt << endl;
  }

  return 0;
}
