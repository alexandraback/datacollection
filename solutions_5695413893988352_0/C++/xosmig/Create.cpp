
#include <bits/stdc++.h>

using namespace std;

typedef int INT;
typedef long long ll;
typedef long double ld;
#define int ll

typedef pair<int, int> pii;
#define one first
#define two second

#define isize(v) static_cast<int>(v.size())

#define qfor(i, a, b) for (int i = static_cast<int>(a), _end_ = static_cast<int>(b); i < _end_; ++i)
#define fori(n) qfor(i, 0, n)
#define forj(n) qfor(j, 0, n)

#define forin(x, v) for (auto &x: v)

void solve() {
    string s, g;
    cin >> s >> g;

    int n = s.size();

    string s0, s9, g0, g9;
    s0.resize(n + 1); s0.back() = '\0';
    s9.resize(n + 1); s9.back() = '\0';
    g0.resize(n + 1); g0.back() = '\0';
    g9.resize(n + 1); g9.back() = '\0';

    transform(s.begin(), s.end(), s0.begin(), [](char c){ return c == '?' ? '0' : c; });
    transform(g.begin(), g.end(), g0.begin(), [](char c){ return c == '?' ? '0' : c; });

    transform(s.begin(), s.end(), s9.begin(), [](char c){ return c == '?' ? '9' : c; });
    transform(g.begin(), g.end(), g9.begin(), [](char c){ return c == '?' ? '9' : c; });

    string sr, gr;
    sr.resize(n);
    gr.resize(n);

    char who = '\0';
    fori (n) {
        if (who == '\0') {
            int bs = '0', bg = '0';
            int best = 1e18 + 10;
            for (char sc = '0'; sc <= '9'; ++sc) {
                for (char gc = '0'; gc <= '9'; ++gc) {
                    if ((s[i] != '?' && s[i] != sc) || (g[i] != '?' && g[i] != gc)) {
                        continue;
                    }
                    s0[i] = sc;
                    s9[i] = sc;
                    
                    g0[i] = gc;
                    g9[i] = gc;

                    int cur1 = abs(atoll(&s0[i]) - atoll(&g0[i]));
                    int cur2 = abs(atoll(&s0[i]) - atoll(&g9[i]));
                    int cur3 = abs(atoll(&s9[i]) - atoll(&g0[i]));

                    int cur = min(cur1, min(cur2, cur3));

                    if (cur < best) {
                        best = cur;
                        bs = sc;
                        bg = gc;
                    }
                }
            }

            sr[i] = bs;
            gr[i] = bg;

            if (bs > bg) {
                who = 's';
            }

            if (bg > bs) {
                who = 'g';
            }
        } else {
            if (s[i] == '?' && g[i] == '?') {
                if (who == 's') {
                    sr[i] = '0';
                    gr[i] = '9';
                } else {
                    sr[i] = '9';
                    gr[i] = '0';
                }
            }

            if (s[i] == '?' && g[i] != '?') {
                gr[i] = g[i];
                if (who == 's') {
                    sr[i] = '0';
                } else {
                    sr[i] = '9';
                }
            }

            if (s[i] != '?' && g[i] == '?') {
                sr[i] = s[i];
                if (who == 's') {
                    gr[i] = '9';
                } else {
                    gr[i] = '0';
                }
            }

            if (s[i] != '?' && g[i] != '?') {
                sr[i] = s[i];
                gr[i] = g[i];
            }
        }
    }

    cout << sr << ' ' << gr << endl;
}

INT main() {
    #ifdef _GLIBCXX_DEBUG
    assert(freopen("test.in", "r", stdin));
    assert(freopen("result.out", "w", stdout));
    #else
    // assert(freopen("unequal.in", "r", stdin));
    // assert(freopen("result.out", "w", stdout));
    cin.tie(0);
    #endif
    ios_base::sync_with_stdio(0);
    /// =======================================

    int n;
    cin >> n;
    fori (n) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}
