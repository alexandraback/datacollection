#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef vector<bool> vb;

void check(ll N, vb &seen) {
    while (N) {
        seen[N % 10] = true;
        N /= 10;
    }
}

int main() {
    ll T;
    cin >> T;

    for (ll cs = 1; cs <= T; ++cs) {
        ll N;
        cin >> N;

        if (N == 0)
            printf("Case #%lld: INSOMNIA\n", cs);
        else {
            vb seen(10, false);
            
            ll num = 0;

            while (true) {
                num += N;

                check(num, seen);

                bool quit = true;
                for (ll i = 0; i < 10; ++i) {
                    if (!seen[i])
                        quit = false;
                }

                if (quit)
                    break;
            }

            printf("Case #%lld: %lld\n", cs, num);
        }
    }
    return 0;
}
