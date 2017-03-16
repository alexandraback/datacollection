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

const int N = 1111;

int a, b, c, n;
int h1[N][N], h2[N][N], h3[N][N], id[N];
vector < pair < int, ii > > v, path, ans;

void dfs(int i, int res) {
    if(i == v.size()) {
        if(path.size() > ans.size()) {
            ans = path;
        }
        return;
    }
    int a = v[id[i]].first, b = v[id[i]].second.first, c = v[id[i]].second.second;
    if(h1[a][b] < n and h2[a][c] < n and h3[b][c] < n) {
        h1[a][b]++;
        h2[a][c]++;
        h3[b][c]++;
        path.push_back(v[id[i]]);
        dfs(i + 1, res + 1);
        path.pop_back();
        h1[a][b]--;
        h2[a][c]--;
        h3[b][c]--;
    }
    else {
        dfs(i + 1, res);
    }
}

void solve() {
    scanf("%d %d %d %d", &a, &b, &c, &n);
    v.clear();
    ans.clear();
    path.clear();
    for(int i = 1; i <= a; i++)
        for(int j = 1; j <= b; j++)
            for(int k = 1; k <= c; k++)
                v.push_back({i, {j, k}});
    for(int i = 0; i < v.size(); i++)
        id[i] = i;
    int cnt = 1000;
    while(cnt--) {
        dfs(0, 0);
        random_shuffle(id, id + v.size());
    }
    printf("%d\n", ans.size());
    for(auto tmp : ans) {
        int a = tmp.first, b = tmp.second.first, c = tmp.second.second;
        printf("%d %d %d\n", a, b, c);
    }
}

int main () {
    
    freopen("C-large.in.txt", "r", stdin);
    freopen("large.txt", "w", stdout);
    
    int t;
    
    scanf("%d", &t);
    
    for(int tt = 1; tt <= t; tt++) {
        printf("Case #%d: ", tt);
        solve();
    }
    
    return 0;
    
}