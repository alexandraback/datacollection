#include <bits/stdc++.h>
using namespace std;

void solve(string inp) {
    deque<char> d;
    d.push_back(inp[0]);

    for (size_t i = 1; i < inp.length(); i++) {
        if (inp[i] >= d.front()) {
            d.push_front(inp[i]);
        }
        else {
            d.push_back(inp[i]);
        }
    }

    for (char c : d) {
        cout << c;
    }
    cout << endl;
}

int main() {
    int TC; cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cout << "Case #" << tc << ": ";
        string inp;
        cin >> inp;
        solve(inp);
    }

    return 0;
}
