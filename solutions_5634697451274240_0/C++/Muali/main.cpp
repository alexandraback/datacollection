#include <bits/stdc++.h>

using namespace std;

template<class T>
using v = vector<T>;
using ll = long long;

using pii = pair<ll, ll>;


void stupid()
{
    string s;
    cin >> s;
    set<string>   used;
    used.insert(s);
    queue<pair<string, int>> q;
    q.push(make_pair(s, 0));

    auto check = [](string &s)
    {
        for (char x: s)
            if (x == '-')
                return false;
        return true;
    };

    auto flip = [](string &s, int x)
    {
        string res = s;
        for (int i = 0; i < x; ++i)
            res[i] = res[i] == '-' ? '+' : '-';
        reverse(res.begin(), res.begin() + x);
        return res;
    };

    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        if (check(t.first))
        {
            cout << t.second << endl;
            return;
        }
        for (int i = 0; i < t.first.size(); ++i)
        {
            string f = flip(t.first, i + 1);
            if (used.find(f) == used.end())
            {
                used.insert(f);
                q.push(make_pair(f, t.second + 1));
            }
        }
    }
}

void solve()
{
    string s;
    cin >> s;

    auto check = [](string &s)
    {
        for (char x: s)
            if (x == '-')
                return false;
        return true;
    };

    auto flip = [](string &s, int x)
    {
        for (int i = 0; i < x; ++i)
            s[i] = s[i] == '-' ? '+' : '-';
        reverse(s.begin(), s.begin() + x);
    };

    int ans = 0;
    while (!check(s))
    {
        ++ans;
        if (s[0] == '+')
        {
            int i = 0;
            for (; s[i] == '+'; ++i);
            flip(s, i);
        }
        else
        {
            int i = s.size() - 1;
            for (; s[i] == '+'; --i);
            flip(s, i + 1);
        }
    }
    cout << ans << endl;
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
        stupid();
    }
}