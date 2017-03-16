#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


int main() {
    int tc; cin >> tc;
    for (int _ = 1; _ <= tc; ++_) {
        int A, B, K;
        cin >> A >> B >> K;
        int ans = 0;
        for (int i = 0; i < A; ++i) {
            for (int j = 0; j < B; ++j) {
                int res = i & j;
                if (res < K) {
                    ++ans;
                }
            }
        }
        cout << "Case #" << _ << ": " << ans << endl;
    }
    return 0;
}
