#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll T;
    cin >> T;

    for (ll cs = 1; cs <= T; ++cs) {
        string S;
        cin >> S;

        ll switches = 0;
        for (ll i = 1; i < S.size(); ++i) {
            if (S[i-1] != S[i])
                ++switches;
        }

        if (S[S.size()-1] == '-')
            ++switches;

        printf("Case #%lld: %lld\n", cs, switches);
    }
    return 0;
}
