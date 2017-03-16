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
int n; long long x;
char s[10005];
int pf[4], sf[4];

void Solve() {
    long long x;
    scanf("%d", &n);
    cin >> x;
    scanf(" %s", s);
    --x;
    qua now, r;
    for (int i = 0; i < n; ++i) {
        qua w = qua(s[i], 1);
        now = mul(now, w);
    }
    r = now;
    for (int i = 0; i < x % 4; ++i) {
        now = mul(now, r);
    }
    if (now.c != '1' || now.sign > 0) {
        puts("NO");
        return;
    }
    for (int e = 0; e < 4; ++e) {
        pf[e] = sf[e] = -1;
    }

    now = qua('1', 1);
    for (int i = 0; i < n; ++i) {
        qua w = qua(s[i], 1);
        now = mul(now, w);
        qua cn = now;
        for (int e = 0; e < 4; ++e) {
            if (cn.c == 'i' && pf[e] < 0) {
                pf[e] = i;
            }
            cn = mul(cn, r);
        }
    }

    now = qua('1', 1);
    for (int i = n - 1; i >= 0; --i) {
        qua w = qua(s[i], 1);
        now = mul(w, now);
        qua cn = now;
        for (int e = 0; e < 4; ++e) {
            if (cn.c == 'k' && sf[e] < 0) {
                sf[e] = i;
            }
            cn = mul(cn, r);
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (pf[i] < 0 || sf[j] < 0) {
                continue;
            }
            int add = (pf[i] >= sf[j]);
            if (x >= i + j + add) {
                puts("YES");
                return;
            }
        }
    }

    puts("NO");
}

void check() {
    string a[105], b[105], s;
    for (int i = 0; i < 100; ++i) {
        getline(cin, s);
        a[i] = s;
    }
    for (int i = 0; i < 100; ++i) {
        getline(cin, s);
        b[i] = s;
    }
    for (int i = 0; i < 100; ++i) {
        if (a[i] != b[i]) {
            cout << a[i] << "\n" << b[i] << "\n\n";
        }
    }
    exit(0);
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
