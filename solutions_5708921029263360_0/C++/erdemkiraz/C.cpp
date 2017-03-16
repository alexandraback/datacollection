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

const int N = 5;

int a, b, c, n, ans, ansMask;
int h1[N][N], h2[N][N], h3[N][N];
vector < pair < int, ii > > v;

void dfs(int i, int res, int mask) {
    if(i == v.size()) {
        if(res > ans) {
            ans = res;
            ansMask = mask;
        }
        return;
    }
    dfs(i + 1, res, mask);
    int a = v[i].first, b = v[i].second.first, c = v[i].second.second;
    if(h1[a][b] < n and h2[a][c] < n and h3[b][c] < n) {
        h1[a][b]++;
        h2[a][c]++;
        h3[b][c]++;
        dfs(i + 1, res + 1, mask | (1 << i));
        h1[a][b]--;
        h2[a][c]--;
        h3[b][c]--;
    }
}

void solve() {
    scanf("%d %d %d %d", &a, &b, &c, &n);
    v.clear();
    ans = ansMask = 0;
    for(int i = 1; i <= a; i++)
        for(int j = 1; j <= b; j++)
            for(int k = 1; k <= c; k++)
                v.push_back({i, {j, k}});
    dfs(0, 0, 0);
    printf("%d\n", ans);
    for(int i = 0; i < v.size(); i++) {
        if(ansMask & (1 << i)) {
            int a = v[i].first, b = v[i].second.first, c = v[i].second.second;
            printf("%d %d %d\n", a, b, c);
        }
    }
}

int main () {
    
    freopen("C-small-attempt1.in.txt", "r", stdin);
    freopen("small.txt", "w", stdout);
    
    int t;
    
    scanf("%d", &t);
    
    for(int tt = 1; tt <= t; tt++) {
        printf("Case #%d: ", tt);
        solve();
    }
    
    return 0;
    
}