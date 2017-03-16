#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>

using namespace std;

string zfill(string s, int sz) {
    string ans = "";
    for (int i = 0; i < sz - s.length(); i++) {
        ans += '0';
    }
    ans += s;
    return ans;
}

int p[4];

bool ok(string s, string t) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != t[i] && s[i] != '?' && t[i] != '?') return false;
    }
    return true;
}

int main() {
    freopen("B-small-attempt3.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    p[0] = 1;
    p[1] = 10;
    p[2] = 100;
    p[3] = 1000;
    for (int tc = 1; tc <= t; tc++) {
        string c;
        string j;
        cin >> c >> j;
        int diff = 1000000;
        string ccc = "1000000";
        string jjj = "1000000";
        int sz = c.length();
        for (int icc = 0; icc < p[sz]; icc++) {
            for (int ijj = 0; ijj < p[sz]; ijj++) {
                string cc = zfill(to_string(icc), sz);
                string jj = zfill(to_string(ijj), sz);
                if (ok(cc, c) && ok(jj, j)) {
                    if (abs(stoi(cc) - stoi(jj)) < diff) {
                        diff = abs(stoi(cc) - stoi(jj));
                        ccc = cc;
                        jjj = jj;
                    }
                    else if (abs(stoi(cc) - stoi(jj)) == diff) {
                        if (cc < ccc || (cc == ccc && jj < jjj)) {
                            ccc = cc;
                            jjj = jj;
                        }
                    }
                }
            }
        }
        cout << "Case #" << tc << ": " << ccc << " " << jjj << "\n";
    }
    return 0;
}

