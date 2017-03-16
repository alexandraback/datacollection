#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define forn(i, n) for(int i = 0; i < (n); ++i)
#define forv(i, a) forn(i, (int)(a).size())

typedef long long lng;

int d[2000000];

int reverse(int num) {
    int res = 0;
    while(num) {
        res = res * 10 + num % 10;
        num /= 10;
    }
    return res;
}

void precalc() {
    forn(i, 2000000) {
        d[i] = 2000000000;
    }
    d[1] = 1;

    for(int n = 1; n <= 1000000; ++n) {
        d[n+1] = min(d[n+1], d[n] + 1);
        d[reverse(n)] = min(d[reverse(n)], d[n]+1);
    }
}

int solve() {
    int n;

    cin >> n;
    return d[n];
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    precalc();

    int T;
    cin >> T;
    forn(tc, T) {
        auto res = solve();

        std::cout << "Case #" << tc + 1 << ": " << res << endl;
    }
    
    return 0;
}
