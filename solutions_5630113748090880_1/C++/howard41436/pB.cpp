#include<bits/stdc++.h>
using namespace std;
main(){
    freopen("B-large.in","r",stdin);
    freopen("outB","w",stdout);
    int T,a,c=1,n,i,j,num[3000];
    scanf("%d",&T);
    while(T--){
        memset(num,0,sizeof(num));
        scanf("%d",&n);
        for(i=0;i<2*n-1;i++)
            for(j=0;j<n;j++)scanf("%d",&a),num[a]++;
        printf("Case #%d:",c++);
        for(i=1;i<=2500;i++)
            if(num[i]%2)printf(" %d",i);
        puts("");
    }
    return 0;
}
