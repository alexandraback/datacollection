#include<cstdio>
#include<algorithm>
using namespace std;
int tc,n,cnt[2505];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,q,k;
    scanf("%d",&tc);
    for(q=1;q<=tc;q++) {
        scanf("%d",&n);
        for(i=0;i<2*n*n-n;i++) {
            scanf("%d",&k);
            cnt[k]++;
        }
        printf("Case #%d: ",q);
        for(i=1;i<=2500;i++) {
            if(cnt[i]%2) {
                printf("%d ",i);
            }
            cnt[i] = 0;
        }
        puts("");
    }
}
