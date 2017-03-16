#include <iostream>
using namespace std;

long long T, B, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> B >> M;
        if (M > (1LL << (B - 2))) {
            cout << "Case #" << tc << ": IMPOSSIBLE\n";
        } else {
            cout << "Case #" << tc << ": POSSIBLE\n";
            bool MAT[55][55] = {{0}};
            for (int a = 1; a < B; ++a) { // For each level
                // Connect to everything above it
                for (int b = a + 1; b < B; ++b)
                    MAT[a][b] = true;
            }
            if (M == 1LL << (B - 2)) {
                // Take everything
                for (int a = 1; a < B; ++a)
                    MAT[a][B] = true;
            } else
                for (int a = 0; a < B - 2; ++a) {
                    if (M & (1LL << a)) { // Take this building
                        MAT[a + 2][B] = true;
                        M ^= (1LL << a);
                    }
                }
            for (int a = 1; a <= B; ++a) {
                for (int b = 1; b <= B; ++b)
                    cout << MAT[a][b];
                cout << "\n";
            }
        }
    }
    return 0;
}
