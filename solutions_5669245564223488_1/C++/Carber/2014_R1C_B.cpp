#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int mod = 1000000007;

string Convert(string &s)
{
    string ret_s = "";
    ret_s += s[0];
    ret_s += s[s.size() - 1];
    return ret_s;
}

int g[26][26];
int cnt_tt_tt = 0;
bool crc = false;

void dfs(int u, bool used[])
{
    if (used[u])
    {
        crc = true;
        return;
    }
    ++cnt_tt_tt;
    used[u] = true;
    for (int i = 0; i < 26; ++i)
        if (u != i && g[u][i]) dfs(i, used);
}

void Solved(int nT)
{
    memset(g, 0, sizeof(g));
    long long fact[128] = {1};
    for (int i = 1; i < 128; ++i)
        fact[i] = fact[i - 1] * i % mod;
    vector<string> vec;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string ss;
        cin >> ss;
        vec.push_back(ss);
    }
    printf("Case #%d: ", nT);

    for (char ch = 'a'; ch <= 'z'; ++ch)
    {
        bool inside = false;
        int left_side_count = 0;
        int right_side_count = 0;
        for (int i = 0; i < n; ++i)
        {
            int pre = -1;
            bool left_side = false;
            bool right_side = false;
            bool b_inside = false;
            for (int j = 0; j < vec[i].size(); ++j)
            {
                if (vec[i][j] != ch)
                    continue;
                if (pre == -1 || j == pre + 1)
                    pre = j;
                else
                {
                    puts("0");
                    return;
                }
                if (j == 0) left_side = true;
                if (j + 1 == vec[i].size())
                    right_side = true;
                if (j > 0 && j + 1 < vec[i].size())
                    b_inside = true;
            }
            if (b_inside || left_side || right_side)
            {
                if (inside)
                {
                    puts("0");
                    return;
                }
            }
            if (b_inside && !left_side && !right_side)
            {
                
                inside = true;
            }
            if (left_side) ++left_side_count;
            if (right_side) ++right_side_count;
        }
        if (abs(left_side_count - right_side_count) > 1)
        {
            puts("0");
            return;
        }
    }

    vector<string> real;
    for (int i = 0; i < n; ++i)
        real.push_back(Convert(vec[i]));
    int du[26] = {0};
    int in[26] = {0};

    for (int i = 0; i < n; ++i)
    {
        g[real[i][0] - 'a'][real[i][1] - 'a']++;
        if (real[i][0] != real[i][1]) 
        {
            ++du[real[i][0] - 'a'];
            ++in[real[i][1] - 'a'];
        }
    }

    for (int i = 0; i < 26; ++i)
        if (du[i] > 1 || in[i] > 1)
        {
            puts("0");
            return;
        }

    for (char ch = 'a'; ch <= 'z'; ++ch)
    {
        int left_side_count = 0;
        int right_side_count = 0;
        int same_count = 0;
        for (int i = 0; i < n; ++i)
        {
            if (real[i][0] == ch) ++left_side_count;
            if (real[i][1] == ch) ++right_side_count;
            if (real[i][0] == ch && real[i][1] == ch) ++same_count;
        }

        if (left_side_count == right_side_count && left_side_count == same_count)
        {
            continue;
        }

        if (left_side_count == right_side_count && left_side_count == same_count + 1)
        {
            continue;
        }

        if (left_side_count + 1 == right_side_count)
        {
            if (same_count == left_side_count)
                continue;
            puts("0");
            return;
        }
        if (left_side_count == right_side_count + 1)
        {
            if (same_count == right_side_count)
                continue;;
            puts("0");
            return;
        }

        puts("0");
        return;
    }

    bool used[26] = {false};
    long long result = 1;
    int cnt = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (used[i]) continue;
        if (in[i] != 0) continue;
        cnt_tt_tt = 0;
        crc = false;
        dfs(i, used);
        if (crc)
        {
            puts("0");
            return;
        }
        if (du[i] || g[i][i]) 
            ++cnt;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (g[i][i])
        {
            result *= fact[g[i][i]];
            result %= mod;
        }
    }

    result *= fact[cnt];
    result %= mod;

    for (int i = 0; i < 26; ++i)
    {
        if (!used[i])
            result = 0;
    }
    cout << result << endl;
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large3.out", "w", stdout);

    int T = 1;
    cin >> T;
    for (int nT = 1; nT <= T; ++nT)
    {
        Solved(nT);
    }

    return 0;
}