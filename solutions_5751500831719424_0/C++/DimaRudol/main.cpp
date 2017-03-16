#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

string s[200];
vector< pair<char, int> > v[200];

vector< pair<char, int> > conv(string &s)
{
    vector< pair<char, int> > res;
    int len = 0;
    for (int i = 0; i < s.length(); i++)
    {
        len++;
        if (s[i+1] != s[i] || i == s.length()-1)
        {
            res.push_back(make_pair(s[i], len));
            len = 0;
        }
    }
    return res;
}

int med(int pos, int n)
{
    vector<int> vals;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        vals.push_back(v[i][pos].second);
    }

    sort(vals.begin(), vals.end());
    int m = vals[n/2];

    for (int i = 0; i < n; i++)
        res += abs(vals[i] - m);

    return res;
}

void solve(int TT)
{
    cerr << TT << endl;
    int res = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        v[i] = conv(s[i]);
    }

    bool ok = true;

    for (int j = 0; j < n; j++)
        if (v[j].size() != v[0].size())
            ok = false;

    if (ok)
    for (int i = 0; i < v[0].size(); i++)
    {
        for (int j = 0; j < n; j++)
            if (v[j][i].first != v[0][i].first)
                ok = false;
    }

    if (ok == false)
    {
        cout << "Case #" << TT << ": " << "Fegla Won" << endl;
        return;
    }

    res = 0;
    for (int i = 0; i < v[0].size(); i++)
        res += med(i, n);

    cout << "Case #" << TT << ": " << res << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}

