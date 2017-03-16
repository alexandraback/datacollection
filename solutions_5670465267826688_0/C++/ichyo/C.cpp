// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

#ifdef LOCAL
#include "contest.h"
#else
#define dump(x) 
#endif

class range {
    struct Iterator {
        int val, inc;
        int operator*() {return val;}
        bool operator!=(Iterator& rhs) {return val < rhs.val;}
        void operator++() {val += inc;}
    };
    Iterator i, n;
    public:
    range(int e) : i({0, 1}), n({e, 1}) {}
    range(int b, int e) : i({b, 1}), n({e, 1}) {}
    range(int b, int e, int inc) : i({b, inc}), n({e, inc}) {}
    Iterator& begin() {return i;}
    Iterator& end() {return n;}
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}

struct QT{
    int sign;
    int type;
};
QT operator *(QT p, QT q) {
    QT res;
    res.sign = p.sign * q.sign;
    if(p.type == 0) {
        res.type = q.type;
    } else if(q.type == 0) {
        res.type = p.type;
    } else if(p.type == q.type) {
        res.type = 0;
        res.sign *= -1;
    } else {
        bool b[4] = {};
        b[p.type] = true;
        b[q.type] = true;
        REP(i, 4) if(!b[i]) res.type = i;

        int x = p.type + 1;
        if(x == 4) x = 1;
        int y = q.type + 1;
        if(y == 4) y = 1;

        if(x == q.type) {
        } else {
            assert(y == p.type);
            res.sign *= -1;
        }
    }
    return res;
}
void solve() {
    int L, X;
    cin >> L >> X;
    string s;
    cin >> s;
    string t;

    REP(i, X) {
        t += s;
    }

    int N = t.size();
    unordered_set<int> I;
    unordered_set<int> K;
    {
        QT p = {1, 0};
        for(int i = 0; i < N; i++) {
            QT q = {1, 0};
            q.type = t[i] - 'i' + 1;
            p = p * q;
            if(p.sign == 1 && p.type == 1) {
                I.insert(i+1);
            }
        }
    }

    for(int b = 1; b < N; b++) {
        QT p = {1, 0};
        for(int i = b; i < N; i++) {
            QT q = {1, 0};
            q.type = t[i] - 'i' + 1;
            p = p * q;
        }
        if(p.sign == 1 && p.type == 3) {
            K.insert(b);
        }
    }

    bool ok = false;
    for(int b = 0; b < N; b++) if(I.count(b)) {
        QT p = {1, 0};
        for(int i = b; i < N; i++) {
            QT q = {1, 0};
            q.type = t[i] - 'i' + 1;
            p = p * q;
            if(K.count(i+1) && p.sign == 1 && p.type == 2) {
                // if(N < 100) cout << "[" << b << "," << i+1 << ") = I" << endl;
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
    cout << (ok ? "YES" : "NO") << endl;
}
int main(){
    iostream_init();
    int T;
    cin >> T;
    for(int casenum = 1; casenum <= T; casenum++) {
        cout << "Case #" << casenum << ": ";
        solve();
    }
    return 0;
}

/* vim:set foldmethod=marker: */

