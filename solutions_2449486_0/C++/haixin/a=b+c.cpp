#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int n,m,map[110][110];
int h[110],l[110];
int can(int x){
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(map[i][j]==x){
    if(h[i]&&l[j])return 1;
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(map[i][j]==x){
       h[i]=1;
       l[j]=1;
    }
    return 0;
}
int doit(){
    memset(h,0,sizeof(h));
    memset(l,0,sizeof(l));
    for(int i=100;i>=1;i--){
            if(can(i))return 0; 
            }
            return 1;
    }
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int q;
    scanf("%d",&q);
    for(int t=1;t<=q;t++){
            scanf("%d%d",&n,&m);
            for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                    scanf("%d",&map[i][j]);
            int d=doit();
            printf("Case #%d: ",t);
            if(d==0)printf("NO\n");
            if(d==1)printf("YES\n");
            }
    }
