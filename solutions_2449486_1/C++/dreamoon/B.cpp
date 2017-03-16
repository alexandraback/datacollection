#include<stdio.h>
#define SIZE 111
int used[SIZE][SIZE],a[SIZE][SIZE],cs;
bool check(int n,int m){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)if(used[i][j]!=cs)return 0;
    return 1;
}
int main(){
    int T,i,j,k,n,m;
    scanf("%d",&T);
    while(T--){
        cs++;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)scanf("%d",&a[i][j]);
        printf("Case #%d: ",cs);
        for(i=1;i<=100;i++){
            for(j=0;j<n;j++){
                for(k=0;k<m;k++)
                    if(a[j][k]>i)break;
                if(k==m){
                    for(k=0;k<m;k++)
                        if(a[j][k]==i)used[j][k]=cs;
                }
            }
            for(k=0;k<m;k++){
                for(j=0;j<n;j++)
                    if(a[j][k]>i)break;
                if(j==n){
                    for(j=0;j<n;j++)
                        if(a[j][k]==i)used[j][k]=cs;
                }
            }
        }
        if(!check(n,m))puts("NO");
        else puts("YES");
    }
}
