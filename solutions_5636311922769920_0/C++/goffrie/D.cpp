#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

void tc() {
    ull K, C, S;
    cin >> K >> C >> S;

    static int cas = 1;
    cout << "Case #" << cas++ << ":";

    if (S * C < K) {
        cout << " IMPOSSIBLE" << endl;
        return;
    }

    for (ull i = 0; i < S; ++i) {
        ull l = i;
        ull r = 0;
        for (ull j = 0; j < C; ++j) {
            r = r*K + l;
            l = (l + S) % K;
        }

        cout << ' ' << r+1;
    }
    cout << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) tc();
}
