#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for(int i(a);i<=(int)(b);i++)
#define REP(i,n) FOR(i,0,n-1)

const int N = 1005;
int n, a[N], b[N], s[N];
vector<int> e[N];

void Prepare() {

}

int bfs(int s, int t) {
    queue<int> q;
    b[s] = 1;
    q.push(s);
    int ans = 0;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        ans = max(ans, b[i]);
        REP(j, e[i].size()) {
            int p = e[i][j];
            if (!b[p] && p != t) {
                b[p] = b[i] + 1;
                q.push(p);
            }
        }
    }
    return ans;
}

void Work(int casenum) {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) b[i] = 0, e[i].clear(), s[i] = 0;
    FOR(i, 1, n) e[a[i]].push_back(i);

    int ans = 0;
    FOR(i, 1, n) if (a[a[i]] == i && i <= a[i]) {
        int x = bfs(i, a[i]);
        int y = bfs(a[i], i);
        ans += x + y;
    }
    queue<int> q;
    FOR(i, 1, n)
    if (!b[i]) {
        int tmp = 0;
        vector<int> v;
        int now = i;
        int cnt = 0;
        while (!b[now]) {
            b[now] = cnt++;
            v.push_back(now);
            now = a[now];
        }
        if (b[now] < v.size() && v[b[now]] == now && now != v.back()) {
            ans = max(ans, (int)v.size() - b[now]);
            //cout << "!" << v.size() << ' ' << now << ' ' << b[now] << endl;
        }
    }


    cout << "Case #" << casenum << ": " << ans << endl;
}

int main() {
  Prepare();
  int n;
  cin >> n;
  FOR(i, 1, n) Work(i);

}
