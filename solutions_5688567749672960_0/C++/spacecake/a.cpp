#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <queue>

using namespace std;

void test() {
    std::random_device rd;
    std::mt19937 mt(time(0));
    std::uniform_int_distribution<int> dist(1, 10000);
    int t = 1000;
    for (int i = 1; i <= t; i++) {
        int l = dist(mt) % 8;
        cout << l << "\n";
    }
}

inline int rev(int x) {
    int y = 0;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}

vector<int> solve() {
    vector<int> ans(int(1e6) + 1, int(1e6) + 1);
    queue<int> q;
    ans[0] = 0;
    ans[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int w = v + 1;
        if (w >= int(1e6) + 1) continue;
        if (ans[w] > ans[v] + 1) {
            ans[w] = ans[v] + 1;
            q.push(w);
        }
        w = rev(v);
        if (w >= int(1e6) + 1) continue;
        if (ans[w] > ans[v] + 1) {
            ans[w] = ans[v] + 1;
            q.push(w);
        }

    }
    return ans;
}

int main() {
    ifstream cin("test.in");
    ofstream cout("test.out"); 
    int testCount;
    cin >> testCount;
    vector<int> ans = solve();
    for (int testCase = 1; testCase <= testCount; testCase++) {
        int N;
        cin >> N;
        cout << "Case #" << testCase << ": " << ans[N] << "\n";
    }
    return 0;
}
