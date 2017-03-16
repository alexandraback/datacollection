#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N;
int BFF[15];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int a = 1; a <= T; ++a) {
        cin >> N;
        for (int b = 1; b <= N; ++b)
            cin >> BFF[b];
        int maxi = 0;
        for (int x = 1; x < (1 << N); ++x) {
            vector<int> V;
            for (int b = 0; b < N; ++b)
                if (x & (1 << b))
                    V.push_back(b + 1);
            do {
                bool can = true;
                int cur = 0;
                for (int a = 0; a < (int)V.size(); ++a) {
                    can &= (BFF[V[a]] == V[(a - 1 + V.size()) % V.size()]) || (BFF[V[a]] == V[(a + 1) % V.size()]);
                    if (!can) break;
                }
                if (can) maxi = max(maxi, (int)V.size());
            } while (next_permutation(V.begin(), V.end()));
        }
        cout << "Case #" << a << ": " << maxi << "\n";
    }
    return 0;
}
