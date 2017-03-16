#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
int MAXr[105],MAXc[105];
int MAP[105][105];
int main(){
    int T,flag = 0,ca,n,i,m,j;
    scanf("%d",&T);
    for(ca=1;ca<=T;ca++){
        printf("Case #%d: ",ca);
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++)
                scanf("%d",&MAP[i][j]);
        }
        for(i=0;i<n;i++){
            MAXc[i] = 0;
            for(j=0;j<m;j++){
                MAXc[i] = max(MAXc[i],MAP[i][j]);
            }
        }
        for(j=0;j<m;j++){
            MAXr[j] = 0;
            for(i=0;i<n;i++){
                MAXr[j] = max(MAXr[j],MAP[i][j]);
            }
        }
        flag = 1;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(MAXc[i] > MAP[i][j] && MAXr[j] > MAP[i][j])
                    flag = 0;
            }
        }
        if(flag == 1)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/*
3
3 3
2 1 2
1 1 1
2 1 2
5 5
2 2 2 2 2
2 1 1 1 2
2 1 2 1 2
2 1 1 1 2
2 2 2 2 2
1 3
1 2 1
*/
