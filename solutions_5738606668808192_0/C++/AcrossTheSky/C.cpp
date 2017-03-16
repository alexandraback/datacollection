/* Copyright 2016 AcrossTheSky */
#include <iostream>
#include <cstdio>
#include <utility>
#include <cassert>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)
#define RVC(i, c) fot (int i = 0; i < (c).size(); ++i)
#define RED(k, u) for (int k = head[(u)]; k; k = edge[k].next)
#define lowbit(x) ((x) & (-(x)))
#define CL(x, v) memset(x, v, sizeof x)
#define MP std::make_pair
#define PB push_back
#define FR first
#define SC second
#define rank rankk
#define next nextt
#define link linkk
#define index indexx
#define abs(x) ((x) > 0 ? (x) : (-(x)))
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

template<class T> inline
bool getmin(T *a, const T &b) {
    if (b < *a) {
        *a = b;
        return true;
    }
    return false;
}

template<class T> inline
bool getmax(T *a, const T &b) {
    if (b > *a) {
        *a = b;
        return true;
    }
    return false;
}

template<class T> inline
void read(T *a) {
    char c;
    while (isspace(c = getchar())) {}
    bool flag = 0;
    if (c == '-') flag = 1, *a = 0;
    else
        *a = c - 48;
    while (isdigit(c = getchar())) *a = *a * 10 + c - 48;
    if (flag) *a = -*a;
}
const int mo = 1000000007;
template<class T>
T pow(T a, T b, int c = mo) {
    T res = 1;
    for (T i = 1; i <= b; i <<= 1, a = 1LL * a * a % c) if (b & i) res = 1LL * res * a % c;
    return res;
}
/*======================= TEMPLATE =======================*/
int n, m;
int a[100];
int cnt;
void print() {
    PER(i, n - 1, 0) printf("%d", (a[i] | a[i - 1]));
    REP(i, 3, 11) printf(" %d", i);
    puts("");
}
bool dfs(int u) {
    if (u == n - 1) {
        if (a[0] && a[n - 2]) {
            print();
            if (++cnt == m) return true;
        }
        return false;
    }
    if (u == 0) {
        a[u] = 1;
        if (dfs(u + 1)) return true;
    }
    else {
        a[u] = 0;
        if (dfs(u + 1)) return true;
        if (!a[u - 1]) {
            a[u] = 1;
            if (dfs(u + 1)) return true;
        }
        a[u] = 0;
    }
}
int main() {
    int T;
    cin >> T;
    cin >> n >> m;
    printf("Case #1:\n");
    dfs(0);
    return 0;
}

