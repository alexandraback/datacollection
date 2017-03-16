#include<bits/stdc++.h>
using namespace std;
main(){
    freopen("A-large.in","r",stdin);
    freopen("outA","w",stdout);
    int T,c=1;
    scanf("%d",&T);
    while(T--){
        char str[1500],ans[5000];
        scanf(" %s",str);
        int len=strlen(str),left=2000,right=2000,i;
        memset(ans,0,sizeof(ans));
        ans[2000]=str[0];
        for(i=1;i<len;i++){
            if(str[i]>=ans[left])left--,ans[left]=str[i];
            else right++,ans[right]=str[i];
        }
        printf("Case #%d: ",c++);
        for(i=left;i<=right;i++)printf("%c",ans[i]);
        puts("");
    }
    return 0;
}
