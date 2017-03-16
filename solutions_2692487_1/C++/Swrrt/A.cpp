#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[105];
int main(){
    int T,n,i,j,k,l,tt=0,A;
    freopen("A.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        tt++;
        scanf("%d%d",&A,&n);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        int ans=n;
        sort(a+1,a+1+n);
        for(i=0;i<=n;i++){
            int tans=i,tA=A;
            for(j=1;j<=n-i;j++){
                while(tA<=a[j]&&tans<=n){
                    tA=tA+tA-1;
                    tans++;
                }
                if(tA<=a[n])tA+=a[j];
            }
            if(ans>tans)ans=tans;
        }
        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}

