#include <bits/stdc++.h>

using namespace std;

const int MX_SZ = 20;

inline bool get_bit(int mask, int pos)
{
    return (mask >> pos) & 1;
}

void solve(int z)
{
    cout << "Case #" << z << ": ";
    int n;
    cin >> n;
    int cnt[2] = {1, 1};
    map<string, int> mp[2];
    int a[MX_SZ], b[MX_SZ];
    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s >> t;
        if (mp[0].find(s) == mp[0].end())
        {
            mp[0][s] = cnt[0];
            cnt[0]++;
        }
        if (mp[1].find(t) == mp[1].end())
        {
            mp[1][t] = cnt[1];
            cnt[1]++;
        }
        a[i] = mp[0][s];
        b[i] = mp[1][t];
    }
    /*
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " " << b[i] << endl;
    }
    */
    bool used[MX_SZ][2];
    bool real_[MX_SZ];
    int res = 0;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int cres = n;
        memset(used, false, sizeof(used));
        memset(real_, false, sizeof(real_));
        for (int i = 0; i < n; i++)
        {
            if (get_bit(mask, i))
            {
                used[a[i]][0] = true;
                used[b[i]][1] = true;
                real_[i] = true;
                cres--;
            }
        }
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            if (!real_[i] and (!used[a[i]][0] or !used[b[i]][1]))
            {
                ok = false;
                break;
            }
        }
        if (ok and res < cres)
        {
            res = cres;
        }
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
}
