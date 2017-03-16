#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

typedef array<int, 200> keyc;
typedef array<int, 20> soln;

vector<int> ckeys;
vector<keyc> chests;
keyc init;
array<soln, (1<<20)> dp;
bitset<(1<<20)> solvable;

inline int popcount(int a) { return __builtin_popcount(a); }

int canOpen(int chest, int state) {
    int key = ckeys[chest];
    int c = init[key];
    for (int i = 0; i < 20; ++i) if ((1<<i) & state) c += chests[i][key];
    return c >= 1;
}

int main() {
    int T;
    cin >> T;
    for (int C = 1; C <= T; ++C) {
        cout << "Case #" << C << ':';
        fill(init.begin(), init.end(), 0);
        int n, k;
        cin >> k >> n;
        ckeys.resize(n);
        chests.resize(n);
        for (int i = 0; i < k; ++i) {
            int key;
            cin >> key;
            ++init[key-1];
        }
        for (int i = 0; i < n; ++i) {
            cin >> ckeys[i];
            --ckeys[i];
            int nk;
            cin >> nk;
            fill(chests[i].begin(), chests[i].end(), 0);
            chests[i][ckeys[i]] = -1;
            for (int j = 0; j < nk; ++j) {
                int key;
                cin >> key;
                ++chests[i][key-1];
            }
        }
        solvable.reset();
        solvable.set(0);
        for (int state = 1; state < (1<<n); ++state) {
            for (int c = 0; c < n; ++c) if (state & (1<<c)) {
                int prev = state ^ (1<<c);
                if (solvable.test(prev) && canOpen(c, prev)) {
                    soln newSolution = dp[prev];
                    int popcnt = popcount(prev);
                    newSolution[popcnt] = c;
                    ++popcnt;
                    if (!solvable.test(state) || lexicographical_compare(newSolution.begin(), newSolution.begin()+popcnt, dp[state].begin(), dp[state].begin() + popcnt)) {
                        dp[state] = newSolution;
                        solvable.set(state);
                    }
                }
            }
        }
        if (solvable.test((1<<n)-1)) {
            for (int i = 0; i < n; ++i) {
                cout << ' ' << dp[(1<<n)-1][i] + 1;
            }
            cout << endl;
        } else {
            cout << " IMPOSSIBLE" << endl;
        }
    }
}
