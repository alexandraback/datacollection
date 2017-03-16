#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>

using namespace std;

const int N=101;

string s[N], t[N];
int n, used[N], T, k, ans, i, j;
vector <int> g[N];
pair <int, int> a[N];

bool valid(string s)
{
    int used[26];
    for(int i = 0; i < 26; ++i) {
        used[i] = 0;
    }
    int n = s.length();
    for(int i = 0; i < n; ++i)
        if(used[s[i] - 'a'] == 0) {
            used[s[i] - 'a'] = 1;
        }
        else if(s[i] != s[i - 1] && used[s[i] - 'a']) {
            return false;
        }
    return true;
}

void dfs(int v, int pr, int d)
{
    used[v] = 1;
    t[v] = t[pr] + s[v];
    if(d < n)
    {
        for(int i = 1; i <= n; i++)
            if(used[i] == 0 && valid(t[v] + s[i])) dfs(i, v, d + 1);
    } else ++ans;
    used[v] = 0;
}

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> s[i];
        for(int i = 1; i <= n; i++)
            if (valid(s[i])) dfs(i, 0, 1);
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
