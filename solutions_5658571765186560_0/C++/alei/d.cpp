#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;

bool ok[5][5][5];
int main(){
    freopen("ds.in","r",stdin);    
    freopen("ds.out","w",stdout);
    memset(ok,false,sizeof ok);
    ok[4][3][4]=true;
    ok[4][4][4]=true;

    ok[3][2][3]=true;
    ok[3][3][3]=true;
    ok[3][3][4]=true;

    ok[2][1][2]=true;
    ok[2][1][4]=true;
    ok[2][2][2]=true;
    ok[2][2][3]=true;
    ok[2][2][4]=true;
    ok[2][3][4]=true;
    ok[2][4][4]=true;
    
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            ok[1][i][j]=true;

    int t,x,n,m;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d %d %d",&x,&n,&m);
        if(n>m)swap(n,m);
        if(ok[x][n][m])printf("Case #%d: GABRIEL\n",tt);
        else printf("Case #%d: RICHARD\n",tt);
    }
    return 0;
}
