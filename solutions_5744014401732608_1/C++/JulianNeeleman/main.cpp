#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <iomanip>

using namespace std;

int64_t power(int64_t b, int64_t e) {
    if(e == 0) return (int64_t)1;
    return b * power(b, e - (int64_t)1);
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        int64_t B, M;
        cin >> B >> M;
        int64_t m = power(2, B - 2);
        if(m < M) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        cout << "POSSIBLE" << endl;
        vector<vector<bool> > g(B, vector<bool> (B, true));
        for(int i = 0; i < B; i++) for(int j = 0; j <= i; j++) g[i][j] = false;

        while(m > M) {
            int64_t diff = m - M, e = 0;
            while(power(2, e + 1) <= diff) e++;
            g[0][B - 2 - e] = false;
            m -= power(2, e);
        }

        for(int i = 0; i < B; i++) {
            for(int j = 0; j < B; j++) {
                cout << g[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
