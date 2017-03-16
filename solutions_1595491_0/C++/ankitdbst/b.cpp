//      anks
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define debug(args...) dbg(),args
#define S(N) scanf("%d", &N)
#define SS(N) scanf("%s", N)
#define FOR(A,B,C) for(int A=B;A<C;++A)
#define RFOR(A,B,C) for(int A=B;A>=C;--A)
#define PB(A,B) A.push_back(B);
#define MEM(A,B) memset(A,B,sizeof(A))
#define MAX(A,B) ((A > B) ? A : B)
#define MIN(A,B) ((A < B) ? A : B)
#define MAXLIM 100000
#define MAXN 30
bool DBG;
struct dbg { template<typename T> dbg& operator , (const T& v) { if (DBG)
 cerr << v << " "; return *this; } ~dbg() { if (DBG) cerr << endl; } };

vector<int> nonsurp[MAXN+1], surp[MAXN+1];

bool check(int a, int b) {
    return (a <= 10 && b <= 10);
}

void recordn(int a, int b, int c, int i) {
    PB(nonsurp[i], a); PB(nonsurp[i], b); PB(nonsurp[i], c);
}

void records(int a, int b, int c, int i) {
    PB(surp[i], a); PB(surp[i], b); PB(surp[i], c);
}

void preprocess() {
    int a, b, c, d;
    FOR(i, 0, MAXN+1) {
        a = i/3;
        d = i-a;
        if ((d+1) % 2 == 0) {
            b = (d-1)/2;
            c = (d+1)/2;
            if (check(b, c)) {
                recordn(a, b, c, i);
            }
        }
        if (d % 2 == 0) {
            b = c = d/2;
            if (check(b, c)) {
                recordn(a, b, c, i);
            }
        }
        if ((d+2) % 2 == 0 && i) {
            b = (d-2)/2;
            c = (d+2)/2;
            if (check(b, c)) {
                records(a, b, c, i);
            }
        }
    }
}

void printM() {

    debug("NON SURPRISING");

    FOR(i, 0, MAXN+1) {
        if (nonsurp[i].size() > 0) {
            debug("CASE:", i);
            debug(nonsurp[i][0], nonsurp[i][1], nonsurp[i][2]);
        }
        debug("");
    }

    debug("SURPRISING");

    FOR(i, 0, MAXN+1) {
        if (surp[i].size() > 0) {
            debug("CASE:", i);
            debug(surp[i][0], surp[i][1], surp[i][2]);
        }
        debug("");
    }
}

int getmaxn(int n) {
    int max = 0;
    FOR(i, 0, 3) {
        max = MAX(nonsurp[n][i], max);
    }
    return max;
}

int getmaxs(int n) {
    int max = 0;
    FOR(i, 0, 3) {
        max = MAX(surp[n][i], max);
    }
    return max;
}

int main (int argc, char *argv[]) {
    DBG = (argc > 1 && *argv[1]);

    preprocess();
    printM();

    int t;
    S(t);

    FOR(l, 0, t) {
        int n, s, p, count = 0;
        S(n); S(s); S(p);
        int A[n];
        FOR(i, 0, n) {
            S(A[i]);
            int k1 = getmaxn(A[i]);
            if (k1 >= p) {
                debug("NS:", A[i]);
                count++;
            } else {
                if (s > 0 && surp[A[i]].size() > 0) {
                    int k2 = getmaxs(A[i]);
                    if (k2 >= p) {
                        debug("S:", A[i]);
                        count++;
                        s--;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", l+1, count);
    }

    return 0;
}
