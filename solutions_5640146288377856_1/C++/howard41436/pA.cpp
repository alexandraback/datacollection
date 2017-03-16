#include<bits/stdc++.h>
using namespace std;
main(){
    freopen("A-large.in","r",stdin);
    freopen("pA_big.txt","w",stdout);
    int T,i,j,ans[30][30],cs=1;
    for(i=1;i<=20;i++)ans[i][1]=ans[i][i]=i;
    for(i=2;i<=20;i++)for(j=2;j<=i-1;j++){
        if(j*2<=i)ans[i][j]=ans[i-j][j]+1;
        else ans[i][j]=j+1;
    }
    scanf("%d",&T);
    while(T--){
        int r,c,w;
        scanf("%d %d %d",&r,&c,&w);
        printf("Case #%d: %d\n",cs++,(r-1)*(c/w)+ans[c][w]);
    }
    return 0;
}
