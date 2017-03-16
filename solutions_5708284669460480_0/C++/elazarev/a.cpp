#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int k, l, s;
string kbd, target;
map<string, int> cnt;
char cur[100];
void bf(int pos)
{
    if (pos == s)
    {
        cnt[cur]++;
    }
    else
    {
        for (int i = 0; i < k; ++i)
        {
            cur[pos] = kbd[i];
            bf(pos + 1);
        }
    }
}

int countIns(const string& str)
{
    int ans = 0;
    size_t pos = 0;
    while((pos = str.find(target, pos)) != string::npos)
        ans++, pos++;
    return ans;
}
void solve()
{
    double ans = 0;
    int min_r = 0;
    cnt.clear();
    memset(cur, 0, 100);
    cin >> k >> l >> s;
    cin >> kbd >> target;
    bf(0);
    int total_w = 0;
    for(map<string, int>::const_iterator it = cnt.begin(); it != cnt.end(); ++it)
    {
        int app = countIns(it->first);
        min_r = max(min_r, app);
        total_w += it->second;
    }
    for(map<string, int>::const_iterator it = cnt.begin(); it != cnt.end(); ++it)
    {
        int app = countIns(it->first);
        int keep = min_r - app;
        ans += keep * (it->second / (total_w + 0.0));
    }
    printf("%.7lf\n", ans);
}

int main()
{
    int t;
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
}

