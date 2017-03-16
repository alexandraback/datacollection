#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, X;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int a = 1; a <= T; ++a) {
        map<int, int> F;
        cin >> N;
        for (int b = 0; b < 2 * N - 1; ++b)
            for (int c = 0; c < N; ++c) {
                cin >> X;
                ++F[X];
            }
        vector<int> V;
        for (auto C: F)
            if (C.second & 1)
                V.push_back(C.first);
        sort(V.begin(), V.end());
        cout << "Case #" << a << ":";
        for (auto E: V)
            cout << " " << E;
        cout << "\n";
    }
    return 0;
}
