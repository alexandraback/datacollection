#include <bits/stdc++.h>

using namespace std;

vector<int> ms;
map<int, pair<int, pair<int, int>>> mp;

void solve(int z)
{
    cout << "Case #" << z << ": ";
    int j, p, s, k;
    cin >> j >> p >> s >> k;
    if (k >= 3)
    {
        cout << j * p * s << '\n';
        for (int ii = 1; ii <= j; ii++)
        {
            for (int jj = 1; jj <= p; jj++)
            {
                for (int kk = 1; kk <= s; kk++)
                {
                    cout << ii << " " << jj << " " << kk << '\n';
                }
            }
        }
        return;
    }
    int res = 0;
    int js[3][3], sp[3][3], jp[3][3];
    for (int ii = 0; ii < (int)ms.size(); ii++)
    {
        memset(js, 0, sizeof(js));
        memset(sp, 0, sizeof(sp));
        memset(jp, 0, sizeof(jp));
        int cmask = ms[ii];
        //cout << __builtin_popcount(cmask) << endl;
        bool bad = false;
        for (int jj = 0; jj < 27; jj++)
        {
            if ((cmask >> jj) & 1)
            {
                auto pp = mp[jj];
                if (pp.first + 1 > j or pp.second.first + 1 > p or pp.second.second + 1 > s)
                {
                    bad = true;
                    break;
                }
                js[pp.first][pp.second.first]++;
                sp[pp.second.first][pp.second.second]++;
                jp[pp.first][pp.second.second]++;
                if (js[pp.first][pp.second.first] > k or sp[pp.second.first][pp.second.second] > k or jp[pp.first][pp.second.second] > k)
                {
                    bad = true;
                    break;
                }
            }
        }
        if (!bad and __builtin_popcount(cmask) > __builtin_popcount(res))
        {
            res = cmask;
        }
    }
    cout << __builtin_popcount(res) << '\n';
    for (int i = 0; i < 27; i++)
    {
        if ((res >> i) & 1)
        {
            auto pp = mp[i];
            cout << pp.first + 1 << " " << pp.second.first + 1 << " " << pp.second.second + 1 << '\n';
            assert(pp.first + 1 <= j and pp.second.second <= p and pp.second.second + 1 <= s);
        }
    }
}

int main()
{
    for (int i = 0; i < (1 << 27); i++)
    {
        if (__builtin_popcount(i) <= 9)
        {
            ms.push_back(i);
        }
    }
    for (int i = 0; i < 27; i++)
    {
        mp[i] = {(i % 3), {(i / 3), (i / 9)}};
    }
    freopen("C-small-attempt6.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
}
