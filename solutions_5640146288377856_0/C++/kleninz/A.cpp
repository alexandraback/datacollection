#include <bits/stdc++.h>
#define INF 2e9
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < n; i++)

using namespace std;

typedef long long ll; 

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tests;

    cin >> tests;

    for (int it = 0; it < tests; it++) {
        int r, c, w;
        cin >> r >> c >> w;
        int C = c;
        int m = (c / w) * r; 
        if (c % w == 0) {
            m += w - 1;
        } else {
            m += w;
        }
        cout << "Case #" << it + 1 << ": " << m << endl;
    }

    return 0;
}
