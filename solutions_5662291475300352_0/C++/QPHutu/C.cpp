#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <queue>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <ctime>
using namespace std;

#define PII pair<int,int> 
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define lid (id << 1)
#define rid (id << 1 | 1)
#define MID(a, b) ((a + b) >> 1)

const int N = 100010;
const int INF = 1000000000;
const int Mod = 1000000007;
const int maxn = 10;
const double PI = acos(-1.0);
const double eps = 1e-6;

int n, m, D[N], H[N], M[N];
int x[N], v[N];

void solve() {
    scanf("%d", &n); m = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d%d%d", &D[i], &H[i], &M[i]);
        for(int j = 1; j <= H[i]; j++) {
            x[m + j] = D[i]; 
            v[m + j] = M[i] + j - 1;
        }
        m += H[i];
    }
    if(m < 2) {
        puts("0");
        return;
    }
    if(v[1] == v[2]) {
        puts("0");
        return;
    }
    if(v[1] < v[2]) {
        swap(x[1], x[2]); swap(v[1], v[2]);
    }
    // printf("%d %d --> %d %d\n", x[1], v[1], x[2], v[2]);
    if(1LL * (360 + x[1] - x[2]) * v[2] + 1LL * (v[1] - v[2]) * x[1] > 1LL * 360 * (v[1] - v[2])) {
        puts("0");
        return;
    }
    puts("1");
}

int main() {
    freopen("C1.in", "r", stdin);
    freopen("C1.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}