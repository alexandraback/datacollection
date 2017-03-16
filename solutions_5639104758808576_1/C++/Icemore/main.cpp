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

int solve() {
    int smax = 0;
    int res = 0;
    int standing = 0;

    cin >> smax;
    for(int k = 0; k <= smax; ++k) {
        char cur;
        cin >> cur;
        cur -= '0';

        if(cur == 0) {
            continue;
        }

        if(standing < k) {
            res += k - standing;
            standing = k;
        }

        standing += cur;
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
