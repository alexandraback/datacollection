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

long long diff;
string ra, rb;

void greed(string a, string b) {
    int pref = 1;
    int bg = 0;
    int n = (int)a.size();
    for (int i = 0; i < n; ++i) {
        if (pref) {
            if (a[i] == '?' && b[i] == '?') {
                a[i] = '0';
                b[i] = '0';
            } else
            if (a[i] == '?') {
                a[i] = b[i];
            } else
            if (b[i] == '?') {
                b[i] = a[i];
            } else {
                if (a[i] == b[i]) continue;
                if (a[i] > b[i]) bg = 1;
                pref = 0;
            }
        } else {
            if (!bg) {
                if (a[i] == '?') a[i] = '9';
                if (b[i] == '?') b[i] = '0';
            } else {
                if (a[i] == '?') a[i] = '0';
                if (b[i] == '?') b[i] = '9';
            }
        }
    }
    long long x = atoll(a.c_str());
    long long y = atoll(b.c_str());
    long long d = x > y ? x - y : y - x;
    if (d < diff || (d == diff && ra > a) || (d == diff && ra == a && rb > b)) {
        diff = d;
        ra = a;
        rb = b;
    }
}

void Solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size();
    diff = 5e18;
    greed(a, b);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (char c1 = '0'; c1 <= '9' + 1; ++c1) {
                for (char c2 = '0'; c2 <= '9' + 1; ++c2) {
                    string w = a, e = b;
                    if (c1 <= '9' && w[i] == '?') w[i] = c1;
                    if (c2 <= '9' && e[j] == '?') e[j] = c2;
                    greed(w, e);
                }
            }
        }
    }
    cout << ra << ' ' << rb << '\n';
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
