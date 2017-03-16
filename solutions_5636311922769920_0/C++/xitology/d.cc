
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t ++) {
        int K, C, S;
        cin >> K >> C >> S;

        vector<uint64_t> tiles;

        if (S*C >= K) {
            int k = 0;
            while (k < K) {
                uint64_t n = 0;
                for (int c = 0; c < C; c ++) {
                    n = n*K + min(k, K-1);
                    k ++;
                }
                tiles.push_back(n);
            }
        }

        cout << "Case #" << (t+1) << ":";
        if (tiles.empty()) {
            cout << "IMPOSSIBLE";
        }
        else {
            for (const auto& t : tiles) {
                cout << ' ' << (t+1);
            }
        }
        cout << '\n';
    }
}

