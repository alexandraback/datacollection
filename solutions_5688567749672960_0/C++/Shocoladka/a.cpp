#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

const int maxn = 1e6 + 1;

int used[maxn];

int reverse(int n) {
    int m = 0;

    while (n > 0) {
        m = m * 10 + n % 10;
        n /= 10;
    }

    return m;
}

int bfs(int n) {
    for (int i = 0; i < maxn; i++) {
        used[i] = 0;
    }

    queue<pair<int, int> > q;
    q.push(make_pair(1, 1));

    while(!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();
        if (top.first == n)
            return top.second;
        if (!used[top.first + 1])
            q.push(make_pair(top.first + 1, top.second + 1));
        used[top.first + 1] = 1;

        if (!used[reverse(top.first)])
            q.push(make_pair(reverse(top.first), top.second + 1));
        used[reverse(top.first)] = 1;
    }
    return 0;
}

int main() {
    ifstream cin("input");
    ofstream cout("output");
    int t;
    cin >> t;

    for (int l = 0; l < t; l++) {
        int n;
        cin >> n;

        cout << "Case #" << l + 1 << ": " << bfs(n) << endl;
    }
}
