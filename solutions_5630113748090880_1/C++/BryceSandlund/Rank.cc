#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
    ll T;
    cin >> T;

    for (ll cs = 1; cs <= T; ++cs) {
        ll N;
        cin >> N;

        vi heights(2600, 0);
        for (ll i = 0; i < N*N*2-N; ++i) {
            ll xi;
            cin >> xi;
            ++heights[xi];
        }

        vi row;
        for (ll i = 0; i < heights.size(); ++i) {
            if (heights[i] % 2 == 1)
                row.push_back(i);
        }

        sort(row.begin(), row.end());
        printf("Case #%lld:", cs);

        for (ll i = 0; i < N; ++i) {
            cout << " " << row[i];
        }

        cout << endl;
    }
    return 0;
}
