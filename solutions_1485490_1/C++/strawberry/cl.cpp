#include <iostream>
__int64 dat[120][120];
__int64 s1[120][120],s2[120][120];
struct node{
    __int64 t,v;
}ina[120],inb[120];
long long MAX(long long a,long long b){
    return a>b?a:b;
}
long long MIN(long long a,long long b){
    return a<b?a:b;
}
int main(){
    freopen("cl.in","r",stdin);
    freopen("cl.out","w",stdout);
    int i,j,k,n,m,co=1,x,y;
    int cas,c;
    scanf("%d",&cas);
    for(c=1;c<=cas;c++){
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        scanf("%d%d",&n,&m);
        for (i=0;i<n;i++){
            scanf("%lld%lld",&ina[i].v,&ina[i].t);
            s1[ina[i].t][i+1]=ina[i].v;
        }
        for (i=0;i<n;i++)
            for (k=0;k<=100;k++)
                s1[k][i+1]+=s1[k][i];
        for (i=0;i<m;i++){
            scanf("%lld%lld",&inb[i].v,&inb[i].t);
            s2[inb[i].t][i+1]=inb[i].v;
        }
        for (i=0;i<m;i++)
            for (k=0;k<=100;k++)
                s2[k][i+1]+=s2[k][i];
        memset(dat,0,sizeof(dat));        
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++){
                if (ina[i-1].t!=inb[j-1].t)
                    dat[i][j]=MAX(dat[i-1][j],dat[i][j-1]);
                else{
                    for (x=0;x<i;x++)
                        for (y=0;y<j;y++)
                            dat[i][j]=MAX(dat[i][j],dat[x][y]+MIN(s1[ina[i-1].t][i]-s1[ina[i-1].t][x],s2[inb[j-1].t][j]-s2[inb[j-1].t][y]));
                }
            }        
        __int64 ans=0;
        for (i=0;i<=n;i++)
            for (j=0;j<=m;j++)
                ans=MAX(ans,dat[i][j]);
        printf("Case #%d: %I64d\n",c,ans);
    }
    return 0;
}
