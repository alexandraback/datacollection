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

#define FOR(i,a,b) for(auto i=(a);i<(b);i++)
#define REVERSE(i,a,b) for(auto i=(a);i>=(b);i--)
#define REP(i,N) FOR(i,0,N)
#define ALL(A) A.begin(),A.end()
#define EACH(it,A) for(auto &it : A)

int G[4]={0,1,0,-1},
    H[4]={1,0,-1,0};

typedef pair<int,int> point;
typedef vector<point> VP;
typedef vector<int> VI;

void normalize(VP &A) {
    int mi_first = INT_MAX;
    int mi_second = INT_MAX;
    EACH(p,A) {
        mi_first = min(mi_first,p.first);
        mi_second = min(mi_second,p.second);
    }
    EACH(p,A) {
        p.first -= mi_first;
        p.second -= mi_second;
    }
    sort(ALL(A));
}

vector<VP> build_xomino(int X) {
    vector<VP> ret;
    function<void(int,VP,VP)> fun = [&](int level, VP consider, VP scratch) -> void {
        if(level == X) {
            normalize(scratch);
            ret.push_back(scratch);
            return;
        }
        EACH(p,consider) {
            VP new_scratch = scratch;
            VP new_consider = consider;
            new_scratch.push_back(p);
            new_consider.erase(find(ALL(new_consider),p));
            FOR(k,0,4) {
                point new_p = make_pair(p.first+G[k],p.second+H[k]);
                if(find(ALL(new_consider),new_p) == new_consider.end() &&
                    find(ALL(new_scratch),new_p) == new_scratch.end()) {
                    new_consider.push_back(new_p);
                }
            }
            fun(level+1,new_consider,new_scratch);
        }
    };
    fun(0,VP(1,point(0,0)),VP(0));
    sort(ALL(ret));
    ret.resize(unique(ALL(ret)) - ret.begin());
    return ret;
}

vector<VI> build_EC_matrix(vector<VP> &xominos, int R, int C, VI &row_xid) {
    auto enc = [=](int r, int c) -> decltype(r*R + c) { return r*C + c; };
    vector<VI> ret;
    FOR(i,0,R) FOR(j,0,C) FOR(k,0,xominos.size()) {
        auto fit = [=](point p)->bool{return i+p.first < R && j+p.second < C;};
        if(all_of(ALL(xominos[k]),fit)) {
            VI row(R*C,0);
            EACH(p,xominos[k]) row[enc(i+p.first,j+p.second)] = 1;
            ret.push_back(row);
            row_xid.push_back(k);
        }
    }
    return ret;
}

struct one_obj;

struct one_obj {
    one_obj *left;
    one_obj *right;
    one_obj *up;
    one_obj *down;
    one_obj *col;
    int size;
};

typedef vector<one_obj *> VOO;

one_obj* build_DLX_DS(vector<VI> &ec_mat, VOO &row_hooks) {
    assert(ec_mat.size() > 0);
    int R = ec_mat.size(), C = ec_mat[0].size();
    vector<VOO> tmp(R,VOO(C,NULL));
    FOR(i,0,R) {
        one_obj *la = NULL;
        FOR(j,0,C) if(ec_mat[i][j]) {
            tmp[i][j] = new one_obj;
            one_obj &t = *(tmp[i][j]);
            if(la == NULL) {
                t.left = tmp[i][j];
                t.right = tmp[i][j];
                t.size = 0;
            } else {
                t.left = la;
                t.right = la->right;
                la->right = tmp[i][j];
                t.right->left = tmp[i][j];
            }
            la = tmp[i][j];
        }
        row_hooks.push_back(la);
    }
    vector<one_obj *> co(C+1,NULL);
    FOR(i,0,C+1) co[i] = new one_obj;
    FOR(i,0,C+1) {
        auto left_i = [=](int i) -> int{return (i+C)%(C+1);};
        auto right_i = [=](int i) -> int{return (i+1)%(C+1);};
        co[i]->left = co[left_i(i)];
        co[i]->right = co[right_i(i)];
        co[i]->up = co[i];
        co[i]->down = co[i];
        co[i]->col = co[i];
        co[i]->size = 0;
    }
    FOR(i,0,C) {
        one_obj *la = co[i];
        FOR(j,0,R) if(ec_mat[j][i]) {
            one_obj &t = *(tmp[j][i]);
            t.up = la;
            t.down = la->down;
            la->down = tmp[j][i];
            t.down->up = tmp[j][i];
            t.col = la->col;
            t.col->size++;
            la = tmp[j][i];
        }
    }
    return co[C];
}

