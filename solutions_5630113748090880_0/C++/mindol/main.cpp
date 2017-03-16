#include<cstdio>
#include<memory.h>
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int mindol=1;mindol<=tc;mindol++,puts("")) {
        int n,cnt[2501];
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(int i=1,a;i<=(2*n-1)*n;i++) {
            scanf("%d",&a);
            cnt[a]++;
        }
        printf("Case #%d: ",mindol);
        for(int i=1;i<=2500;i++) {
            if(cnt[i]%2 == 1)
                printf("%d ",i);
        }
    }
    return 0;
}
