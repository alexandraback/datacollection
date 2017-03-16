#include <bits/stdc++.h>

using namespace std;

const int INF = 1e+9 + 42;

vector<string> a[2];

void gen(int pos, string s, string res, int k)
{
    if (pos == (int)s.size())
    {
        a[k].push_back(res);
        return;
    }
    if (s[pos] == '?')
    {
        string t;
        for (int i = 0; i < 10; i++)
        {
            t = res;
            t += (char)(i + '0');
            gen(pos + 1, s, t, k);
        }
    }
    else
    {
        res += s[pos];
        gen(pos + 1, s, res, k);
    }
}

int get_num(string s)
{
    int res = 0;
    for (int c : s)
    {
        res = res * 10 + (int)(c - '0');
    }
    return res;
}

void solve(int z)
{
    a[0].clear();
    a[1].clear();
    cout << "Case #" << z << ": ";;
    string s, t;
    cin >> s >> t;
    gen(0, s, "", 0);
    gen(0, t, "", 1);
    int df = INF;
    pair<string, string> res;
    for (int i = 0; i < (int)a[0].size(); i++)
    {
        for (int j = 0; j < (int)a[1].size(); j++)
        {
            int ii = get_num(a[0][i]), jj = get_num(a[1][j]);
            if (abs(ii - jj) < df or (abs(ii - jj) == df and a[0][i] < res.first) or (abs(ii - jj) == df and a[0][i] == res.first and a[1][j] < res.second))
            {
                df = abs(ii - jj);
                res = {a[0][i], a[1][j]};
            }
        }
    }
    cout << res.first << " " << res.second << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("B-small-attempt3.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
}
