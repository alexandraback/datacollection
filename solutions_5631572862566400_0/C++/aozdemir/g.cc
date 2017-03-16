#include <iostream>
#include <map>
#include <deque>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        map<int,int> forw;
        cin >> N;
        for (int l = 0; l < N ; ++l){
            int F;
            cin >> F;
            forw[l] = F-1;
        }
        cout << "Case #" << t << ": ";
        int best2c = 0;
        map<int,int> V;
        for (int n = 0; n < N; ++n) V[n] = 0;
        for (int k = 0; k < 2*N; ++k) {
            for (int n = 0; n < N; ++n) {
                if (forw[forw[n]] != n) V[forw[n]] = max(V[forw[n]], V[n] + 1);
            }
        }
        for (int n = 0; n < N; ++n) {
            if (forw[forw[n]] == n && forw[n] != n) {
                // cout << '{' << n << '}';
                best2c = max(best2c, 2 + V[n] + V[forw[n]]);
            }
        }
        int bestBc = 0;
        for (int n = 0; n < N; ++n) {
            int place = n;
            for (int i = 0; i < 2*N; ++i) {
                place = forw[place];
                if (place == n) {
                    bestBc = max(bestBc, i + 1);
                    break;
                }
            }
        }
//         cout << best2c << " ";
//         cout << bestBc << " ";
        cout << max(best2c, bestBc) << endl;
    }
}

