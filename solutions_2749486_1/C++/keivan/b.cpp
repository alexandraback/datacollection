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

const string ch = "NESW" ;
const int go[4][2] = { {0,1} , {1,0} , {0,-1} , {-1,0} } ;

int T ;

bool IsIn (int x , int y , int N) {
    return abs(x)+abs(y) <= N*(N+1)/2 && (abs(x+y)%2 == (N*(N+1)/2)%2) ;
}

bool IsIn (pii a , int N) {
    return IsIn(a.X,a.Y,N) ;
}

pii Go(int x , int y , int dir ,int num) {
    return pii(x-go[dir][0]*num,y-go[dir][1]*num) ;
}

int main() {
    cin >> T ;
    REP (lv,1,T) {
        int x , y ;
        cin >> x >> y ;
        int N = 0 ;
        while (!IsIn(x,y,N) ) {
            ++N ;
        }
        string ans = "" ;
        REP (i,1,N) {
            FOR (j,0,4) {
                pii nxt = Go(x,y,j,N-i+1) ;
                if (IsIn(nxt,N-i)) {
                    x = nxt.X , y = nxt.Y ;
                    ans += ch[j] ;
                    break ;
                }
            }
        }
        reverse (all(ans)) ;
        cout << "Case #" << lv << ": " << ans << endl ;
    }
    return 0 ;
}
