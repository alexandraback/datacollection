#include <bits/stdc++.h>

using namespace std;

template<class T>
using v = vector<T>;
using ll = long long;

using pii = pair<ll, ll>;

void solve()
{
    ll k, c, s;
    cin >> k >> c >> s;
    --c;
    vector<ll> ps;
    function<void(ll, ll, ll)> foo = [&](ll pos, ll cur, ll mx)
    {
        if (cur > mx)
        {
            ps.push_back(pos + 1);
            return;
        }
        pos += cur >= k ? 0LL : cur;
        if (cur < mx) pos *= k;
        foo(pos, cur + 1, mx);
    };

    for (int i = 0; i < k; i += c + 1)
    {
        foo(0, i, i + c);
    }

    if (ps.size() <= s)
    {
        for (auto p: ps)
            cout << p << " ";
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}