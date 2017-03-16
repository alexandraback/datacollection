#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int main() {
    ll T;
    cin >> T;
    for (ll cs = 1; cs <= T; ++cs) {
        ll R, C, W;
        cin >> R >> C >> W;

        ll moves = (C / W) * R;
        
        if (C % W == 0) {
            moves += W-1;
        }
        else {
            moves += W;
        }

        printf("Case #%lld: %lld\n", cs, moves);
    }
    return 0;
}
