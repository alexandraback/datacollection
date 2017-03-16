#include <bits/stdc++.h>

using namespace std;

map<char,int> cnt;
vector<string> f, s;

void rec(int pos, string& s, vector<string>& v) {
    if (pos == s.size()) {
        v.push_back(s);
        return;
    }
    if (s[pos] != '?') {
        rec(pos + 1, s, v);
    } else {
        for (char c = '0'; c <= '9'; ++c) {
            s[pos] = c;
            rec(pos + 1, s, v);
        }
        s[pos] = '?';
    }
}

void Solve() {
    f.clear();
    s.clear();
    string a, b;
    cin >> a >> b;
    rec(0, a, f);
    rec(0, b, s);
    int p1, p2;
    int diff = 1e9;
    sort(f.begin(), f.end());
    sort(s.begin(), s.end());
    for (int i = 0; i < f.size(); ++i) {
        for(int j = 0; j < s.size(); ++j) {
            int x = atoi(f[i].c_str());
            int y = atoi(s[j].c_str());
            if (abs(x - y) < diff) {
                diff = abs(x - y);
                p1 = i;
                p2 = j;

            }
        }
    }
    cout << f[p1] << " " << s[p2] << endl;
}

int main() {
    int z;
    cin >> z;
    for (int i = 1; i <= z; ++i) {
        cout << "Case #" << i << ": ";
        Solve();
    }
    return 0;
}
