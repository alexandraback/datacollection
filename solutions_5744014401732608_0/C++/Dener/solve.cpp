#include <bits/stdc++.h>

using namespace std;

void solve(int testnum)
{
    int B;
    long long M;
    cin >> B >> M;
    long long max_number = (1ll << (B - 2));

    cout << "Case #" << testnum + 1 << ": ";
    if (M > max_number) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << "POSSIBLE\n";
    for (int i = 0; i < B; i++) {
        for (int j = 0; j < B; j++) {
            if (i == B-1 and j == B-1) {
                cout << 0;
            } else if (i == B-1) {
                cout << 0;
            } else if (j == B-1) {
                if (i == 0) {
                    if (M == max_number) {
                        cout << 1;
                        M -= 1;
                    } else {
                        cout << 0;
                    }
                } else if (i > 0) {
                    cout << M % 2;
                    M /= 2;
                }
            } else {
                cout << (i >= j ? 0 : 1);
            }
        }
        cout << '\n';
    }
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve(i);
    }
}
