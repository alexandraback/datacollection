#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int t,T;
    int now,n;
    int i,j;
    int a[110];
    int need[110];
    freopen("A-small-attempt2.in","r",stdin);
    freopen("b.txt","w",stdout);

    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d %d",&now,&n);
        memset(need,0,sizeof(need));
        for(i=1;i<=n;i++) scanf("%d",&a[i]);
        if(now==1){
            printf("Case #%d: %d\n",t,n);
            continue;
        }
        sort(a+1,a+n+1);
        int tem=now;
        for(i=1;i<=n;i++){
            need[i]=need[i-1];
            if(tem>a[i]){
                tem+=a[i];
            }
            else{
                int temp=0;
                while(a[i]>=tem){
                    temp++;
                    tem=tem*2-1;
                }
                need[i]+=temp;
                tem+=a[i];
            }
        }
        int ans=100000;
        for(i=1;i<=n;i++) if(ans>need[i-1]+n-i+1) ans=need[i-1]+n-i+1;
        if(ans>need[n]) ans=need[n];
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
