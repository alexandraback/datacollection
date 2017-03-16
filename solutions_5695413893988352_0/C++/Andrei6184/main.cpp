#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isOk(string& pat, int v) {
    for (int i = pat.length() - 1; i >= 0; i--) {
        if ((pat[i] != '?') && (pat[i] - '0') != (v % 10)) return false;
        v /= 10;
    }
    return (v == 0);
}

int main() {
    freopen("B-small-attempt3.in", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s1, s2;
        cin >> s1 >> s2;
        int a1 = -1, a2 = -1, a3 = 10000;
        for (int i1 = 0; i1 < 1000; i1++) {
            if (!isOk(s1, i1)) continue;
            for (int i2 = 0; i2 < 1000; i2++) {
                if (!isOk(s2, i2)) continue;
                int d = abs(i1 - i2);
                if (d < a3) {
                    a1 = i1;
                    a2 = i2;
                    a3 = d;
                }
            }
        }
        cout << "Case #" << t << ": " << setw(s1.length()) << setfill('0') << a1 << ' ' <<
                                         setw(s2.length()) << setfill('0') << a2 << endl;
    }
    return 0;
}
