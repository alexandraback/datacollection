#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int e, r, n, ans;
int a[20];

void init(){
    cin >> e >> r >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
}

void dfs(int x, int ene, int val){
    if(x == n + 1) ans = max(ans, val);
    for(int i = 0; i <= ene; ++i){
        dfs(x + 1, min(e, ene - i + r), val + i * a[x]);
    }
}
void solve(){
    ans = 0;
    dfs(1, e, 0);
    cout << ans << endl;
}
int main(){
    freopen("in.txt", "r", stdin);
//    freopen("C:\\Users\\数字艺术实验室\\Downloads\\", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int t, cas = 1;
    for(cin >> t; t--; ){
        printf("Case #%d: ", cas++);
        init();
        solve();
    }
    return 0;
}
