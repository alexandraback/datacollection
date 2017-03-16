#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pi;
typedef long long LL;
int a[77][77];
int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int _;scanf("%d",&_);
    int cas=1;
    while(_--){
        printf("Case #%d: ",cas++);
        int n;
        LL m;
        scanf("%d%lld",&n,&m);
        LL tot=(1LL<<(n-2));
        if(m>tot){puts("IMPOSSIBLE");continue;}
        puts("POSSIBLE");
        memset(a,0,sizeof(a));
        for(int i=n-1;i>1;i--){
            for(int j=i+1;j<=n;j++)a[i][j]=1;
        }
        if(m==tot){
            for(int i=2;i<=n;i++)a[1][i]=1;   
        }
        else{
            for(int i=0;i<n-2;i++){
                if(m>>i&1)a[1][n-1-i]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)printf("%d",a[i][j]);
            puts("");
        }
    }
}
