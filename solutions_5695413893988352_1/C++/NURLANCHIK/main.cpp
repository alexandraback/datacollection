#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#pragma comment(linker, "/STACK:64000000")

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define sqr(x) ((x) * (x))
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pii;

string s, t;

__int128 get(string s) {
    __int128 res = 0;
    for (int i = 0; i < sz(s); i++) {
        res = res * 10 + (s[i] - '0');
    }
    return res;
}

pair <string, string> solve1(string s, string t, int pos) {
    for (int i = 0; i < pos; i++) {
        if (s[i] == '?' && t[i] == '?') {
            s[i] = t[i] = '0';
        }
        if (s[i] == '?') {
            s[i] = t[i];
        } else {
            t[i] = s[i];
        }
    }
    for (int i = pos + 1; i < sz(s); i++) {
        if (s[i] == '?') {
            s[i] = '9';
        }
    }
    for (int i = pos + 1; i < sz(s); i++) {
        if (t[i] == '?') {
            t[i] = '0';
        }
    }
    return {s, t};
}

pair <string, string> solve2(string s, string t, int pos) {
    for (int i = 0; i < pos; i++) {
        if (s[i] == '?' && t[i] == '?') {
            s[i] = t[i] = '0';
        }
        if (s[i] == '?') {
            s[i] = t[i];
        } else {
            t[i] = s[i];
        }
    }
    for (int i = pos + 1; i < sz(s); i++) {
        if (s[i] == '?') {
            s[i] = '0';
        }
    }
    for (int i = pos + 1; i < sz(s); i++) {
        if (t[i] == '?') {
            t[i] = '9';
        }
    }
    return {s, t};
}

int main() {
    freopen("/Users/nurlan/Dropbox/Programming/contest/contest/input", "r", stdin);
    freopen("/Users/nurlan/Dropbox/Programming/contest/contest/output", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cout << "Case #" << test << ": ";
        cin >> s >> t;
        string ss = s;
        string tt = t;
        int pos = -1;
        for (int i = 0; i < sz(s); i++) {
            if (s[i] != '?' && t[i] != '?' && s[i] != t[i]) {
                pos = i;
                break;
            }
            if (s[i] == '?' && t[i] == '?') {
                s[i] = t[i] = '0';
            }
            if (s[i] == '?') {
                s[i] = t[i];
            } else {
                t[i] = s[i];
            }
        }
        if (pos == -1) {
            cout << s << " " << t << "\n";
            continue;
        }
        __int128 d, x;
        pair <string, string> cur;
        string A, B;
        if (s[pos] < t[pos]) {
            cur = solve1(s, t, pos);
            d = get(cur.s) - get(cur.f);
            A = cur.f;
            B = cur.s;
        } else {
            cur = solve2(s, t, pos);
            d = get(cur.f) - get(cur.s);
            A = cur.f;
            B = cur.s;
        }
//        cout << A << " " << B << "\n";
        for (int i = 0; i < pos; i++) {
            s = ss;
            t = tt;
            if (s[i] != '?' && t[i] != '?') {
                continue;
            }
            if (s[i] == '?' && t[i] == '?') {
                s[i] = '0';
                t[i] = '1';
                cur = solve1(s, t, i);
                x = get(cur.s) - get(cur.f);
                if (x < d) {
                    d = x;
                    A = cur.f;
                    B = cur.s;
                }
                s[i] = '1';
                t[i] = '0';
                cur = solve2(s, t, i);
                x = get(cur.f) - get(cur.s);
                if (x < d) {
                    d = x;
                    A = cur.f;
                    B = cur.s;
                }
                continue;
            }
            if (s[i] == '?') {
                if (t[i] < '9') {
                    s[i] = t[i] + 1;
                    cur = solve2(s, t, i);
                    x = get(cur.f) - get(cur.s);
                    if (x < d) {
                        d = x;
                        A = cur.f;
                        B = cur.s;
                    }
                }
                if (t[i] > '0') {
                    s[i] = t[i] - 1;
                    cur = solve1(s, t, i);
                    x = get(cur.s) - get(cur.f);
                    if (x < d) {
                        d = x;
                        A = cur.f;
                        B = cur.s;
                    }
                }
            } else {
                if (s[i] < '9') {
                    t[i] = s[i] + 1;
                    cur = solve2(s, t, i);
                    x = get(cur.s) - get(cur.f);
                    if (x < d) {
                        d = x;
                        A = cur.f;
                        B = cur.s;
                    }
                }
                if (s[i] > '0') {
                    t[i] = s[i] - 1;
                    cur = solve1(s, t, i);
                    x = get(cur.f) - get(cur.s);
                    if (x < d) {
                        d = x;
                        A = cur.f;
                        B = cur.s;
                    }
                }
            }
        }
        cout << A << " " << B;
        cout << "\n";
    }
    return 0;
}