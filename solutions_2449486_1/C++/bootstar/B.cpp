#include <stdio.h>
#include <string.h>
int arr[105][105];
int n, m;
bool checkx(int x, int y){
    for(int i = 1; i <= m; i ++){
        if(arr[x][y] < arr[x][i])
            return false;
    }
    return true;
}

bool checky(int x, int y){
    for(int i = 1; i <= n; i ++){
        if(arr[x][y] < arr[i][y])
            return false;
    }
    return true;
}

int main(){
    int T, cas = 1;
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &T);
    while(cas <= T){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                scanf("%d", &arr[i][j]);
            }
        }
        bool flag = true;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                if(checkx(i, j) || checky(i, j))
                    continue;
                else{
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        printf("Case #%d: ", cas++);
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
