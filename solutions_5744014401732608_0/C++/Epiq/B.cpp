#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define pb push_back(x)
#define mp make_pair
//#define DEBUG
#ifdef DEBUG
#define debug(x) cerr << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif


#define PROBLEM_NAME "B"

int main(){
    ios_base::sync_with_stdio(false);

    freopen(PROBLEM_NAME".test.in", "r", stdin);
    freopen(PROBLEM_NAME".test.out", "w", stdout);

    ll T;
    cin >> T;

    for (int test = 1; test <= T; test++) {
        ll b, n;
        cin >> b >> n;
        cout << "Case #" << test << ": ";

        if ((1LL << (b - 2)) < n) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << "POSSIBLE" << endl;
debug(n);
            ll p = 1;
            int i = 0;
            while ((p << 1LL) <= n) {
                p <<= 1LL;
                i++;
            }

            debug(p);

            // connect last p + 1 nodes
            char grid[50][50 + 1];
            memset(grid, '0', sizeof(grid));
            for (int z = 0; z < b; z++) grid[z][b] = 0;
            for (int z = 1; z < b; z++) {
                for (int j = z + 1; j < b; j++) {
                    grid[z][j] = '1';
                }
            }

            // special case
            if (n == (1LL << (b - 2))) {
                grid[0][b - 1] = '1';
                n--;
            }

            while (i >= 0) {
                if ((1LL << i) & n) {
                    grid[0][b - 2 - i] = '1';
                    #ifdef DEBUG
                    cout << "> " << i << "  " << b - 2 - i << endl;
                    #endif
                }
                i--;
            }

            for (int z = 0; z < b; z++) {
                cout << grid[z] << endl;
            }
        }
    }

    return 0;
}
