#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,tk=1;
    scanf("%d",&t);
    while(t--){
        int d, p[1100];
        scanf("%d",&d);
        for(int i=0; i<d; i++){
            scanf("%d",p+i);
        }
        int ans=9999;
        for(int i=1;i<=1000;i++){
            int ll=0;
            for(int j=0;j<d;j++){
                ll+=p[j]/i-(p[j]%i==0);
            }
            ans=min(ans,i+ll);
        }
        printf("Case #%d: %d\n",tk++,ans);
    }
}
