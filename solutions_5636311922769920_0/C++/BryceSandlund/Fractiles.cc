#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll T;
    cin >> T;

    for (ll cs = 1; cs <= T; ++cs) {
        ll K, C, S;
        cin >> K >> C >> S;

        if ((C == 1 && S < K) || S < (K+1)/2) {
            printf("Case #%lld: IMPOSSIBLE\n", cs);
        }
        else {
            if (C == 1) {
                printf("Case #%lld:", cs);
                for (ll i = 1; i <= K; ++i) {
                    cout << " " << i;
                }
                cout << endl;
            }
            else {
                printf("Case #%lld:", cs);
                for (ll i = 0; i < K/2; ++i) {
                    ll ans = 2*K*i + (i+1)*2;
                    cout << " " << ans;
                }

                if (K % 2 == 1)
                    cout << " " << K;

                cout << endl;
            }
        }
    }
    return 0;
}
