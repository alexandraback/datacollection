#include <map>
#include <set>
#include <queue>
#include <time.h>
#include <string>
#include <math.h>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
const int inf = 1000000000,
          mod = 1000000007;
#define Wi(a) printf("%d ", (a))
#define Wi2(a, b) printf("%d %d ", (a), (b))
#define Wie(a) printf("%d\n", (a))
#define Wie2(a, b) printf("%d %d\n", (a), (b))
#define Ri(a) scanf("%d", &(a))
#define Ri2(a, b) scanf("%d%d", &(a), &(b))
#define F first
#define S second
#define pii pair < int, int >
#define v(tp) vector< tp >
#define ll long long
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for(int (i) = (a), _n_ = (b); (i) <= _n_; (i)++)
#define FORD(i,a,b) for(int (i) = (a), _n_ = (b); (i) >= _n_; (i)--)
#define forn(i,b) FOR((i),0,(b) - 1)
using namespace std;

ll gcd( ll a, ll b ) {
    return a? gcd( b % a, a ): b;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    Ri( T );

    FOR( nom, 1, T ) {
        ll P, Q;
        char c;
        cin >> P >> c >> Q;
        ll g = gcd( P, Q );
        P /= g;
        Q /= g;
        if( (1LL << 40) % Q != 0 ) {
            cout << "Case #" << nom << ": impossible\n";
            continue;
        }
        ll kol = ((1LL << 40) / Q) * P;
        int k = 0;
        while( kol ) {
            k++;
            kol >>= 1;
        }
        cout << "Case #" << nom << ": " << 40 - k + 1 << "\n";
    }

    return 0;
}
