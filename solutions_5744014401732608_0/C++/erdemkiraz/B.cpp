#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "cstring"
#include "string"
#include "vector"
#include "cassert"
#include "queue"
#include "cstdio"
#include "cstdlib"
#include "ctime"
#include "cmath"
#include "bitset"

using namespace std;

typedef long long ll;
typedef pair < int, int > ii;

int n;
ll m, val[100];
char h[100][100];

void add(int x, int y) {
    h[x][y] = '1';
}

void solve() {
    memset(val, 0, sizeof(val));
    scanf("%d %lld", &n, &m);
    memset(h, 0, sizeof(h));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            h[i][j] = '0';
    int bit = 0;
    while((1LL << bit) <= m)
        bit++;
    bit--;
    val[n] = 1;
    for(int i = n - 1; i > 1; i--) {
        for(int j = i + 1; j <= n; j++) {
            val[i] += val[j];
            add(i, j);
        }
    }
    for(int i = 2; i <= n; i++) {
        if(val[i] <= m) {
            add(1, i);
            m -= val[i];
        }
    }
    if(m) {
        puts("IMPOSSIBLE");
    }
    else {
        puts("POSSIBLE");
        for(int i = 1; i <= n; i++)
            puts(h[i] + 1);
    }
}

int main () {
    
    freopen("B-small-attempt0.in.txt", "r", stdin);
    freopen("small.txt", "w", stdout);
    
    int t;
    
    scanf("%d", &t);
    
    for(int tt = 1; tt <= t; tt++) {
        printf("Case #%d: ", tt);
        solve();
    }
    
    return 0;
    
}