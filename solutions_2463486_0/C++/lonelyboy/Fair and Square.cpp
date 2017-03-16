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

template<typename T>
T bsrch(T beg, T end, std::function<int(T)> f) {
	T mid;
	while(beg < end) {
		mid = (beg + end) / 2;
		if(f(mid)) {
			end = mid;
		} else {
			beg = mid + 1;
		}
	}
	return end;
}

ull db[20000000], dt[20000000], top;

int g(ull x) {
    static int w[100], len;
    len = 0;
    while(x) {
        w[len] = x % 10;
        x /= 10;
        len++;
    }
    REP(i, 0, (len + 1) / 2) if(w[i] != w[len - 1 - i]) return 0;
    return 1;
}

int f(ull x) {
    if(g(x) && g(x * x)) return 1;
    return 0;
}
int MAXN = 10000100;
int main() {
    top = 0;
    REP(i, 1, MAXN) {
        if(f(i)) {
            dt[top++] = i;
            //cout << i << endl;
        }
    }
    //puts("OK");
    //getchar();
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int t;
    cin >> t;
    REP(tt, 1, t + 1) {
        ull a, b;
        int x, y;
        cin >> a >> b;
        x = bsrch<int>(0, top, [&](int mid) {
            if(dt[mid] * dt[mid] >= a) return 1;
            return 0;
        });
        y = bsrch<int>(0, top, [&](int mid) {
            if(dt[mid] * dt[mid] > b) return 1;
            return 0;
        });
        printf("Case #%d: %d\n", tt, y - x);
    }

    return 0;
}
