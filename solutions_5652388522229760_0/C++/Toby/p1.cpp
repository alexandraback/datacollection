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

void solve() {
    int64_t N;
    cin >> N;
    if (N == 0) {
        cout << "INSOMNIA" << endl;
        return;
    }

    set<char> s;
    int64_t num = N;
    while (true) {
        for (char c : to_string(num)) s.insert(c);
        if (s.size() == 10) {
            cout << num << endl;
            break;
        }
        num += N;
    }
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cout << "Case #" << testcase << ": ";
        solve();
    }
    return 0;
}
