#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

int T;
int P, Q;
string s;

void solve() {
    int res = 0;
    for (res = 0; res < 40; ++res) {
        if (Q % 2 != 0) {
            cout << "impossible" << endl;
            return;
        } else if (P*2 >= Q) {
            cout << res + 1<< endl;
            return;
        } else {
            Q /= 2;
        }
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    cin >> T;
    for (int caseId = 1; caseId <= T; ++caseId) {
        cin >> s;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '/') {
                s[i] = ' ';
            }
        }
        istringstream sin(s);
        sin >> P >> Q;
        cout << "Case #" << caseId << ": ";
        solve();
    }
    return 0;
}
