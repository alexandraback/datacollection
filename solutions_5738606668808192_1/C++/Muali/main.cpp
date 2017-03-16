#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

template<class T>
using v = vector<T>;
using ll = long long;

using pii = pair<ll, ll>;

void solve()
{
    ll n, c;
    cin >> n >> c;

    v<v<ll>> ans;
    v<ll> tmp;
    auto check = [&](ll x, ll b)
    {
        for (ll p = 3; p < 20; p += 2)
        {
            ll d = 0;
            ll f = 1;
            for (ll i = 0; i < n; ++i)
            {
                if (x & (1LL << i))
                    d += f;
                f *= b;
                f %= p;
                d %= p;
            }
            if (d % p == 0)
            {
                tmp.push_back(p);
                return;
            }
        }
    };

    ll x = 1;
    x |= (1 << (n - 1));
    vector<string> ans2;
    auto tos = [&](ll x)
    {
        string res;
        for (ll i = 0; i < n; ++i)
        {
            if (x & (1LL << i))
                res = '1' + res;
            else
                res = '0' + res;
        }
        return res;
    };

    while (x < (1 << (n)) && ans.size() < c)
    {
        tmp.clear();
        for (ll i = 2; i < 11; ++i)
        {
            check(x, i);
        }
        if (tmp.size() == 9)
        {
            ans.push_back(tmp);
            ans2.push_back(tos(x));
        }
        x += 2;
    }

    cout << endl;
    for (ll i = 0; i < ans.size(); ++i)
    {
        cout << ans2[i];
        for (ll j = 0; j < 9; ++j)
        {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}