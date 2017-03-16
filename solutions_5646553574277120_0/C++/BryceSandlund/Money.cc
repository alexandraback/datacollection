#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
    ll T;
    cin >> T;

    for (ll cs = 1; cs <= T; ++cs) {
        ll C, D, V;
        cin >> C >> D >> V;

        vi nums(D);
        for (ll i = 0; i < D; ++i) {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());

        ll j = 0;
        ll sum = 0;
        ll needed = 0;
        for (ll i = 1; i <= V; ++i) {
            if (j < nums.size() && nums[j] == i) {
                sum += i;
                ++j;
            }
            else if (sum < i) {
                ++needed;
                sum += i;
            }
        }

        printf("Case #%lld: %lld\n", cs, needed);
    }

    return 0;
}
