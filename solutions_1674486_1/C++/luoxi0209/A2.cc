#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n,m;
int x,y,total;
long long s[1001][1001];
bool ans;

void solve() {
    for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            s[i][j] += s[i][k] * s[k][j];
            if (s[i][j] >= 2) {
                ans = true;
                return;
            }
        }
}

int main(int argc, char *argv[]) {
    int T;
    scanf("%d",&T);

    for (int i = 1; i <= T ; i++) {
        memset(s,0,sizeof(s));
        scanf("%d",&n);
        for (int j = 1; j <= n ; j++) {
            scanf("%d",&m);
            int a;
            for (int k = 0; k < m; k++) {
                scanf("%d",&a);
                s[j][a] = 1;
            }
        }
        ans = false;
        solve();
        printf("Case #%d: ",i);
        if (ans) printf("Yes\n");
            else printf("No\n");
    }
    return 0;
}
