
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

using lli = long long int ;
template <class T> T get() { T x ; cin >> x ; return x ; }
template <class T> lli size(T const& c) { return c.size() ; }
#define rep0(i,n) for (lli i = 0; i < lli(n); ++i)
#define rep1(i,n) for (lli i = 1; i <= lli(n); ++i)
#define rep rep0
#define fromto(i,a,b) for (lli i = a; i <= lli(b); ++i)
#define show(x) #x " = " << x
#define all(c) (c).begin(), (c).end()
#define print(e) cout << e << endl ;

int main() {
    int T;
    cin >> T;
    rep (test,T) {
        cout << "Case #" << test+1 << ": ";
        lli P, Q; char c;
        cin >> P >> c >> Q;
        int LP = log(P)/log(2), LQ = log(Q)/log(2);
        if (LQ > 40 || (1 << LQ) != Q) {
            cout << "impossible" << endl;
            continue;
        }
        cout << LQ-LP << endl;
    }
}
