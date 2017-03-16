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

ld F(int N , int k) {
    ld sum = 0 , last = 1 , p = 1 ;
    FOR (i,0,N) p *= 2 ;
    REP (i,0,k) {
        sum += last/p ;
        last = last*(N-i)/(i+1) ;
    }
    return sum ;
}

int main() {
    int T ;
    cin >> T ;
    REP (l,1,T) {
        int N , x , y ;
        cin >> N >> x >> y ;
        x = abs(x) ;
        int p = (x+y)/2 ;
        int sum = 0 ;
        int j ;
        for (j = 0 ; sum <= N ; j += 2)
            sum += 2*j+1 ;
        j -= 2 ;
        j /= 2 ;
        cout << fixed << setprecision(8) ;
        cout << "Case #" << l << ": " ;
        // Solve Correctly ;
//             cerr << endl ;
//             cerr << sum << " " << j << " " << p << endl ;
        if (p > j) {
            cout << (ld)0.0 << endl ;
        } else if (p < j) {
            cout << (ld)1.0 << endl ;
        } else {
            j *= 2 ;
            sum -= 2*j+1 ;
            N -= sum ;
//                 cerr << N << endl ;
            if (N == 0) {
                cout << (ld)0.0 << endl ;
            } else {
                if (N > j) {
                    int diff = N-j ;
                    N -= 2*diff ;
                    j -= diff ;
                    if (x > N) {
                        cout << (ld)1.0 << endl ;
                        continue ;
                    }
                }
                x = N-(j-x) ;
//                     cerr << N << " " << x << endl ;
                cout << F(N,x-1) << endl ;
            }
        }
//             cerr << string(80,'-') << endl ;
    }
    return 0 ;
}
