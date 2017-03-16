#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <limits>
#include <climits>
#include <string>
#include <cstring>
#include <list>
#include <functional>
#include <iterator>

using namespace std;

int main(void)
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int C, D, V;
        cin >> C >> D >> V;
        vector<int> existing(D);
        for (int j = 0; j < D; ++j) {
            cin >> existing[j];
        }
        vector<bool> solvable(32, false);
        for (int j = 1; j < (1 << D); ++j) {
            int value = 0;
            for (int k = 0; k < D; ++k) {
                if (j & (1 << k)) {
                    value += existing[k];
                }
            }
            solvable[value] = true;
        }
        int ans = 0;
        for (int j = 1; j <= V; ++j) {
            if (solvable[j]) continue;
            ++ans;
            solvable[j] = true;
            vector<bool> nextSolvable(solvable);
            for (int k = 1; k + j <= V; ++k) {
                if (solvable[k] && k != j) {
                    nextSolvable[k+j] = true;
                }
            }
            solvable.swap(nextSolvable);
        }
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}
