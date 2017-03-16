#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdio>

#define INF 1000000000

using namespace std;

int main() {
    
    cin.tie(0);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        int D, P[1010];
        cin >> D;
        for (int i = 0; i < D; i++) cin >> P[i];
        int best = INF;
        for (int i = 1; i < 1010; i++) {
            int extra = 0;
            for (int j = 0; j < D; j++) {
                extra += (P[j]-1)/i;
            }
            best = min(best, i + extra);
        }
        cout << "Case #" << tc << ": " << best << endl;
    }

    return 0;
}
