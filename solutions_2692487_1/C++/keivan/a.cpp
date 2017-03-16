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
 
using namespace std;
 
#define FOREACH(i, c) for(__typeof( (c).begin() ) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for(__typeof(n) i = (a); i<(n); ++i)
#define REP(i, a, n) for(__typeof(n) i = (a); i<=(n); ++i)
#define ROF(i, n, a) for(__typeof(n) i = (n); i>=(a); --i)
#define error(n) cout << #n << " = " << n << endl
#define all(c) c.begin(), c.end()
#define pb push_back
#define po pop_back
#define Size(n) ((int)(n).size())
#define X first
#define Y second
int _ ;
#define scanf _ = scanf
// #define X real()
// #define Y imag()

typedef long long   ll ;
typedef long double ld ;
typedef pair<int,int> pii ;

const int MAXN = 111 ;
const int INF = 1111 * 1000 ;

int A , N ;
int a[MAXN] ;

int main() {
    int T ;
    cin >> T ;
    REP (l,1,T) {
        cin >> A >> N ;
        FOR (i,0,N)
            cin >> a[i] ;
        sort (a,a+N) ;
        int ans = N , bigmote = A ,x = 0 ;
        for (int i = 0 ; i < N ; ++i) {
            while (i < N && a[i] < bigmote) {
                bigmote += a[i] ;
                ++i ;
            }
            ans = min(ans,x+N-i) ;
            //
            if (bigmote == 1) break ;
            bigmote = min(INF,bigmote*2-1) ;
            ++x ;
            --i ;
        }
        cout << "Case #" << l << ": " << ans << endl ;
    }
    return 0 ;
}
