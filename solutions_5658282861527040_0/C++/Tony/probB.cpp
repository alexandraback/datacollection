
#include <iostream>

using namespace std;

int A, B, K;

void solve() {
    cin >> A >> B >> K;
    int cnt = 0;
    for (int a = 0; a < A; a++)
        for (int b = 0; b < B; b++)
            if ((a & b) < K)
                cnt++;
    cout << cnt << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

