#include <iostream>
using namespace std;

int main() {
    int T, N;
    cin >> T;
    int cnt[2501];
    for (int ncase = 1; ncase <= T; ++ ncase) {
        memset(cnt, 0, sizeof(cnt));
        cin >> N;
        for (int i = 0; i < N * 2 - 1; ++ i) {
            for (int j = 0; j < N; ++ j) {
                int d;
                cin >> d;
                ++ cnt[d];
            }
        }
        cout << "Case #" << ncase << ":";
        for (int i = 0; i < 2501; ++ i)
            if (cnt[i] % 2 == 1)
                cout << " " << i;
        cout << endl;
    }
    return 0;
}
