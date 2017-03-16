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

int n;
int p[2000];

int solve() {
    cin >> n;
    forn(i, n) {
        cin >> p[i];
    }

    int maxp = *std::max_element(p, p + n);
    int res = INT32_MAX;

    for (int q = 1; q <= maxp; ++q) {
        int cur = q;
        forn(i, n) {
            cur += (p[i] - 1) / q;
        }

        if (cur < res) {
            res = cur;
        }
    }

    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    int T;
    cin >> T;
    forn(tc, T) {
        std::cout << "Case #" << tc + 1 << ": " << solve() << endl;
    }
    
    return 0;
}
