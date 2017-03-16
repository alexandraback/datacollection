#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<pair<string, string> > V;
vector<pair<int, int> > adjList[20]; // Node, Type
string F, E;
int T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int a = 1; a <= T; ++a) {
        cin >> N;
        V.clear();
        for (int b = 0; b < N; ++b) {
            adjList[b].clear();
            cin >> F >> E;
            V.emplace_back(F, E);
        }
        for (int b = 0; b < N; ++b) {
            for (int c = 0; c < b; ++c) {
                if (V[b].first == V[c].first) {
                    adjList[b].emplace_back(c, 0);
                    adjList[c].emplace_back(b, 0);
                }
                if (V[b].second == V[c].second) {
                    adjList[b].emplace_back(c, 1);
                    adjList[c].emplace_back(b, 1);
                }
            }
        }
        int maxi = 0;
        for (int b = 1; b < (1 << N); ++b) {
            bool can = true;
            for (int c = 0; c < N; ++c) {
                if (b & (1 << c)) { // This node marked
                    bool has0 = false;
                    bool has1 = false;
                    for (auto e: adjList[c]) {
                        if (e.second) {
                            has1 |= !(b & (1 << e.first));
                        } else {
                            has0 |= !(b & (1 << e.first));
                        }
                    }
                    can &= has0 & has1;
                }
            }
            if (can) {
                maxi = max(maxi, __builtin_popcount(b));
            }
        }
        cout << "Case #" << a << ": " << maxi << "\n";
    }
    return 0;
}
