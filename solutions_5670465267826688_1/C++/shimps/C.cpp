#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdint>
#include <ctime>
#include <cmath>
#include <climits>
#include <cassert>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <tuple>
#include <iterator>
#include <functional>
#include <numeric>
#include <complex>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <regex>
using namespace std;

#include <gmpxx.h>

typedef long long ll;

#define FOR(i,a,b) for(auto i=(a);i<(b);i++)
#define REVERSE(i,a,b) for(auto i=(a);i>=(b);i--)
#define REP(i,N) FOR(i,0,N)
#define ALL(A) A.begin(),A.end()
#define EACH(it,A) for(auto const &it : A)

typedef pair<int,char> QAT;
QAT make_quat(int sign, char sym) {
    assert(sign == 1 || sign == -1);
    assert(sym == '1' || sym == 'i' || sym == 'j' || sym == 'k');
    return make_pair(sign,sym);
}
QAT mul_pos_quat(char sym_1, char sym_2) {
    switch(sym_1) {
    case '1':
        switch(sym_2) {
        case '1':
            return make_quat(1,'1');
        case 'i':
            return make_quat(1,'i');
        case 'j':
            return make_quat(1,'j');
        case 'k':
            return make_quat(1,'k');
        default:
            assert(false);
        }
    case 'i':
        switch(sym_2) {
        case '1':
            return make_quat(1,'i');
        case 'i':
            return make_quat(-1,'1');
        case 'j':
            return make_quat(1,'k');
        case 'k':
            return make_quat(-1,'j');
        default:
            assert(false);
        }
    case 'j':
        switch(sym_2) {
        case '1':
            return make_quat(1,'j');
        case 'i':
            return make_quat(-1,'k');
        case 'j':
            return make_quat(-1,'1');
        case 'k':
            return make_quat(1,'i');
        default:
            assert(false);
        }
    case 'k':
        switch(sym_2) {
        case '1':
            return make_quat(1,'k');
        case 'i':
            return make_quat(1,'j');
        case 'j':
            return make_quat(-1,'i');
        case 'k':
            return make_quat(-1,'1');
        default:
            assert(false);
        }
    default:
        assert(false);
    }
    return make_quat(0,'z');
}
QAT mul_quat(QAT A, QAT B) {
    QAT T = mul_pos_quat(A.second,B.second);
    T.first *= A.first;
    T.first *= B.first;
    return T;
}

bool solve_very_simple(int N, QAT T[]) {
    map<QAT,int> le, ri;

    QAT cu = make_quat(1,'1');
    bool found_i = false;
    FOR(i,0,N) {
        cu = mul_quat(cu,T[i]);
        if(found_i) {
            if(le.find(cu) == le.end()) le[cu] = i;
        } else if(cu == make_quat(1,'i')) {
            found_i = true;
            cu = make_quat(1,'1');
            if(le.find(cu) == le.end()) le[cu] = i;
        }
    }

    cu = make_quat(1,'1');
    bool found_k = false;
    REVERSE(i,N-1,0) {
        cu = mul_quat(T[i],cu);
        if(found_k) {
            if(ri.find(cu) == ri.end()) ri[cu] = i;
        } else if(cu == make_quat(1,'k')) {
            found_k = true;
            cu = make_quat(1,'1');
            if(ri.find(cu) == ri.end()) ri[cu] = i;
        }
    }

    EACH(ii,le) EACH(jj,ri) if(ii.second <= jj.second) {
        cu = ii.first;
        FOR(i,ii.second+1,jj.second) cu = mul_quat(cu,T[i]);
        cu = mul_quat(cu,jj.first);
        if(cu == make_quat(1,'j')) return true;
    }
    return false;
}

bool solve_simple(int L, int X, const string &A) {
    assert(X<=8);
    QAT* T = new QAT[X*L];
    int k = 0;
    REP(i,X) REP(j,L) {
        T[k] = make_quat(1,A[j]);
        k++;
    }
    bool res = solve_very_simple(k,T);
    delete T;
    return res;
}

bool solve_hard(int L, ll X, string &A) {
    assert(X>8);

    QAT tot = make_quat(1,'1');
    REP(i,L) tot = mul_quat(tot,make_quat(1,A[i]));
    QAT mid = make_quat(1,'1');
    REP(i,(X-8)%4) mid = mul_quat(mid,tot);

    QAT* T = new QAT[8*L + 1];
    int k = 0;
    REP(i,4) REP(j,L) {
        T[k] = make_quat(1,A[j]);
        k++;
    }
    T[k] = mid;
    k++;
    REP(i,4) REP(j,L) {
        T[k] = make_quat(1,A[j]);
        k++;
    }
    bool res = solve_very_simple(k,T);
    delete T;
    return res;
}

void do_case(int case_number) {
    int L; ll X; cin >> L >> X;
    string A; cin >> A;

    bool res = X>8?solve_hard(L,X,A):solve_simple(L,(int)X,A);
    cout << "Case #" << case_number << ": " << (res?"YES":"NO") << endl;
}

int main(int argc, char** argv) {
    if(argc > 1) {
        auto fname_in = string(argv[1]) + ".in";
        auto fname_out = string(argv[1]) + ".out";
        freopen(fname_in.c_str(), "r", stdin);
        freopen(fname_out.c_str(), "w", stdout);
    }
    int T, te = 1;
    cin >> T;
    while(T--) {
        do_case(te);
        te++;
    }
    return 0;
}
