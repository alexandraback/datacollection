#include <iostream>

using namespace std;

int T, N, S, p, a[128];

int gao()
{
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int x;
        switch (a[i] % 3) {
            case 0:
                x = a[i] / 3;
                if (x >= p) ++ans;
                else {
                    x = a[i] / 3 + 1;
                    if (S && x >= p && x >= 2) {
                        ++ans;
                        --S;
                    }
                }
                break;
            case 1:
                x = a[i] / 3 + 1;
                if (x >= p) ++ans;
                else {
                    x = a[i] / 3 + 1;
                    if (S && x >= p && x >= 2) {
                        ++ans;
                        --S;
                    }
                }
                break;
            case 2:
                x = a[i] / 3 + 1;
                if (x >= p) ++ ans;
                else {
                    x = a[i] / 3 + 2;
                    if (S && x >= p && x >= 2) {
                        ++ans;
                        --S;
                    }
                }
                break;
            default:
                break;
        }
    }
    return ans;
}

int main(int argc, const char *argv[])
{
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cin >> N >> S >> p;
        for (int i = 0; i < N; ++i) cin >> a[i];
        cout << "Case #" << cas << ": " << gao() << endl;
    }
    return 0;
}
