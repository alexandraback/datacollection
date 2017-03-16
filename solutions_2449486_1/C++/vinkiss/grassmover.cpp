#include <iostream>
#include <cstdio>
using namespace std;
bool fun(int a[100][100],int n, int m,int x,int y){
    int flag = 0;
    for(int i=0; i<n; i++){
        if(a[i][y] > a[x][y]){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        for(int i = 0; i<m; i++){

            if(a[x][i] > a[x][y]){
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int p;
    int t,n,m,x = 0;
    int a[100][100];
    cin >> t;
    while(t--){
        x++;
        int flag = 0;
        cin >> n >> m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p = a[i][j];
                if(fun(a,n,m,i,j) == 1){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
            break;
        }
    if (flag == 1){
        printf("Case #%d: NO\n", x);
        }else{
             printf("Case #%d: YES\n", x);
        }
    }
    return 0;
}
