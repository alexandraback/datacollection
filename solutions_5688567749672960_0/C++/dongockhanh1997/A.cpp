#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e6;
int res[N + 1];

int main() {
    ios::sync_with_stdio(false);
    queue<int> q;
    q.push(1);
    res[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u < N && res[u + 1] == 0) {
            res[u + 1] = res[u] + 1;
            q.push(u + 1);
        }
        stringstream sout;
        sout << u;
        string s = sout.str();
        reverse(s.begin(), s.end());
        stringstream ss;
        ss << s;
        int x; ss >> x;
        if (res[x] == 0) {
            res[x] = res[u] + 1;
            q.push(x);
        }
    }
    int nt; cin >> nt;
    for (int t = 1; t <= nt; ++t) {
        int x; cin >> x;
        cout << "Case #" << t << ": " << res[x] << '\n';
    }
    return 0;
}
