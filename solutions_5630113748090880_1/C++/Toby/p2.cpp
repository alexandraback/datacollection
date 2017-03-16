#include <cstdint>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int N;
map<int, int> C;

void solve() {
    C.clear();
    cin >> N;
    for (int i = 0; i < N * 2 - 1; i++) {
        for (int j = 0; j < N; j++) {
            int v;
            cin >> v;
            C[v]++;
        }
    }

    for (const auto& kvp : C) {
        if (kvp.second % 2 == 1) {
            cout << ' ' << kvp.first;
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cout << "Case #" << testcase << ":";
        solve();
    }
    return 0;
}
