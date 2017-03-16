#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

ll cycle_length(ll u, vi &BFF, vi &visited, ll count) {
    if (visited[u] != -1)
        return count - visited[u];
    visited[u] = count;
    return cycle_length(BFF[u], BFF, visited, count+1);
}

ll longest_path(ll u, vvi &BFF_inv, ll avoid) {
    ll best = 0;
    for (ll i = 0; i < BFF_inv[u].size(); ++i) {
        if (BFF_inv[u][i] == avoid)
            continue;

        best = max(best, longest_path(BFF_inv[u][i], BFF_inv, avoid));
    }
    return best + 1;
}

int main() {
    ll T;
    cin >> T;

    for (ll cs = 1; cs <= T; ++cs) {
        ll N;
        cin >> N;

        vi BFF(N);
        for (ll i = 0; i < N; ++i) {
            cin >> BFF[i];
            BFF[i]--;
        }

        ll longest_cycle = 0;
        for (ll i = 0; i < N; ++i) {
            vi visited(N, -1);
            longest_cycle = max(longest_cycle, cycle_length(i, BFF, visited, 0));
        }

        vvi BFF_inv(N);
        for (ll i = 0; i < N; ++i) {
            BFF_inv[BFF[i]].push_back(i);
        }

        ll longest_paths = 0;
        for (ll i = 0; i < N; ++i) {
            if (BFF[BFF[i]] == i) {
                longest_paths += longest_path(i, BFF_inv, BFF[i]);
                longest_paths += longest_path(BFF[i], BFF_inv, i);
            }
        }

        ll ans = max(longest_cycle, longest_paths/2);
        printf("Case #%lld: %lld\n", cs, ans);
    }
    return 0;
}
