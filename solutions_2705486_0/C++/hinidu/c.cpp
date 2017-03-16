#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int MAX_LEN = 4040;
const int MAX_WORD_LEN = 11;
const int MAXD = 5;

set<string> words[MAX_WORD_LEN];

void read_dictionary()
{
    ifstream dict("dictionary");

    string word;
    while (dict >> word)
        words[word.length()].insert(word);
}

int dp[MAX_LEN][MAXD];

inline
bool exists(const string &s)
{
    return words[s.length()].find(s) != words[s.length()].end();
}

void calc_dp(const int n, const int m, const int prev, const string &s, const int acc)
{
    int d = min(n - prev - 1, 4);
    if (dp[n][d] <= acc)
        return;
    if (exists(s))
    {
        dp[n][d] = min(dp[n][d], acc);
        return;
    }

    for (int i = prev + 5; i < n; ++i)
        for (char ch = 'a'; ch <= 'z'; ++ch)
            if (ch != s[i - m])
            {
                string t = s;
                t[i - m] = ch;
                calc_dp(n, m, i, t, acc + 1);
            }
}

int solve(const string &s)
{
    for (int i = 1; i <= (int)s.length(); ++i)
        for (int j = max(i - 10, 0); j < i; ++j)
            for (int d = 0; d < MAXD; ++d)
                calc_dp(i, j, j - 1 - d, s.substr(j, i - j), dp[j][d]);

    int ans = dp[s.length()][0];
    for (int i = 1; i < MAXD; ++i)
        ans = min(ans, dp[s.length()][i]);
    return ans;
}

int main()
{
    read_dictionary();

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        string s;
        cin >> s;
        for (int i = 0; i <= s.length(); ++i)
            for (int j = 0; j < MAXD; ++j)
                dp[i][j] = i;
        printf("Case #%d: %d\n", tc, solve(s));
        // for (int i = 0; i <= s.length(); ++i)
        // {
        //     for (int j = 0; j < MAXD; ++j)
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }
    }

    return 0;
}
