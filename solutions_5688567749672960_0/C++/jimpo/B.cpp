#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <memory>

typedef long long ll;

using namespace std;

ll reverse_number(ll n) {
    string val = to_string(n);
    reverse(val.begin(), val.end());
    return stoll(val);
}

ll solve(ll N) {
    map<ll, ll> pi;
    priority_queue<pair<ll, ll> > q;
    nodes.insert(pair<ll, ll>(1, 1));
    while (!q.empty()) {
        pair<ll, ll> p = q.top();
        q.pop();
        ll n = p.second;
        ll dist = -p.first;
        if (pi.find(n) == pi.end()) {
            if (n == N) {
                return dist;
            }

            pi[n] = dist;
            ll next;

            next = n + 1;
            if (next == N) {
                return dist + 1;
            }
            if (pi.find(next) == pi.end()) {
                nodes.insert(pair<ll, ll>(dist + 1, next));
            }

            next = reverse_number(n);
            if (next == N) {
                return dist + 1;
            }
            if (pi.find(next) == pi.end()) {
                nodes.insert(pair<ll, ll>(dist + 1, next));
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        ll N;
        cin >> N;
        cout << "Case #" << i + 1 << ": " << solve(N) << endl;
    }
}
