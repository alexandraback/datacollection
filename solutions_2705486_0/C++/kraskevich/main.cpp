#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>


const int N = 55;
const int INF = 1000;

vector<string> with_len[N];
int dp[55][55];
string s;
int n, sz;
int bad[N];

void check(string word, string s, int &pref, int &suff, int &cnt)
{
    cnt = 0;
    pref = word.length();
    suff = word.length();

    sz = 0;
    for (int i = 0; i < word.length(); ++i)
        if (word[i] != s[i])
        {
            bad[sz] = i;
            sz++;
            if (sz >= 2 && bad[sz - 1] - bad[sz - 2] < 5)
            {
                pref = -1;
                return;
            }
        }

    cnt = sz;
    if (cnt)
        pref = bad[0];
    if (cnt)
        suff = (int)word.length() - bad[sz - 1] - 1;
}

void solve(int test)
{
    s.clear();
    cin >> s;
    n = s.length();

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= 5; ++j)
            dp[i][j] = INF;
    for (int i = 0; i <= 5; ++i)
        dp[0][i] = 0;

    for (int l = 0; l < n; ++l)
    {
        string curr;
        for (int r = l; r < n; ++r)
        {
            curr += s[r];
            int len = r - l + 1;
            for (int i = 0; i < with_len[len].size(); ++i)
            {
                int pref;
                int suff;
                int cnt;

                check(with_len[len][i], curr, pref, suff, cnt);

                if (pref == -1)
                    continue;

                for (int diff = 0; diff <= 5; ++diff)
                {
                    if (pref != len && pref + diff < 4)
                        continue;
                    int sf = suff;
                    if (sf == len)
                        sf += diff;
                    sf = min(sf, 5);
                    dp[r + 1][sf] = min(dp[r + 1][sf], dp[l][diff] + cnt);
                }
            }
        }
    }

    int res = INF;
    for (int i = 0; i <= 5; ++i)
        res = min(res, dp[n][i]);

    cout << "Case #" << test << ": ";
    cout << res;
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    ifstream fin("dictionary.txt"); //a file which contains the given dictionary
    string word;
    while (fin >> word)
        with_len[(int)word.length()].push_back(word);
    fin.close();



    int T;
    cin >> T;
    for (int test = 1; test <= T; test++)
        solve(test);


    fclose(stdin);
    fclose(stdout);

    return 0;
}
