#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int cs,no=0;
    scanf("%d",&cs);
    while(cs--){
        int a,n,x[100];
        scanf("%d%d",&a,&n);
        for(int i=0;i<n;i++) scanf("%d",x+i);
        sort(x,x+n);
        int ans=n,cnt=0;
        if(a>1) for(int i=0;i<n;i++){
            while(a<=x[i]){
                a+=a-1;
                cnt++;
            }
            a+=x[i];
            ans=min(ans,cnt+n-i-1);
        }
        printf("Case #%d: %d\n",++no,ans);
    }
}
