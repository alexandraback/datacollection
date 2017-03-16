#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int matrix[1005][1005];
int vis[1005];
int flag,n;
void dfs(int pos){
    int i;
    if(flag == 1)return;
    vis[pos] = 1;
    for(i=1;i<=n;i++){
        if(matrix[pos][i] == 1){
            if(vis[i] == 1)flag = 1;
            dfs(i);
        }
    }
}
int main (){
    int T,ca=0;
    int i,j;
    int m,a;
    scanf("%d",&T);
    while(T--){
        ca++;
        printf("Case #%d:",ca);
        memset(matrix,0,sizeof(matrix));
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&m);
            for(j=0;j<m;j++){
                scanf("%d",&a);
                matrix[i][a] = 1;
            }
        }
        flag = 0;
        for(i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            dfs(i);
        }
        if(flag == 1)printf(" Yes\n");
        else printf(" No\n");
    }
    return 0;
}

