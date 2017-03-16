#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <functional>
#include <cstdint>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <sstream>

#define D(x) 

using namespace std;

int main() {
    int numCases;
    cin >> numCases;

    for (int testCase = 1; testCase <= numCases; testCase++) {
        int R, C, W;
        cin >> R >> C >> W;

        vector<int> f(C+1), g(C+1);

        f[W] = W;
        g[W] = 1;
        D(cerr << "f[" << W << "] == " << W << endl);

        for (int i = W+1; i <= C; i++) {
            int best_nohit = i, best = i;
            for (int pos = 0; pos < i; pos++) {
                int worst_nohit;
                // brother says miss
                worst_nohit = 1+max(f[pos]+g[i-pos-1], g[pos]+f[i-pos-1]);

                int worst = worst_nohit;
                // brother says hit
                if (pos == 0 || pos == i-1) {
                    worst = max(worst, W);
                } else {
                    worst = max(worst, W+1);
                }
                D(cerr << "  pos " << pos << ": " << worst << " (" << worst_nohit << " if no hit)" << endl);

                best_nohit = min(best_nohit, worst_nohit);
                best = min(best, worst);
            }
            f[i] = best;
            g[i] = best_nohit;

            D(cerr << "f[" << i << "] == " << f[i] << endl);
            D(cerr << "g[" << i << "] == " << g[i] << endl);
        }

        int result = (R-1)*g[C] + f[C];
        cout << "Case #" << testCase << ": " << result << endl;
    }
}
