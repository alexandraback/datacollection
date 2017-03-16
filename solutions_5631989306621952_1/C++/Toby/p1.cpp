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
    string s;
    cin >> s;

    string t = s.substr(0, 1);
    for (size_t i = 1; i < s.size(); i++) {
        if (s[i] >= t[0])
            t = s.substr(i, 1) + t;
        else
            t.push_back(s[i]);
    }
    cout << t << endl;
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
