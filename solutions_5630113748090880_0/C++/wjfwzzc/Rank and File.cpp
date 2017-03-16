#include <cstdio>
#include <cstring>
using namespace std;
const int N=2505;
int cnt[N];
int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t,n,h;
    scanf("%d",&t);
    for(int cas=1; cas<=t; ++cas) {
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(int i=1; i<n<<1; ++i)
            for(int j=0; j<n; ++j) {
                scanf("%d",&h);
                ++cnt[h];
            }
        printf("Case #%d:",cas);
        for(int i=0; i<N; ++i)
            if(cnt[i]&1)
                printf(" %d",i);
        putchar('\n');
    }
    return 0;
}
