#include<cstdio>
#include<iostream>
using namespace std;

#define BM 105

int n,m,t;
int a[BM][BM];

int main (){
    int i,j,l,k,okv,oko,bun;
    //freopen("l.in","r",stdin);
    //freopen("l.out","w",stdout);
    scanf("%d",&t);
    for(l=1;l<=t;++l){
        scanf("%d %d\n",&n,&m);
        for(i=1;i<=n;++i)for(j=1;j<=m;++j)scanf("%d",&a[i][j]);
        bun=1;
        for(i=1;i<=n;++i)for(j=1;j<=m;++j){
            okv=oko=1;
            for(k=1;k<=n;++k)if(a[k][j]>a[i][j])okv=0;
            for(k=1;k<=m;++k)if(a[i][k]>a[i][j])oko=0;
            if(oko==0&&okv==0)bun=0;
        }
        printf("Case #%d: ",l);
        if(bun)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
