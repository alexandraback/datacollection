#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define MP(x, y) make_pair((x),(y))
#define FI first
#define SE second
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
#define HEIGHT(n) (sizeof(int) * 8 - __builtin_clz(n)) //height of range n segment tree
typedef long long llong;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> inline T min(T a, T b, T c) {return min(min(a,b),c);}
template<class T> inline T min(T a, T b, T c, T d) {return min(min(a,b),min(c,d));}
template<class T> inline T max(T a, T b, T c) {return max(max(a,b),c);}
template<class T> inline T max(T a, T b, T c, T d) {return max(max(a,b),max(c,d));}
const int INF = 1e9;
const llong INF_LL = 4e18;
const double pi = acos(-1.0);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 51
struct Info {
    int flag, id; // flag=0, row; flag=1, col;
};

int h[N][N], n;
int rec[N << 1][N];
bool used[2][N];
Info info[N << 1];

bool check_fill(int p, int flag, int id) {
    if (flag == 0) {
        for (int c=0; c<n; c++) if (h[id][c] != -1) {
            if (h[id][c] != rec[p][c]) return false;
        }
        for (int c=0; c<n; c++) {
            for (int r=0; r<id; r++) if (h[r][c] != -1) {
                if (h[r][c] >= rec[p][c]) return false;
            }
        }
        for (int c=0; c<n; c++) h[id][c] = rec[p][c];
        return true;
    } else {
        for (int r=0; r<n; r++) if (h[r][id] != -1) {
            if (h[r][id] != rec[p][r]) return false;
        }
        for (int r=0; r<n; r++) {
            for (int c=0; c<id; c++) if (h[r][c] != -1) {
                if (h[r][c] >= rec[p][r]) return false;
            }
        }
        for (int r=0; r<n; r++) h[r][id] = rec[p][r];
        return true;
    }
}

void cancel_fill(int flag, int id) {
    if (flag == 0) {
        for (int c=0; c<n; c++) if (!used[1][c]) h[id][c] = -1;
    } else {
        for (int r=0; r<n; r++) if (!used[0][r]) h[r][id] = -1;
    }
}

void Print(int flag, int id) {
    if (flag == 0) {
        for (int c=0; c<n; c++) printf(" %d", h[id][c]);
    } else {
        for (int r=0; r<n; r++) printf(" %d", h[r][id]);
    }
    printf("\n");
}

void PrintH() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) printf(" %d", h[i][j]);
        printf("\n");
    }
}

bool dfs(int p) {
    if (p == 2*n-1) {
        //PrintH();
        return true;
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<n; j++) if (!used[i][j] && check_fill(p, i, j)) {
            //printf("fill %d, i:%d j:%d\n", p, i, j);
            //PrintH();
            used[i][j] = true;
            info[p] = Info{i, j};
            if (dfs(p+1)) return true;
            used[i][j] = false;
            cancel_fill(i, j);
        }
    }
    return false;
}

void solve() {
    memset(h, -1, sizeof(h));
    memset(used, false, sizeof(used));
    dfs(0);
    memset(used, false, sizeof(used));
    for (int i=0; i<(2*n-1); i++) {
        used[info[i].flag][info[i].id] = true;
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<n; j++) if (!used[i][j]) {
            Print(i, j);
            return;
        }
    }
}

int main() {
    freopen("test.in", "r", stdin);
    int cas;
    cin >> cas;
    for (int i=1; i<=cas; i++) {
        cin >> n;
        for (int j=0; j<(2*n-1); j++) {
            for (int k=0; k<n; k++) scanf("%d", & rec[j][k]);
        }
        printf("Case #%d:", i);
        solve();
    }
    return 0;
}
