#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int solve(string& s) {
    int res = 0;
    int diff = 0;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            diff++;
        }
    }

    if (s[0] == '+') {
        // The case of "+-+-".
        return (diff % 2 == 1)? (diff + 1) : diff;
    } else {
        // The case of "-+-".
        return (diff % 2 == 1)? diff : (diff + 1);
    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        string s;
        cin >> s;
        int res = solve(s);
        cout << "Case #" << (i + 1) << ": " << res << endl;
    }    
    return 0;
}
