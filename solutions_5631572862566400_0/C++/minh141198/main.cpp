#include <bits/stdc++.h>
using namespace std;
#define W << " " <<
const int MOD = (int) 1e9 + 7;
const double eps = 1e-8, pi = acos(-1);
void MAIN();
int main(){
    //freopen("input.txt", "r", stdin);
    ios:: sync_with_stdio(false); cin.tie(0);
    MAIN();
    return 0;
}

void MAIN() {
    int nTest;
    cin >> nTest;
    for (int cs = 1; cs <= nTest; cs ++) {
        int n;
        cin >> n;
        vector <int> Next(n), deg(n, 0), furthest(n, 0);
        for (int i = 0; i < n; i ++)    cin >> Next[i], Next[i] --, deg[Next[i]] ++;
        queue <int> q;
        for (int i = 0; i < n; i ++)    if (deg[i] == 0) q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            int v = Next[u];
            deg[v] --;
            furthest[v] = max(furthest[v], furthest[u] + 1);
            if (deg[v] == 0) q.push(v);
        }
        int maxCircle = 0, sumCircle = 0;
        for (int i = 0; i < n; i ++)    if (deg[i] == 1) {
            int u = i, circleLen = 0, first = 0, second = 0;
            while (true) {
                circleLen ++;
                int v = furthest[u];
                if (v > first) second = first, first = v;
                else if (v > second) second = v;
                deg[u] = 0;
                u = Next[u];
                if (u == i) break;
            }
            if (circleLen == 2) sumCircle += 2 + first + second;
            else maxCircle = max(maxCircle, circleLen);
        }
        int ans = max(maxCircle, sumCircle);

        cout << "Case #" << cs << ": " << ans << "\n";
        cerr << "Case #" << cs << ": " << ans << "\n";
    }
}
