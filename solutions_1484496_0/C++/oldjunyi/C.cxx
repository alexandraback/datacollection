#include <cstdio>
#include <algorithm>
using namespace std;

int sum[1<<20];

int main(){
    int cs,n,a[500];
    scanf("%d",&cs);
    for(int no=1;no<=cs;no++){
        printf("Case #%d:\n",no);
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",a+i);
        int mask=(1<<n)-1;
        bool tag=false;
        for(int s=1;s<=mask;s++){
            sum[s]=sum[s&(s-1)]+a[__builtin_ctz(s)];
            for(int r=s&(s-1);r;r=s&(r-1)){
                if(sum[r]!=sum[s^r]) continue;
                for(int i=0,cnt=0;i<n;i++) if(r&1<<i){
                    if(cnt++) putchar(' ');
                    printf("%d",a[i]);
                }
                puts("");
                for(int i=0,cnt=0;i<n;i++) if((s^r)&1<<i){
                    if(cnt++) putchar(' ');
                    printf("%d",a[i]);
                }
                puts("");
                tag=true;
                break;
            }
            if(tag) break;
        }
        if(!tag) puts("Impossible");
    }
}