void cleanup_DLX_DS(one_obj *H) {
    auto cur = H->right;
    while(cur != H) {
        auto ro = cur->down;
        while(ro != cur) {
            auto new_ro = ro->down;
            delete ro;
            ro = new_ro;
        }
        auto new_cur = cur->right;
        delete ro;
        cur = new_cur;
    }
    delete cur;
}

bool dance_dance(one_obj *H, one_obj *cover_this_row_first) {
    auto chooseC = [=]() -> one_obj* {
        one_obj *minC = H->right;
        for(auto c = H->right; c != H; c = c->right) {
            if(c->size < minC->size) minC = c;
        }
        return minC;
    };
    auto cover = [](one_obj *C) -> void {
        C->right->left = C->left;
        C->left->right = C->right;
        for(auto i = C->down; i != C; i = i->down)
            for(auto j = i->right; j != i; j = j->right) {
                j->down->up = j->up;
                j->up->down = j->down;
                j->col->size--;
            }
    };
    auto uncover = [](one_obj *C) -> void {
        for(auto i = C->up; i != C; i = i->up)
            for(auto j = i->left; j != i; j = j->left) {
                j->col->size++;
                j->down->up = j;
                j->up->down = j;
            }
        C->right->left = C;
        C->left->right = C;
    };

    if(cover_this_row_first != NULL) {
        one_obj *R = cover_this_row_first;
        cover(R->col);
        for(auto nC = R->right; nC != R; nC = nC->right) cover(nC->col);
        auto retVal = dance_dance(H,NULL);
        for(auto nC = R->left; nC != R; nC = nC->left) uncover(nC->col);
        uncover(R->col);
        return retVal;
    }

    assert(cover_this_row_first == NULL);
    if(H->right == H) return true;
    one_obj *C = chooseC();
    if(C->size == 0) return false;
    bool retVal = false;
    cover(C);
    for(auto R = C->down; R != C && !retVal; R = R->down) {
        for(auto nC = R->right; nC != R; nC = nC->right) cover(nC->col);
        retVal = dance_dance(H,NULL);
        for(auto nC = R->left; nC != R; nC = nC->left) uncover(nC->col);
    }
    uncover(C);
    return retVal;
}

map<int,int> xomino_ec(vector<VP> &T, int &uniq) {
    auto rotateLeft = [](VP &A) -> VP {
        VP B(A.size());
        auto map_point = [](point p)->point{return point(-p.second,p.first);};
        transform(ALL(A),B.begin(),map_point);
        normalize(B);
        return B;
    };
    auto reflectAlongXAxis = [](VP &A) -> VP {
        VP B(A.size());
        auto map_point = [](point p)->point{return point(p.first,-p.second);};
        transform(ALL(A),B.begin(),map_point);
        normalize(B);
        return B;
    };
    map<VP,int> _M;
    FOR(i,0,T.size()) _M[T[i]] = i;
    map<int,int> M; int k = 0;
    FOR(i,0,T.size()) if(M.find(i) == M.end()) {
        M[i] = k;
        VP t = T[i];
        REP(tmp,3) {
            t = rotateLeft(t);
            M[_M[t]] = k;
        }
        t = rotateLeft(t);
        t = reflectAlongXAxis(t);
        REP(tmp,4) {
            t = rotateLeft(t);
            M[_M[t]] = k;
        }
        k++;
    }
    uniq = k;
    return M;
}

void do_case(int case_number) {
    int X, R, C;
    cin >> X >> R >> C;

    auto isValid = [=]() -> bool {
        if(X > 6) return false;
        if(X > max(R,C)) return false;
        if(R*C % X != 0) return false;
        return true;
    };

    if(isValid()) {
        auto T = build_xomino(X);
    
        VI row_xid;
        auto ec_mat = build_EC_matrix(T,R,C,row_xid);
        if(ec_mat.size()) {

            VOO row_hooks;
            auto H = build_DLX_DS(ec_mat,row_hooks);

            VI can_do(T.size(),0);
            FOR(i,0,row_xid.size()) {
                if(dance_dance(H,row_hooks[i])) can_do[row_xid[i]] = 1;
            }

            cleanup_DLX_DS(H);

            int uniq;
            auto M = xomino_ec(T,uniq);
            VI matters_can_do(uniq,0);
            FOR(i,0,can_do.size()) if(can_do[i]) matters_can_do[M[i]] = 1;
            if(accumulate(ALL(matters_can_do),0) != uniq) goto not_possible;

            cout << "Case #" << case_number << ": GABRIEL" << endl;
            return;

        }
    }

not_possible:
    cout << "Case #" << case_number << ": RICHARD" << endl;
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
