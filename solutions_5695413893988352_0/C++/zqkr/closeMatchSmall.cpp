#pragma region Template
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <vector>
#include <list>
#include <utility>
#include <functional>
#include <algorithm>
#include <set>
#include <stack>
#include <cassert>
#include <cctype>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define SZ(a)        ((int)a.size())
#define LENGTH(a)    ((int)a.length())
#define ALL(a)       a.begin(), a.end()
#define REP(i, n)    for(int i = 0; i < (n); i++)
#define INC(i, a, b) for(int i = (a); i <= (b); i++)
#define DEC(i, a, b) for(int i = (a); i >= (b); i--)
#define CLEAR(a, b)  memset(a, b, sizeof a)
#define X            first
#define Y            second
#define si(a)        scanf("%d", &a)
#define ss(a)        scanf("%s", a)
#define sll(a)       scanf("%lld", &a)

typedef long long int LL;

const double PI = acos(-1.0);
const double EPS = 1e-9;
const int    inf = 1000000000;
const LL     INF = ((LL)inf)*inf;
#pragma endregion

#define LIM 50

char cstr[LIM], jstr[LIM];
int cc, jj, mnn = 1000;

void ffind(int k, int ck, int jk) {
    if(cstr[k] == 0) {
        if(mnn > abs(ck-jk)) {
            mnn = abs(ck-jk);
            cc = ck;
            jj = jk;
        }
        else if(mnn == abs(ck-jk)) {
            if((cc == ck && jj > jk) || cc > ck) {
                mnn = abs(ck-jk);
                cc = ck;
                jj = jk;
            }
        }
    }
    REP(pic, 10) {
        if(cstr[k] != '?' && pic != cstr[k] - '0') continue;
        REP(pij, 10) {
            if(jstr[k] != '?' && pij != jstr[k] -'0') continue;
            ffind(k+1, ck*10+pic, jk*10+pij);
        }
    }
}

int main(void) {
    int tcase; si(tcase);
    REP(_i, tcase) {
        ss(cstr); ss(jstr);
        int len = strlen(cstr);
        ffind(0, 0, 0);
        mnn = 1000;
        if(len == 1) printf("Case #%d: %d %d\n", _i+1, cc, jj);
        else if(len == 2) printf("Case #%d: %02d %02d\n", _i+1, cc, jj);
        else if(len == 3) printf("Case #%d: %03d %03d\n", _i+1, cc, jj);
    }
}
