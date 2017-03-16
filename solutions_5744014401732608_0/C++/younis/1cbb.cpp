#include<cstdio>
#include<algorithm>
long long p[50];
int a[60][60];
int main(){
    freopen("B-small-attempt1.bin","r",stdin);
    freopen("output.txt","w",stdout);
    int t;scanf("%d",&t);
    int b,i,j;
    p[0]=1;
    for(i=1;i<50;i++)p[i]=p[i-1]<<1;
    long long m;
    for(int cas=1;cas<=t;cas++){
        scanf("%d%lld",&b,&m);
        printf("Case #%d: ",cas);
        if(m>p[b-2]){
            printf("IMPOSSIBLE\n");
            continue;
        }
        printf("POSSIBLE\n");
        for(i=1;i<=b;i++)for(j=1;j<=b;j++)a[i][j]=0;
        for(i=1;i<b;i++)for(j=i+1;j<b;j++)a[i][j]=1;
        if(m==p[b-2])for(i=1;i<b;i++)a[i][b]=1;
        else
            for(i=2;i<b;i++)if((m>>(i-2))&1)a[i][b]=1;
        for(i=1;i<=b;i++){
            for(j=1;j<=b;j++)printf("%d",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
