#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 10
vector<string> words;
char a[N], b[N];
int n, m, times;

void dfs(int k, string s)
{
    if (k == 0)
    {
        words.push_back(s);
        return ;
    }
    for (int i = 0; i < n; ++i)
        dfs(k - 1, s + a[i]);
}

int contains(string w)
{
    int ans = 0;
    for (int i = 0; i <= w.length() - m; ++i)
    {
        if (strcmp(w.substr(i, m).c_str(), b) == 0)
        {
            // printf("%s %d\n", w.c_str(), i);
            ++ans;
        }
    }
    return ans;
}

void solve()
{
    // K L S
    scanf("%d%d%d", &n, &m, &times);
    scanf("%s", a);
    scanf("%s", b);
    words.clear();
    dfs(times, "");
    int tot = words.size();
    int ans = 0;
    int ma = 0;
    for (int i = 0; i < tot; ++i)
    {
        int cnt = contains(words[i]);
        ma = max(ma, cnt);
        ans += cnt;
    }
    printf("%.7f\n", ma - ans * 1.0 / tot);
}

int main()
{
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; ++tt)
    {
        printf("Case #%d: ", tt);
        solve();
    }
    return 0;
}