#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 150

int req[maxm][maxm],n,m;
int chck(int r,int c,int piv);

int main(){

    int i,j,k,l,test,t=1;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&n,&m);

        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&req[i][j]);
            }
        }

        int flag=1;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(!chck(i,j,req[i][j])){ flag=0; break; }
            }
            if(!flag) break;
        }

        printf("Case #%d: ",t++);
        if(!flag) printf("NO\n");
        else printf("YES\n");

    }

    return 0;
}


int chck(int r,int c,int piv){

    int i,j,flag;

    flag=1;
    for(j=1;j<=m;j++){
        if(req[r][j]>piv){
            flag=0; break;
        }
    }
    if(flag) return 1;
    flag=1;
    for(i=1;i<=n;i++){
        if(req[i][c]>piv){
            flag=0; break;
        }
    }
    if(flag) return 1;

    return 0;

}
