#include <bits/stdc++.h>

using namespace std;

namespace {

    typedef double real;
    typedef long long ll;

    const ll INF = LLONG_MAX / 2LL;

    template<class T> ostream& operator<<(ostream& os, const vector<T>& vs) {
        if (vs.empty()) return os << "[]";
        os << "[" << vs[0];
        for (int i = 1; i < vs.size(); i++) os << " " << vs[i];
        return os << "]";
    }
    template<class T> istream& operator>>(istream& is, vector<T>& vs) {
        for (auto it = vs.begin(); it != vs.end(); it++) is >> *it;
        return is;
    }

    int N;
    string C, J;
    void input() {
        C.clear(); J.clear();
        cin >> C >> J;
        N = int(C.size());
    }

    ll to_l(const string& s) {
        istringstream is(s);
        ll ret;
        is >> ret;
        return ret;
    }

    struct X {
        string c, j;
        ll diff;
        X() : c(""), j(""), diff(INF) {}
        X(const string& c, const string& j, ll diff) : c(c), j(j), diff(diff) {}
    };
    bool operator<(const X& a, const X& b) {
        if (a.diff == b.diff) {
            if (a.c == b.c) {
                return a.j < b.j;
            } else {
                return a.c < b.c;
            }
        } else {
            return a.diff < b.diff;
        }
    }
    ostream& operator<<(ostream& os, const X& x) {
        return os << x.c << " " << x.j;
    }

    int nstate(const char& c, const char& j) {
        if (c == j) return 0;
        if (c > j) return 1;
        if (c < j) return 2;
        assert(false);
    }

    ll calc_diff(const string& c, const string& j) {
        ll x = to_l(c);
        ll y = to_l(j);
        return abs<ll>(x - y);
    }

    bool valid_char(char c) {
        return isdigit(c);
    }

    X memo[20][3];
    X dfs(int index, int state) {
        if (index == N) return X("", "", 0);
        X& cache = memo[index][state];
        if (cache.diff < INF) return cache;
        X ret;
        if (state == 0) {
            if (C[index] == '?' && J[index] == '?') {
                for (int c = 0; c <= 1; c++) {
                    for (int j = 0; j <= 1; j++) {
                        if (c == 1 && j == 1) continue;
                        X ret1 = dfs(index + 1, nstate(C[index] + c, J[index] + j));
                        ret1.c = string(1, c + '0') + ret1.c;
                        ret1.j = string(1, j + '0') + ret1.j;
                        ret1.diff = calc_diff(ret1.c, ret1.j);
                        ret = min(ret, ret1);
                    }
                }
            } else if (C[index] == '?') {
                for (int j = 0; j <= 2; j++) {
                    if (valid_char(J[index] + (j - 1))) {
                        X ret1 = dfs(index + 1, nstate(J[index] + (j - 1), J[index]));
                        ret1.c = string(1, J[index] + (j - 1)) + ret1.c;
                        ret1.j = string(1, J[index]) + ret1.j;
                        ret1.diff = calc_diff(ret1.c, ret1.j);
                        ret = min(ret, ret1);
                    }
                }
            } else if (J[index] == '?') {
                for (int j = 0; j <= 2; j++) {
                    if (valid_char(C[index] + (j - 1))) {
                        X ret1 = dfs(index + 1, nstate(C[index], C[index] + (j - 1)));
                        ret1.c = string(1, C[index]) + ret1.c;
                        ret1.j = string(1, C[index] + (j - 1)) + ret1.j;
                        ret1.diff = calc_diff(ret1.c, ret1.j);
                        ret = min(ret, ret1);
                    }
                }
            } else {
                ret = dfs(index + 1, nstate(C[index], J[index]));
                ret.c = string(1, C[index]) + ret.c;
                ret.j = string(1, J[index]) + ret.j;
            }
        } else if (state == 1) {
            if (C[index] == '?' && J[index] == '?') {
                ret = dfs(index + 1, state);
                ret.c = "0" + ret.c;
                ret.j = "9" + ret.j;
            } else if (C[index] == '?') {
                ret = dfs(index + 1, state);
                ret.c = string(1, '0') + ret.c;
                ret.j = string(1, J[index]) + ret.j;
            } else if (J[index] == '?') {
                ret = dfs(index + 1, state);
                ret.c = string(1, C[index]) + ret.c;
                ret.j = string(1, '9') + ret.j;
            } else {
                ret = dfs(index + 1, state);
                ret.c = string(1, C[index]) + ret.c;
                ret.j = string(1, J[index]) + ret.j;
            }
        } else {
            if (C[index] == '?' && J[index] == '?') {
                ret = dfs(index + 1, state);
                ret.c = "9" + ret.c;
                ret.j = "0" + ret.j;
            } else if (C[index] == '?') {
                ret = dfs(index + 1, state);
                ret.c = string(1, '9') + ret.c;
                ret.j = string(1, J[index]) + ret.j;
            } else if (J[index] == '?') {
                ret = dfs(index + 1, state);
                ret.c = string(1, C[index]) + ret.c;
                ret.j = string(1, '0') + ret.j;
            } else {
                ret = dfs(index + 1, state);
                ret.c = string(1, C[index]) + ret.c;
                ret.j = string(1, J[index]) + ret.j;
            }
            assert(state == 2);
        }
        ret.diff = calc_diff(ret.c, ret.j);
        //cout << "index: " << index << " C: " << ret.c << " J: " << ret.j << endl;
        return cache = ret;
    }

    void solve() {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 3; j++) {
                memo[i][j] = X();
            }
        }
        cout << dfs(0, 0) << endl;
    }
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        input();
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}

