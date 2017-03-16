
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

long long dst(string s1, string s2) {
    long long r1 = 0, r2 = 0;
    for (int j = 0; j < s1.size(); ++j) {
        r1 = r1 * 10LL + (s1[j] - '0');
    }
    for (int j = 0; j < s2.size(); ++j) {
        r2 = r2 * 10LL + (s2[j] - '0');
    }
    return (r1 - r2) < 0 ? (r2 - r1) : (r1 - r2);
}

string to_max(string s1, int pos) {
    string r = s1;
    for (int i = pos; i < s1.size(); ++i) {
        if (r[i] == '?') {
            r[i] = '9';
        }
    }
    return r;
}

string to_min(string s1, int pos) {
    string r = s1;
    for (int i = pos; i < s1.size(); ++i) {
        if (r[i] == '?') {
            r[i] = '0';
        }
    }
    return r;
}

long long res = -1;
string res_s, res_t;

void update(string s1, string t1) {
    if (res == -1 || res > dst(s1, t1)) {
            res = dst(s1, t1);
            res_s = s1;
            res_t = t1;
        }
}

void calc(string s, string t, int p) {
    if (p == s.size()) {
        update(s, t);
        return;
    }
    string t_s, t_t;
    if (s[p] == '?' && t[p] == '?') {
        char so = s[p];
        char to = t[p];
        s[p] = '0';
        t[p] = '0';
        calc(s, t, p + 1);
        s[p] = so;
        t[p] = to;

        s[p] = '0';
        t[p] = '1';
        t_s = to_max(s, p + 1), t_t = to_min(t, p + 1);
        update(t_s, t_t);
        s[p] = so;
        t[p] = to;

        s[p] = '1';
        t[p] = '0';
        t_s = to_min(s, p + 1), t_t = to_max(t, p + 1);
        update(t_s, t_t);
        s[p] = so;
        t[p] = to;
    }
    if (s[p] == '?' && t[p] != '?') {
        char so = s[p];
        char to = t[p];
        s[p] = t[p];
        calc(s, t, p + 1);
        s[p] = so;

        if (t[p] != '0') {
            s[p] = t[p] - 1;
            t_s = to_max(s, p + 1), t_t = to_min(t, p + 1);
            update(t_s, t_t);
            s[p] = so;
        }
        if (t[p] != '9') {
            s[p] = t[p] + 1;
            t_s = to_min(s, p + 1), t_t = to_max(t, p + 1);
            update(t_s, t_t);
            s[p] = so;
        }
    }
    if (s[p] != '?' && t[p] == '?') {
        char so = s[p];
        char to = t[p];
        t[p] = s[p];
        calc(s, t, p + 1);
        t[p] = so;

        if (s[p] != '0') {
            t[p] = s[p] - 1;
            t_s = to_max(s, p + 1), t_t = to_min(t, p + 1);
            update(t_s, t_t);
            t[p] = so;
        }
        if (s[p] != '9') {
            t[p] = s[p] + 1;
            t_s = to_min(s, p + 1), t_t = to_max(t, p + 1);
            update(t_s, t_t);
            t[p] = so;
        }
    }
    if (s[p] != '?' && t[p] != '?') {
        if (s[p] == t[p]) {
            calc(s, t, p + 1);
        } else {
            if (s[p] < t[p]) {
                update(to_max(s, p + 1), to_min(t, p + 1));
            } else {
                update(to_min(s, p + 1), to_max(t, p + 1));
            }
        }
    }
}

string solve() {
    string s, t;
    cin >> s >> t;
    calc(s, t, 0);
    return res_s + " " + res_t;
}

int main() {
#ifdef ALEXEY
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(7) << std::fixed;
#endif
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        res = -1;
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}
