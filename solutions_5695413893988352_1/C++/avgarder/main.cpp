#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>
#include <fstream>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

void f(string &s, string &t, string &as, string &at, lint &xs, lint &xt) {
    int n = s.length();
    bool eqp = true;
    for (int i = 0; i < n; i++) {
        if (eqp) {
            if (s[i] == '?' && t[i] == '?') {
                as[i] = at[i] = '0';
            } else if (s[i] == '?') {
                as[i] = at[i] = t[i];
            } else if (t[i] == '?') {
                as[i] = at[i] = s[i];
            } else {
                as[i] = s[i];
                at[i] = t[i];
                if (s[i] != t[i]) {
                    eqp = false;
                }
                if (s[i] < t[i]) {
                    bool ok = false;
                    for (int j = i - 1; j >= 0; j--) {
                        if (as[j] != '9' && s[j] == '?') {
                            as[j]++;
                            ok = true;
                            break;
                        }
                        if (at[j] != '0' && t[j] == '?') {
                            at[j]--;
                            ok = true;
                            break;//
                        }
                    }
                    if (!ok) {
                        as = "-1";
                        at = "-1";
                        return;
                    }
                }
            }
        } else {
            if (s[i] == '?') {
                as[i] = '0';
            } else {
                as[i] = s[i];
            }
            if (t[i] == '?') {
                at[i] = '9';
            } else {
                at[i] = t[i];
            }
        }
    }

    xs = xt = 0;
    for (int i = 0; i < n; i++) {
        xs = xs * 10 + as[i] - '0';
        xt = xt * 10 + at[i] - '0';
    }
}

lint toi(string &s) {
    lint res = 0;
    for (int i = 0; i < s.length(); i++) {
        res = res * 10 + s[i] - '0';
    }
    return res;
}

string to_str(lint x, int n) {
    if (x == -1) {
        return "-1";
    }
    string res = "";
    while (x > 0) {
        res += char(x % 10 + '0');
        x /= 10;
    }
    while (res.size() < n) {
        res += '0';
    }
    reverse(res.begin(), res.end());
    return res;
}

void f2(string &s, string &t, string &as, string &at, lint &xs, lint &xt) {
    int n = s.length();
    bool can_eq = true;
    for (int i = 0; i < n; i++) {
        if (s[i] != '?' && t[i] != '?' && s[i] != t[i]) {
            can_eq = false;
            break;
        }
    }
    if (can_eq) {
        for (int i = 0; i < n; i++) {
            if (s[i] == '?' && t[i] == '?') {
                as[i] = at[i] = '0';
            } else if (s[i] == '?') {
                as[i] = at[i] = t[i];
            } else {
                as[i] = at[i] = s[i];
            }
        }
        xs = toi(as);
        xt = toi(at);
        return;
    }

    lint ad = 5e18;
    lint a1 = -1;
    lint a2 = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] != '?' && t[i] != '?' && s[i] < t[i]) {
            break;
        }

        if (t[i] == '9' || s[i] == '0' || (s[i] != '?' && s[i] == t[i])) {
            if (s[i] != '?' && t[i] != '?' && s[i] > t[i]) {
                break;
            }
            continue;
        }

        for (int j = 0; j < i; j++) {
            if (s[j] == '?' && t[j] == '?') {
                as[j] = at[j] = '0';
            } else if (s[j] == '?') {
                as[j] = at[j] = t[j];
            } else {
                as[j] = at[j] = s[j];
            }
        }

        if (s[i] == '?' && t[i] == '?') {
            as[i] = '1';
            at[i] = '0';
        } else if (s[i] == '?') {
            as[i] = char(t[i] + 1);
            at[i] = t[i];
        } else if (t[i] == '?') {
            as[i] = s[i];
            at[i] = char(s[i] - 1);
        } else {
            as[i] = s[i];
            at[i] = t[i];
        }

        for (int j = i + 1; j < n; j++) {
            if (s[j] == '?') {
                as[j] = '0';
            } else {
                as[j] = s[j];
            }
            if (t[j] == '?') {
                at[j] = '9';
            } else {
                at[j] = t[j];
            }
        }

        lint xx = toi(as);
        lint yy = toi(at);
        lint d = abs(xx - yy);
        if (d < ad || d == ad && (xx < a1 || xx == a1 && yy < a2)) {
            ad = d;
            a1 = xx;
            a2 = yy;
        }


        if (s[i] != '?' && t[i] != '?' && s[i] > t[i]) {
            break;
        }
    }

    as = to_str(a1, n);
    at = to_str(a2, n);
    xs = a1;
    xt = a2;
}

void solve() {
    string s, t;
    cin >> s >> t;
    string s1 = s, t1 = t, s2 = s, t2 = t;
    lint x1, y1, x2, y2;
    f2(s, t, s1, t1, x1, y1);
    f2(t, s, t2, s2, y2, x2);

    string a1 = "", a2 = "";
    if (s1 == "-1") {
        cout << s2 << " " << t2 << "\n";
    } else if (s2 == "-1") {
        cout << s1 << " " << t1 << "\n";
    } else {
        lint d1 = abs(x1 - y1);
        lint d2 = abs(x2 - y2);
        if (d1 < d2) {
            cout << s1 << " " << t1 << "\n";
        } else if (d1 > d2) {
            cout << s2 << " " << t2 << "\n";
        } else {
            if (x1 < x2 || (x1 == x2 && y1 < y2)) {
                cout << s1 << " " << t1 << "\n";
            } else {
                cout << s2 << " " << t2 << "\n";
            }
        }
    }
}

void solve_stupid() {
    ifstream in("input.txt");
    ofstream out("output2.txt");

    int T;
    in >> T;
    for (int tn = 1; tn <= T; tn++) {
        out << "Case #" << tn << ": ";

        string s, t;
        in >> s >> t;

        int a1 = -1, a2 = -1;
        int ad = 1e9;
        int n = s.length();
        int mx = 1;
        for (int i = 0; i < n; i++) {
            mx *= 10;
        }
        for (int i = 0; i < mx; i++) {
            string si = to_str(i, n);
            bool ok = true;
            for (int k = 0; k < n; k++) {
                if (s[k] != '?' && s[k] != si[k]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                continue;
            }
            for (int j = 0; j < mx; j++) {
                string sj = to_str(j, n);
                bool ok = true;
                for (int k = 0; k < n; k++) {
                    if (t[k] != '?' && t[k] != sj[k]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) {
                    continue;
                }
                int d = abs(i - j);
                if (d < ad || (d == ad && (i < a1 || (i == a1 && j < a2)))) {
                    ad = d;
                    a1 = i;
                    a2 = j;
                }
            }
        }
        out << to_str(a1, n) << " " << to_str(a2, n) << "\n";
    }
    in.close();
    out.close();
}

int main() {
//    solve_stupid();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scid(t);
    init_cin
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }


    return 0;
}