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

const int MAXN = 1000 * 1000 + 10 ;

int T ;
int best[MAXN] ;
int last[MAXN] ;

bool Vowel(char x) {
    return (int)string("aeiou").find(x) != -1 ;
}

int main() {
    cin >> T ;
    REP (lv,1,T) {
        string s ; int n;
        cin >> s >> n ;
        int L = Size(s) ; 
        ll ans = 0 ;
        memset (last,0,sizeof(last)) ;
        memset (best,0,sizeof(best)) ;
        best[L] = L ;
        ROF (i,L-1,0) {
            best[i] = best[i+1] ;
            last[i] = ((!Vowel(s[i])?last[i+1]+1:0)) ;
            if (last[i] >= n)
                best[i] = i+n-1 ;
            ans += L-best[i] ;
//             cerr << last[i] << " " << best[i] << endl ;
        }
        cout << "Case #" << lv << ": " << ans << endl ;
//         cerr << endl ;
    }
    return 0 ;
}
