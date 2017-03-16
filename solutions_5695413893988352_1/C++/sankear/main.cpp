#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define prev huprev
#define next hunext
#define link hulink
#define hash huhash
#define rank hurank
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll inf = 1e18;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 22;

bool can[N][10][2];

inline pair<ll, pair<string, string> > solve(string a, string b, bool min_a) {
    assert(sz(a) == sz(b));
    for (int i = 0; i <= sz(a); ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int z = 0; z < 2; ++z) {
                can[i][j][z] = false;
            }
        }
    }
    can[sz(a)][0][0] = true;
    for (int i = sz(a); i > 0; --i) {
        for (int j = 0; j < 10; ++j) {
            for (int z = 0; z < 2; ++z) {
                if (!can[i][j][z]) {
                    continue;
                }
                for (int x = 0; x < 10; ++x) {
                    if (a[i - 1] != '?' && a[i - 1] != '0' + x) {
                        continue;
                    }
                    for (int y = 0; y < 10; ++y) {
                        if (b[i - 1] != '?' && b[i - 1] != '0' + y) {
                            continue;
                        }
                        int val = x - y - z, nz = 0;
                        if (val < 0) {
                            val += 10;
                            nz = 1;
                        }
                        if (val < 0) {
                            continue;
                        }
                        assert(val < 10);
                        can[i - 1][val][nz] = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (can[0][i][0]) {
            set<tuple<int, int, int> > lst, nlst;
            lst.insert(mt(0, i, 0));
            ll res = 0;
            string sa = "", sb = "";
            for (int j = 0; j < sz(a); ++j) {
                nlst.clear();
                tuple<int, int, int> best(100, 100, 100);
                int bx = -1, by = -1;
                for (tuple<int, int, int> st : lst) {
                    int pos, digit, ost;
                    tie(pos, digit, ost) = st;
                    for (int pdigit = 0; pdigit < 10; ++pdigit) {
                        for (int post = 0; post < 2; ++post) {
                            if (!can[pos + 1][pdigit][post]) {
                                continue;
                            }
                            for (int x = 0; x < 10; ++x) {
                                if (a[pos] != '?' && a[pos] != '0' + x) {
                                    continue;
                                }
                                for (int y = 0; y < 10; ++y) {
                                    if (b[pos] != '?' && b[pos] != '0' + y) {
                                        continue;
                                    }
                                    int val = x - y - post, z = 0;
                                    if (val < 0) {
                                        val += 10;
                                        z = 1;
                                    }
                                    if (val != digit || z != ost) {
                                        continue;
                                    }
                                    tuple<int, int, int> cur;
                                    if (min_a) {
                                        cur = mt(pdigit, x, y);
                                    } else {
                                        cur = mt(pdigit, y, x);
                                    }
                                    if (cur < best) {
                                        best = cur;
                                        bx = x;
                                        by = y;
                                    }
                                }
                            }
                        }
                    }
                }
                int digit, tmp;
                tie(digit, tmp, tmp) = best;
                res = res * 10 + digit;
                sa.pb('0' + bx);
                sb.pb('0' + by);
                for (tuple<int, int, int> st : lst) {
                    int pos, digit, ost;
                    tie(pos, digit, ost) = st;
                    for (int pdigit = 0; pdigit < 10; ++pdigit) {
                        for (int post = 0; post < 2; ++post) {
                            if (!can[pos + 1][pdigit][post]) {
                                continue;
                            }
                            for (int x = 0; x < 10; ++x) {
                                if (a[pos] != '?' && a[pos] != '0' + x) {
                                    continue;
                                }
                                for (int y = 0; y < 10; ++y) {
                                    if (b[pos] != '?' && b[pos] != '0' + y) {
                                        continue;
                                    }
                                    int val = x - y - post, z = 0;
                                    if (val < 0) {
                                        val += 10;
                                        z = 1;
                                    }
                                    if (val != digit || z != ost) {
                                        continue;
                                    }
                                    tuple<int, int, int> cur;
                                    if (min_a) {
                                        cur = mt(pdigit, x, y);
                                    } else {
                                        cur = mt(pdigit, y, x);
                                    }
                                    if (cur == best) {
                                        nlst.insert(mt(pos + 1, pdigit, post));
                                    }
                                }
                            }
                        }
                    }
                }
                lst.swap(nlst);
            }
            return mp(res, mp(sa, sb));
        }
    }
    return mp(inf, mp("", ""));
}

inline void solve() {
    string a, b;
    cin >> a >> b;
    pair<ll, pair<string, string>> v1 = solve(a, b, true);
    pair<ll, pair<string, string>> v2 = solve(b, a, false);
    swap(v2.sc.fs, v2.sc.sc);
    string sa, sb;
    if (v1.fs < v2.fs) {
        sa = v1.sc.fs;
        sb = v1.sc.sc;
    } else if (v1.fs > v2.fs) {
        sa = v2.sc.fs;
        sb = v2.sc.sc;
    } else {
        assert(v1.fs == v2.fs);
        if (v1.sc < v2.sc) {
            sa = v1.sc.fs;
            sb = v1.sc.sc;
        } else {
            sa = v2.sc.fs;
            sb = v2.sc.sc;
        }
    }
    cout << sa << " " << sb << endl;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
        cerr << "Test " << i + 1 << " of " << t << endl;
    }
    return 0;
}
