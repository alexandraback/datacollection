//#pragma comment(linker,"/STACK:100000000000,100000000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
#include <functional>
#include <list>
#include <sstream>
#include <ctime>
#include <climits>
#include <bitset>
#include <list>
#include <cassert>
#include <complex>

using namespace std;

/* Constants begin */
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-12;
const double PI = 2*acos(0.0);
const double E = 2.71828;
/* Constants end */

/* Defines begin */
#define pb push_back
#define mp make_pair
#define ll long long
#define double long double
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define forn(i,n) for (int (i)=0; (i)<(n); ++(i))
#define random (rand()<<16|rand())
#define sqr(x) (x)*(x)
#define base complex<double>
/* Defines end */

struct qua {
    char c;
    int sign;

    qua() {c = '1'; sign = 1;}
    qua(char c, int sign): c(c), sign(sign) {}
};

qua mul(qua a, qua b) {
    qua res;
    if (a.c == '1') {
        res.c = b.c;
        res.sign = a.sign * b.sign;
        return res;
    }
    if (b.c == '1') {
        res.c = a.c;
        res.sign = a.sign * b.sign;
        return res;
    }
    if (a.c == 'i' && b.c == 'j') res.c = 'k', res.sign = a.sign * b.sign;
    if (a.c == 'j' && b.c == 'k') res.c = 'i', res.sign = a.sign * b.sign;
    if (a.c == 'k' && b.c == 'i') res.c = 'j', res.sign = a.sign * b.sign;
    if (a.c == 'j' && b.c == 'i') res.c = 'k', res.sign = -a.sign * b.sign;
    if (a.c == 'k' && b.c == 'j') res.c = 'i', res.sign = -a.sign * b.sign;
    if (a.c == 'i' && b.c == 'k') res.c = 'j', res.sign = -a.sign * b.sign;
    if (a.c == 'i' && b.c == 'i') res.c = '1', res.sign = -a.sign * b.sign;
    if (a.c == 'j' && b.c == 'j') res.c = '1', res.sign = -a.sign * b.sign;
    if (a.c == 'k' && b.c == 'k') res.c = '1', res.sign = -a.sign * b.sign;
    return res;
}

int t;
int n, x;
char s[10005];

void Solve() {
    scanf("%d %d %s", &n, &x, s); --x;
    int fs = -1, sd = -1;
    qua now;
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            s[j + i * n] = s[j];
        }
    }
    n += n * x;
    for (int i = 0; i < n; ++i) {
        qua w = qua(s[i], 1);
        now = mul(now, w);
        if (now.c == 'i' && fs < 0) fs = i;
    }
    if (now.c != '1' || now.sign > 0) {
        puts("NO");
        return;
    }
    now = qua('1', 1);
    for (int i = n - 1; i >= 0; --i) {
        qua w = qua(s[i], 1);
        now = mul(w, now);
        if (now.c == 'k' && sd < 0) sd = i;
    }
    if (fs >= 0 && sd >= 0 && fs < sd) {
        puts("YES");
    } else {
        puts("NO");
    }
}

int main(void){
    #ifdef nobik
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        Solve();
    }
    return 0;
}
