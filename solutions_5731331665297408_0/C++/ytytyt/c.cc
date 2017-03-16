#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

int T, m, n, x, y, fc;
int g[10][10];
bool flag[10], t[10][10];
string s[10], ans;
vector<string> ares;
stack<int> sta;

int dfs(int now, int tot, string ss) {
    // cout << "hehe" << endl;
    // cout << now << endl;
    if (tot == n && sta.top() == fc) {
        ares.push_back(ss);
        // cout << "#" << ss << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            if (!flag[i] && g[now][i]) {
                flag[i] = true;
                sta.push(i);
                dfs(i, tot+1, ss + s[i]);
                // sta.pop();
                flag[i] = false;
            }
        }
        if (sta.size() > 1) {
            sta.pop();
            // cout << "*" << sta.top() << endl;
            dfs(sta.top(), tot, ss);
        }
    }
    // cout << "]" << endl;
}

int main() {
    cin >> T;
    for (int ti = 1; ti <= T; ti++) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            flag[i] = false;
        }
        // cout << s[1] << endl;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = false;
        for (int i = 1; i <= m; i++) {
            cin >> x >> y;
            g[x][y] = true;
            g[y][x] = true;
        }
        ares.clear();

        for (int i = 1; i <= n; i++) {
            fc = i;
            flag[i] = true;
            sta.push(i);
            dfs(i, 1, s[i]);
            sta.pop();
            flag[i] = false;
        }
        ans = ares[0];
        for (int i = 1; i < ares.size(); i++)
            if (ares[i] < ans)
                ans = ares[i];
        cout << "Case #" << ti << ": " << ans << endl;
    }
    return 0;
}
