#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve(int)
{
    string a, b;
    cin >> a >> b;
    string a_sol, b_sol, as, ab, bs, bb;

    vector<ll> diff_min(a.size() + 1), a_max(a.size() + 1), a_min(a.size() + 1), b_max(a.size() + 1), b_min(a.size() + 1);

    ll x = 1;
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i] == '?') {
            a_max[i] = a_max[i + 1] + 9 * x;
            a_min[i] = a_min[i + 1];
        } else {
            int n = a[i] - '0';
            a_max[i] = a_max[i + 1] + n * x;
            a_min[i] = a_min[i + 1] + n * x;
        }

        if (b[i] == '?') {
            b_max[i] = b_max[i + 1] + 9 * x;
            b_min[i] = b_min[i + 1];
        } else {
            int n = b[i] - '0';
            b_max[i] = b_max[i + 1] + n * x;
            b_min[i] = b_min[i + 1] + n * x;
        }

        x *= 10;
    }

    string zeroes = "000000000000000000000000000000000000000000000000000000";
    as = to_string(a_min[0]);
    as = zeroes.substr(0, a.size() - as.size()) + as;
    ab = to_string(a_max[0]);
    ab = zeroes.substr(0, a.size() - ab.size()) + ab;
    bs = to_string(b_min[0]);
    bs = zeroes.substr(0, a.size() - bs.size()) + bs;
    bb = to_string(b_max[0]);
    bb = zeroes.substr(0, a.size() - bb.size()) + bb;

    x = 1;
    for (int i = a.size() - 1; i >= 0; --i) {
        ll a_smaller = - a_max[i + 1] + b_min[i + 1];
        ll b_smaller = - b_max[i + 1] + a_min[i + 1];
        ll same = diff_min[i + 1];
        ll& l = diff_min[i];
        char ca = a[i], cb = b[i];

        vector<tuple<ll, string, string>> p; // diff, a_sol, b_sol

        if (ca == '?' || cb == '?' || ca == cb) {
            // same
            char c = ca != '?' ? ca : (cb != '?' ? cb : '0');
            p.push_back(make_tuple(same, c + a_sol, c + b_sol));
        }

        if (cb != '0' && ca != '9' && (ca == '?' || cb == '?' || ca < cb)) {
            // a smaller
            char cca = ca != '?' ? ca : (cb != '?' ? cb - 1 : '0');
            char ccb = cb != '?' ? cb : (cca + 1);
            p.push_back(make_tuple((ccb - cca) * x + a_smaller, cca + ab.substr(i + 1), ccb + bs.substr(i + 1)));
        }

        if (ca != '0' && cb != '9' && (ca == '?' || cb == '?' || cb < ca)) {
            // b smaller
            char ccb = cb != '?' ? cb : (ca != '?' ? ca - 1 : '0');
            char cca = ca != '?' ? ca : (ccb + 1);
            p.push_back(make_tuple((cca - ccb) * x + b_smaller, cca + as.substr(i + 1), ccb + bb.substr(i + 1)));
        }

        assert(p.size());

        sort(p.begin(), p.end());

        tie(l, a_sol, b_sol) = p[0];

        x *= 10;
    }

    cout << a_sol << " " << b_sol << endl;
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve(i);
    }
}
