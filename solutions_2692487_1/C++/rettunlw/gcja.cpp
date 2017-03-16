#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int a[111],T,n,b,ans,ansb;
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&T);
    for (int rc=1;rc<=T;rc++){
        scanf("%d%d",&b,&n);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        ans=0;
        ansb=111111111;
        for (int i=0;i<n;i++){
            if (b<=a[i]){
                ansb=min(ansb,ans+n-i);
                while (b>1&&b<=a[i]){
                      b+=b-1;
                      ans++;
                }       
                if (b<=a[i])
                   ans=1111111111;  
            }
            b+=a[i];    
        }    
        printf("Case #%d: %d\n",rc,min(ans,ansb));
    }
    return 0;
}
