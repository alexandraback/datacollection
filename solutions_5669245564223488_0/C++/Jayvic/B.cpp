#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAX_N = 100;
const int ZY = 1000000007;

string data[MAX_N];
int l[26] = {}, r[26] = {};
bool mid[26] = {};
int cnt[26] = {};
bool vis[26] = {};

int solve(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
    }

    memset(l, 0xff, sizeof(l));
    memset(r, 0xff, sizeof(r));
    memset(mid, 0, sizeof(mid));
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));

    ll ans = 1;

    for (int i = 0; i < n; ++i)
    {
        string s = data[i];
        int t;
        if ((s.size() == 1) || (s[0] == s[s.size() - 1]))
        {
            for (int j = 1; j < (int)s.size(); ++j)
            {
                if (s[j] != s[0])
                {
                    return 0;
                }
            }
            t = s[0] - 'a';
            if (mid[t])
            {
                return 0;
            }
            ++cnt[t];
            continue;
        }

        int lp = 1;
        while (s[lp] == s[0])
        {
            ++lp;
        }

        int rp = s.size() - 2;
        while (s[rp] == s[s.size() - 1])
        {
            --rp;
        }

        for (int j = lp; j <= rp; ++j)
        {
            t = s[j] - 'a';
            char c = s[j];
            while (s[j + 1] == c)
            {
                ++j;
            }
            if (mid[t])
            {
                return 0;
            }
            mid[t] = true;
        }

        t = s[0] - 'a';
        if (l[t] != -1 || mid[t])
        {
            return 0;
        }
        else
        {
            l[t] = s[s.size() - 1] - 'a';
        }

        t = s[s.size() - 1] - 'a';
        if (r[t] != -1 || mid[t])
        {
            return 0;
        }
        else
        {
            r[t] = s[0] - 'a';
        }
    }

    for (int i = 0; i < 26; ++i)
    {
        if (mid[i])
        {
            if (cnt[i] || l[i] != -1 || r[i] != -1)
            {
                return 0;
            }
        }
    }

    int salt = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (!vis[i])
        {
            if (l[i] == -1 && r[i] == -1)
            {
                vis[i] = true;
                continue;
            }
            if (l[i] != -1 && r[i] == -1)
            {
                ++salt;
                vis[i] = true;
                int j = l[i];
                while (l[j] != -1)
                {
                    vis[j] = true;
                    for (int k = 2; k <= cnt[j]; ++k)
                        ans = (ans * k) % ZY;
                    j = l[j];
                }
                vis[j] = true;
            }
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        if (!vis[i])
        {
            return 0;
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        if (cnt[i] > 0)
        {
            if (l[i] == -1 || r[i] == -1)
            {
                for (int k = 2; k <= cnt[i]; ++k)
                    ans = (ans * k) % ZY;
            }
            if (l[i] == -1 && r[i] == -1)
            {
                ++salt;
            }
        }
    }

    for (int i = 2; i <= salt; ++i)
    {
        ans = (ans * i) % ZY;
    }

    return ans;
}

int main(void)
{
    int numTest;
    cin >> numTest;
    for (int testCase = 1; testCase <= numTest; ++testCase)
    {
        cout << "Case #" << testCase << ": ";
        cout << solve() << endl;
    }
    return 0;
}
