#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int T, K, C, S; cin >> T;
    for(int tt = 1; tt <= T; tt++){
        cin >> K >> C >> S; C--;
        printf("Case #%d: ", tt);
        ll sum = 1, kpow = 1;
        for(int i = 0; i < C; i++){
            kpow *= K;
            sum += kpow;
        }
        for(int i = 1; i <= K; i++) printf("%I64d ", 1 + sum*(i - 1));
        printf("\n");
    }
    return 0;
}

