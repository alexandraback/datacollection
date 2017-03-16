#include <iostream>
#include <cstring>
using namespace std;

int x[1010];

int main() {
    int T;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        int N, A;
        cin >> N;
        memset(x, 0, sizeof(x));
        for (int i = 0; i < N; ++i) {
            cin >> A;
            ++x[A];
        }
        int ans = 1000;
        for (int i = 1; i <= 1000; ++i) {
            int temp = i;
            for (int j = 1; j <= 1000; ++j) {
                if (x[j] == 0) continue;
                temp += x[j] *((j - 1) / i);
            }
            ans = min(ans, temp);
        }
        cout << "Case #" << times << ": " << ans << endl;
    }
    return 0;
}
