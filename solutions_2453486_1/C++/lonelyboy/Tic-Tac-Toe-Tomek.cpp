#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iterator>
#define REP(i,a,n) for(int i = (a); i < (int)(n); ++i)
#define foreach(itr,c) for(decltype((c).begin()) itr=(c).begin(); itr != (c).end(); itr++)

using namespace std;

//typedef __int64 ll;
//typedef unsigned __int64 ull;
typedef long long ll;
typedef unsigned long long ull;

template<typename T>
inline T ABS(T a) { return a > 0 ? a : -a; }
template<typename T>
inline T MIN(T a, T b) { return a < b ? a : b; }
template<typename T>
inline T MAX(T a, T b) { return a > b ? a : b; }
template<typename T>
inline T CHKMIN(T &a, T b) { if(a > b) a = b; return a; }
template<typename T>
inline T CHKMAX(T &a, T b) { if(a < b) a = b; return a; }
template<typename T>
inline void SWAP(T &a, T &b) { static T c; c = a; a = b; b = c; }

template<typename T, typename... T0>
T MAX(T a, T b, T0... c) { return a > b ? MAX(a, c...) : MAX(b, c...); }
template<typename T, typename... T0>
T MIN(T a, T b, T0... c) { return a < b ? MIN(a, c...) : MIN(b, c...); }

template<typename T, int n>
void myin(T a[]) { REP(i, 0, n) cin >> a[i]; }
template<typename T>
void myin(T &a) { cin >> a; }

template<typename T>
void print(T a) { cout << a << ' '; }
template<typename T, typename... T0>
void print(T a, T0... b) { print(a); print(b...); }
template<typename T>
void println(T a) {cout << a << endl;}
template<typename T, typename... T0>
void println(T a, T0... b) { print(a); println(b...); }

char s[10][10];
int ans, dot;


int f() {
    int tmp;
    ans = dot = 0;
    REP(i, 0, 4) REP(j, 0, 4) if(s[i][j] == '.') ++dot;
    
    REP(i, 0, 4) {
        tmp = 0;
        REP(j, 0, 4) {
            tmp += s[i][j];
        }
        if(tmp == 3 * 'X' + 'T' || tmp == 4 * 'X') return 1;
        if(tmp == 3 * 'O' + 'T' || tmp == 4 * 'O') return 2;
    }
    REP(j, 0, 4) {
        tmp = 0;
        REP(i, 0, 4) {
            tmp += s[i][j];
        }
        if(tmp == 3 * 'X' + 'T' || tmp == 4 * 'X') return 1;
        if(tmp == 3 * 'O' + 'T' || tmp == 4 * 'O') return 2;
    }
    tmp = 0;
    REP(i, 0, 4) {
        tmp += s[i][i];
    }
    if(tmp == 3 * 'X' + 'T' || tmp == 4 * 'X') return 1;
    if(tmp == 3 * 'O' + 'T' || tmp == 4 * 'O') return 2;
    
    tmp = 0;
    REP(i, 0, 4) {
        tmp += s[i][3 - i];
    }
    if(tmp == 3 * 'X' + 'T' || tmp == 4 * 'X') return 1;
    if(tmp == 3 * 'O' + 'T' || tmp == 4 * 'O') return 2;
    
    if(dot == 0) return 3;
    else return 4;
}

char *out[4] = {"X won", "O won", "Draw", "Game has not completed"};

int main() {
    int t;
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.out", "w", stdout);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    cin >> t;
    REP(tt, 1, t + 1) {
        REP(i, 0, 4) scanf("%s", s + i);
        ans = f() - 1;
        printf("Case #%d: %s\n", tt, out[ans]);
        
    }
    return 0;
}
