#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int n, ans, e, r, i, v[100], cas, CAS;
void dfs(int k, int now, int s){
    if (k > n){
        ans = max(ans, s);
        return;
    }
    for (int i = 0; i <= now; i++)
        dfs(k + 1, min(now - i + r, e), s + i * v[k]);
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &CAS);
    for (cas = 1; cas <= CAS; cas++){
        scanf("%d%d%d", &e, &r, &n);
        for (i = 1; i <= n; i++) scanf("%d", &v[i]);
        ans = 0;
        dfs(1, e, 0);
        printf("Case #%d: %d\n", cas, ans);
    }

}
