#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n, a[1005][1005];
bool floyd(){
    int i, j, k;
    for(k=1; k<=n; k++)
    for(i=1; i<=n; i++)
    for(j=1; j<=n; j++){
        if(a[i][k]&&a[k][j]){
            if(a[i][j])
                return true;
            else a[i][j]=1;
        }
    }
    return false;
}
int main(){
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.out", "w", stdout);
    int T, i, j, k, x, cas=1;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        for(i=1; i<=n; i++){
            scanf("%d", &k);
            while(k--){
                scanf("%d", &x);
                a[i][x]=1;
            }
        }
        if(floyd())printf("Case #%d: Yes\n", cas++);
        else printf("Case #%d: No\n", cas++);
    }
    return 0;
}
