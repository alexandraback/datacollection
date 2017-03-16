#include <iostream>
#include <vector>

using namespace std;

#define all(a) begin(a),end(a)
#define sz(a) ((int)((a).size()))

typedef long long ll;

void solve_case(int case_id);

int main() {
    int num_case;
    cin >> num_case;
    for (int i=1; i<=num_case; i++)
        solve_case(i);
    return 0;
}

void solve_case(int case_id) {
    ll orig_len; // k
    ll complexity; // c = number of iterations
    ll num_check; // s
    cin >> orig_len >> complexity >> num_check;
    cout << "Case #" << case_id << ":";
    if (num_check * complexity < orig_len) {
        cout << " IMPOSSIBLE\n";
        return;
    }
    vector<ll> to_check;
    for (ll i=0; i<orig_len; i++)
        to_check.push_back(i);
    while (sz(to_check) % complexity != 0)
        to_check.push_back(0);
    ll curr_code = 0;
    int num_encoded = 0;
    for (ll x: to_check) {
        curr_code = curr_code * orig_len + x;
        num_encoded++;
        if (num_encoded == complexity) {
            cout << ' ' << (curr_code + 1);
            curr_code = 0;
            num_encoded = 0;
        }
    }
    cout << '\n';
}
