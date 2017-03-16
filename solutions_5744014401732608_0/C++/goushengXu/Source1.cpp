#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int dfs(const vector<vector<int>>& g, int index, int size) {
    if (index == size - 1) return 1;
    int result = 0;
    for (int i = index + 1; i < size; ++i) {
        if (g[index][i]) {
            result += dfs(g, i, size);
        }
    }
    return result;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int B, M; cin >> B >> M;
        vector<vector<int>> g(B, vector<int>(B, 0));

        bool succ = false;
        // build a graph (no circle)
        int ttt = ((1 << B) - 1);
        for (int bit = 1; bit <= ttt; ++bit) {
            // last column
            for (int i = 0; i < (B - 1); ++i) {
                g[i][B - 1] = (bit & (0x01 << i)) > 0 ? 1 : 0;
            }
            // the rest
            int rest = (1 + B - 2)*(B - 2) / 2;
            int total = (1 << rest) - 1;
            for (int mask = 0; mask <= total; ++mask) {
                int index = 0;
                for (int row = 0; row < (B - 2); ++row) {
                    for (int col = row + 1; col < (B - 1); ++col) {
                        g[row][col] = (mask & (0x01 << index)) > 0 ? 1 : 0;
                        ++index;
                    }
                }

                // check # of way from 1 to B
                if (dfs(g, 0, B) == M) {
                    cout << "Case #" << t << ": POSSIBLE" << endl;
                    for (int i = 0; i < B; ++i) {
                        for (int j = 0; j < B; ++j) {
                            cout << g[i][j];
                        }
                        cout << endl;
                    }
                    succ = true; break;
                }
                // clear g
                for (int i = 0; i < B; ++i)
                for (int j = 0; j < B - 1; ++j)
                    g[i][j] = 0;
            }
            if (succ) break;
            for (int i = 0; i < B; ++i) g[i][B - 1] = 0;
        }
        if (!succ) cout << "Case #" << t << ": IMPOSSIBLE" << endl;
        
    }
    return 0;
}
