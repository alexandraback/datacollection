#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
vector<int> nxt[55];
int n;
string zip[55];
string ans;
int ret[55];
int vn[55];

void dfs(int x, int d) {
    if (x == -1) {
        if (d == n) {
            string now;
            for (int i = 1; i <= n; i++) {
                now += zip[vn[i]];
            }
            if (ans == "" || now < ans) {
                ans = now;
            }
        }
        return;
    }
    for (int y : nxt[x]) {
        if (ret[y] == 0) {
            ret[y] = x;
            int t = vn[d + 1];
            vn[d + 1] = y;
            dfs(y, d + 1);
            ret[y] = 0;
            vn[d + 1] = t;
        }
    }
    dfs(ret[x], d);
}

int main() {
    int tn;
    cin >> tn;
    for (int cn = 1; cn <= tn; cn++) {
        int m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> zip[i];
            nxt[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            nxt[a].push_back(b);
            nxt[b].push_back(a);
        }
        ans = "";
        for (int i = 1; i <= n; i++) {
            memset(ret, 0, sizeof(ret));
            ret[i] = -1;
            vn[1] = i;
            dfs(i, 1);
        }
        cout << "Case #" << cn << ": " << ans << endl;
    }
    return 0;
}
