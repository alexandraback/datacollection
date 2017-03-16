#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;

char s[210], t[210], rs[210], rt[210], at[210], as[210];

bool eq(char a, char b) {
    return a == b || a == '?' || b == '?';
}

bool le(const pll& a, const pll& b) {
    ll ad = a.first - a.second;
    ll bd = b.first - b.second;
    if (ad < 0) ad = -ad;
    if (bd < 0) bd = -bd;
    if (ad != bd) return ad < bd;
    return a < b;
}

void solve() {
    scanf("%s %s", rs, rt);
    int n = strlen(rs);

    bool aeq = true;
    forn(i, n) {
        if (!eq(rs[i], rt[i])) {
            aeq = false;
            break;
        }
    }

    if (aeq) {
        forn(i, n) s[i] = rs[i], t[i] = rt[i];

        int state = 0;
        forn(i, n) {
            if (state == 0) {
                if (s[i] == '?')
                    if (t[i] == '?')
                        s[i] = t[i] = '0';
                    else
                        s[i] = t[i];
                else
                    if (t[i] == '?')
                        t[i] = s[i];
                    else
                        if (t[i] > s[i]) state = 1;
                        else if (t[i] < s[i]) state = -1;
            } else if (state == 1) {
                if (s[i] == '?') s[i] = '9';
                if (t[i] == '?') t[i] = '0';
            } else if (state == -1) {
                if (s[i] == '?') s[i] = '0';
                if (t[i] == '?') t[i] = '9';
            } else assert(false);
        }

        s[n] = t[n] = 0;
        // fprintf(stderr, "%s %s\n", rs, rt);
        // fprintf(stderr, "%s %s\n", s, t);
        printf("%s %s\n", s, t);
        assert(state == 0);
        return;
    }

    pll best(ll(2e18), ll(-2e18));
    forn(q, n) {
        for (char c1 = '0'; c1 <= '9'; c1++)
            for (char c2 = '0'; c2 <= '9'; c2++)
                if (c1 != c2 && eq(c1, rs[q]) && eq(c2, rt[q])) {
                    forn(i, n) s[i] = rs[i], t[i] = rt[i];
                    s[q] = c1, t[q] = c2;

                    int state = 0;
                    ll A = 0, B = 0;
                    forn(i, n) {
                        if (state == 0) {
                            if (s[i] == '?')
                                if (t[i] == '?')
                                    s[i] = t[i] = '0';
                                else
                                    s[i] = t[i];
                            else
                                if (t[i] == '?')
                                    t[i] = s[i];
                                else
                                    if (t[i] > s[i]) state = 1;
                                    else state = -1;
                        } else if (state == 1) {
                            if (s[i] == '?') s[i] = '9';
                            if (t[i] == '?') t[i] = '0';
                        } else if (state == -1) {
                            if (s[i] == '?') s[i] = '0';
                            if (t[i] == '?') t[i] = '9';
                        } else assert(false);
                        A = A * 10 + s[i] - '0';
                        B = B * 10 + t[i] - '0';
                    }

                    pll cur(A, B);
                    if (le(cur, best)) {
                        best = cur;
                        forn(i, n) as[i] = s[i], at[i] = t[i];
                    }
                }
        if (!eq(rs[q], rt[q])) break;
    }

    as[n] = at[n] = 0;
    printf("%s %s\n", as, at);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int q = 1; q <= tc; q++) {
        printf("Case #%d: ", q);
        solve();
    }
    return 0;
}
