#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

#define Rep(i,n) for(typeof(n) i = 0; i < (n); ++i)
#define Repd(i,n) for(typeof(n) i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(typeof(b) i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(typeof(a) i = (a); i >= (b); --i)
#define Fit(i,v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define nl puts("")
#define sp printf(" ")
#define ok puts("ok")

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> void db(T a, int p = -1) { if (p >= 0) cout << fixed << setprecision(p); cout << a << " "; }
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }
template<class T> struct Triple { T x, y, z; Triple() {} Triple(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {} };
template<class T> Triple<T> euclid(T a, T b) { if (b == 0) return Triple<T>(1, 0, a); Triple<T> r = euclid(b, a % b); return Triple<T>(r.y, r.x - a / b * r.y, r.z); }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return s == 0 ? 0 : cntbit(s >> 1) + (s & 1); }
const int bfsz = 1 << 16; char bf[bfsz + 5]; int rsz = 0;int ptr = 0;
char gc() { if (rsz <= 0) { ptr = 0; rsz = fread(bf, 1, bfsz, stdin); if (rsz <= 0) return EOF; } --rsz; return bf[ptr++]; }
void ga(char &c) { c = EOF; while (!isalpha(c)) c = gc(); }
int gs(char s[]) { int l = 0; char c = gc(); while (isspace(c)) c = gc(); while (c != EOF && !isspace(c)) { s[l++] = c; c = gc(); } s[l] = '\0'; return l; }
template<class T> bool gi(T &v) {
	v = 0; char c = gc(); while (c != EOF && c != '-' && !isdigit(c)) c = gc(); if (c == EOF) return false; bool neg = c == '-'; if (neg) c = gc();
    while (isdigit(c)) { v = v * 10 + c - '0'; c = gc(); } if (neg) v = -v; return true;
}

const double PI = 2 * acos(0);
const string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dr[] = {-1, 0, +1, 0};
const int dc[] = {0, +1, 0, -1};
const int drbishop[] = {-1, -1, +1, +1};
const int dcbishop[] = {-1, +1, +1, -1};
const int drknight[] = {-2, -2, -1, +1, +2, +2, +1, -1};
const int dcknight[] = {-1, +1, +2, +2, +1, -1, -2, -2};
const int inf = (int)1e9 + 5;
const ll linf = (ll)1e16 + 5;
const double eps = 1e-9;

#define maxn 2005

int n, ibest, jbest, ihave, stars[maxn][3];
bool completed[maxn][3];

bool found() {
    ibest = jbest = -1;
    
    For(i, 1, n) {
        if (!completed[i][1] && !completed[i][2] && ihave >= stars[i][2]) {
            ibest = i;
            jbest = 2;
            return true;
        }
    }

    For(i, 1, n) {
        if (!completed[i][2] && ihave >= stars[i][2]) {
            ibest = i;
            jbest = 2;
            return true;
        }
    }

    For(i, 1, n) {
        if (!completed[i][1] && !completed[i][2] && ihave >= stars[i][1]) {
            if (ibest == -1 || stars[ibest][2] < stars[i][2]) {
                ibest = i;
                jbest = 1;
            }
        }
    }
    
    return ibest != -1;
}

int doit() {
    ms(completed, false);
    
    int total = 0;
    ihave = 0;
    
    while (found()) {
        ++total;
        if (jbest == 1) {
            ++ihave;
            completed[ibest][1] = true;
        }
        else {
            if (!completed[ibest][1]) ihave += 2;
            else ihave += 1;
            completed[ibest][1] = completed[ibest][2] = true;
        }
    }
    
    For(i, 1, n) if (!completed[i][2]) return -1;
    return total;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int ntest;
    cin >> ntest;
    
    For(test, 1, ntest) {
        cin >> n;
        For(i, 1, n) cin >> stars[i][1] >> stars[i][2];
        
        int res = doit();
        
        printf("Case #%d: ", test);
        if (res == -1) puts("Too Bad");
        else printf("%d\n", res);
    }
    
    return 0;
}
