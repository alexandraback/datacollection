#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

void solve(int testNo) {
    int D;
    cin >> D;
    vector <int> v(D);
    int upperLimit = 0;
    for (int i=0; i < D; ++i) {
        cin >> v[i];
        upperLimit = max(upperLimit, v[i]);
    }

    int minimumTurns = upperLimit;
    for (int maxPileSize=1; maxPileSize <= upperLimit; ++maxPileSize) {
        int specialTurnsRequired = 0;
        for (int i=0; i < D; ++i) {
            if (v[i] > maxPileSize) {
                specialTurnsRequired += (v[i] + maxPileSize - 1) / maxPileSize - 1;
            }
        }
        minimumTurns = min(minimumTurns, maxPileSize + specialTurnsRequired);
    }

    cout << "Case #" << testNo << ": " << minimumTurns << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i=1; i <= T; ++i) {
        solve(i);
    }
    return 0;
}
