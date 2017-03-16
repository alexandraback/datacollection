#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t,n,s,p,c;
    freopen("B-large.in","r",stdin);
    freopen("21.out","w",stdout);
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        int gs0,gs1,gs2,gs,ans=0;
        scanf("%d%d%d",&n,&s,&p);
        gs0=gs1=gs2=gs=0;
        for (int j=0;j<n;j++){
            scanf("%d",&c);
            if (c<=1 || c>=29){
                if ((c+2)/3>=p) ans++;
                continue;
            }
            if (c%3==0){
                if (c/3>=p) gs0++;
                else if (c/3+1>=p) gs2++;
                else gs++;
            }
            else if (c%3==1){
                if (c/3+1>=p) gs1++;
                else gs++;
            }
            else{
                if (c/3+1>=p) gs1++;
                else if (c/3+2>=p) gs2++;
                else gs++;
            }
        }
        if (gs2>=s) ans+=(gs0+gs1+s);
        else ans+=(gs0+gs1+gs2);
        printf("Case #%d: %d\n",i+1,ans);
    }
    return 0;
}
