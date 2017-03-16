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

int a, b, X, Y, n, v[205][205];
void dfs(int k, int x, int y){
    if (k > n){
        b++;
        if (v[X][Y]) a++;
        return;
    }
    while (1){
        if (y == 0 || (v[x - 1][y - 1] && v[x + 1][y - 1])){
            v[x][y] = 1;
            dfs(k + 1, 100, k * 2);
            v[x][y] = 0;
            return;
        }
        if (v[x][y - 2]){
            if (!v[x - 1][y - 1]) dfs(k, x - 1, y - 1);
            if (!v[x + 1][y - 1]) dfs(k, x + 1, y - 1);
            return;
        }
        if (v[x - 1][y - 1]){
            dfs(k, x + 1, y - 1);
            return;
        }
        if (v[x + 1][y - 1]){
            dfs(k, x - 1, y - 1);
            return;
        }
        y -= 2;
    }
}
int main(){
    int cas, CAS;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &CAS);
    for (cas = 1; cas <= CAS; cas++){
        scanf("%d%d%d", &n, &X, &Y);
        a = 0; b = 0;
        X += 100;
        if (X < 0 || X > 200 || Y < 0 || Y > 200){
            printf("Case #%d: 0.00000000\n", cas);
            continue;
        }
        memset(v, 0, sizeof(v));
        dfs(1, 100, 0);
        double ans = ((double)a) / ((double)b);
        printf("Case #%d: %.8lf\n", cas, ans);
    }

}
