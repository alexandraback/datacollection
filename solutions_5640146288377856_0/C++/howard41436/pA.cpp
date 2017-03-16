#include<bits/stdc++.h>
using namespace std;
main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("pA.txt","w",stdout);
    int T,i,j,ans[20][20],cs=1;
    for(i=1;i<=10;i++)ans[i][1]=ans[i][i]=i;
    for(i=2;i<=10;i++)for(j=2;j<=i-1;j++){
        if(j*2<=i)ans[i][j]=ans[i-j][j]+1;
        else ans[i][j]=j+1;
    }
    scanf("%d",&T);
    while(T--){
        int r,c,w;
        scanf("%d %d %d",&r,&c,&w);
        printf("Case #%d: %d\n",cs++,ans[c][w]);
    }
    return 0;
}
