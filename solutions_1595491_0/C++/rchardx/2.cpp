#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100+1;

int n,sum[MAXN],d[MAXN][2];

int main() {
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int ntest;
    scanf("%d",&ntest);
    for (int loop = 1; loop<=ntest; loop++) {
        printf("Case #%d: ",loop);
        int s,p;
        scanf("%d%d%d",&n,&s,&p);
        for (int i = 0; i<n; ++i) {
            scanf("%d",sum+i);
            if (sum[i]==0) {
                d[i][0] = d[i][1] = 0;
                continue;
            }
            if (sum[i]==1) {
                d[i][0] = d[i][1] = 1;
                continue;
            }
            switch (sum[i]%3) {
                case 0 :
                    d[i][0] = sum[i]/3;
                    d[i][1] = sum[i]/3+1;
                    break;
                case 1 :
                    d[i][0] = sum[i]/3+1;
                    d[i][1] = sum[i]/3+1;
                    break;
                case 2 :
                    d[i][0] = sum[i]/3+1;
                    d[i][1] = sum[i]/3+2;
                    break;
            }
        }
        int ans = 0;
        for (int i = 0; i<n; ++i)
            if (d[i][0]>=p) ++ans;
            else
                if (s>0 && d[i][1]>=p) {
                    --s;
                    ++ans;
                }
        printf("%d\n",ans);
    }
    return 0;
}
