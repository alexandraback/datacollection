#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <ios>

using namespace std;

const int maxn = 1005;

int n;
string s;

void go(int casenum) {
    cin >> s;
    n = s.length();
    string t = "";
    for (int i = 0; i < n; i++) {
        bool b = 0;
        for (int j = 0; j < t.length(); j++)
            if (t[j] != s[i]) {
                if (t[j] > s[i]) t += s[i];
                else t = s[i] + t;
                b = 1;
                break;
            }

        if (!b) t += s[i];
    }
    cout << "Case #" << casenum << ": " << t << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    for (int i = 1; i <= t; i++) go(i);
}
