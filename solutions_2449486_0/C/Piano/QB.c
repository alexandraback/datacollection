#include<stdio.h>

int main(){
    int t, u;
    scanf("%d", &t);
    for (u = 1 ; u <= t ; ++u){
        int n, m, i, j;
        int a[100][100], mrow[100] = {}, mcol[100] = {};
        printf("Case #%d: ", u);
        scanf("%d%d", &n, &m);
        for (i = 0 ; i < n ; ++i){
            for (j = 0 ; j < m ; ++j){
                scanf("%d", &a[i][j]);
                if (a[i][j] > mrow[i])mrow[i] = a[i][j];
                if (a[i][j] > mcol[j])mcol[j] = a[i][j];
            }
        }
        for (i = 0 ; i < n ; ++i){
            for (j = 0 ; j < m ; ++j){
                if (a[i][j] != (mrow[i] < mcol[j] ? mrow[i] : mcol[j]))
                    break;
            }
            if (j < m)break;
        }
        puts(i == n ? "YES" : "NO");
    }
    return 0;
}
