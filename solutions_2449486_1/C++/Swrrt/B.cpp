#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int G[105][105],Ro[105],Col[105];
struct data{
    int x,y,h;
}A[10005];
inline bool cmp(data a,data b){
    return a.h>b.h;
}
int main(){
    int T,n,m,i,j,k,l,tt;
    freopen("B.out","w",stdout);scanf("%d",&T);
    
    tt=0;
    while(T--){
        tt++;
        scanf("%d%d",&n,&m);
        int gs=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++){
                scanf("%d",&G[i][j]);
                A[++gs].x=i;
                A[gs].y=j;
                A[gs].h=G[i][j];
            }
        sort(A+1,A+1+gs,cmp);
        for(i=1;i<=100;i++){
            Ro[i]=-1;
            Col[i]=-1;
        }
        int fl=0;
        for(i=1;i<=gs;i++){
            if(Ro[A[i].x]>A[i].h&&Col[A[i].y]>A[i].h)fl=1;
            else {
                if(Ro[A[i].x]<A[i].h)Ro[A[i].x]=A[i].h;
                if(Col[A[i].y]<A[i].h)Col[A[i].y]=A[i].h;
            }
            
        }
/*        for(i=1;i<=n;i++){
            Ro[i]=100;
            for(j=1;j<=m;j++)Ro[i]=min(Ro[i],G[i][j]);
        }
        for(i=1;i<=m;i++){
            Col[i]=100;
            for(j=1;j<=n;j++)Col[i]=min(Col[i],G[j][i]);
        }
        int fl=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                if(G[i][j]>Ro[i]&&G[i][j]>Col[j])fl=1;*/
        printf("Case #%d: ",tt);
        if(fl)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
