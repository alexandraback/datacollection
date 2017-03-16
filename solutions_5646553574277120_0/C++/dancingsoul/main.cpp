#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int M = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int v[100], f[100], V, n, m, x, found, CAS;

void Dfs(int x, int lim, int l){
    if (x == lim){
        for (int i = 1; i <= V; i++)
        if (!f[i]) return;
        found = 1;
        return;
    }
    for (int i = l; i <= V; i++)
    if (!v[i]){
        v[i] = 1;
        for (int j = V; j >= x; j--)
            f[j] += f[j - i];
        Dfs(x + 1, lim, i + 1);
        v[i] = 0;
        for (int j = 0; j <= V - x; j++)
            f[j + i] -= f[j];
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &CAS);
    for (int cas = 1; cas <= CAS; cas++){
        if (cas == 100){
            cas = 100;
        }
        scanf("%d%d%d", &m, &n, &V);
        memset(f, 0, sizeof(f));
        memset(v, 0, sizeof(v));
        f[0] = 1;
        found = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &x);
            v[x] = 1;
            for (int j = V; j >= x; j--)
                f[j] += f[j - x];
        }
        int ans = 5;
        for (int i = 0; i < 5; i++){
            Dfs(0, i, 1);
            if (found){
                ans = i;
                break;
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
}
