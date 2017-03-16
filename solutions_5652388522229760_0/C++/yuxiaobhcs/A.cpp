#include<stdio.h>
#include<memory.h>
using namespace std;
int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    int t,n;
    bool dig[10];
    scanf("%d",&t);
    for (int cas=1; cas<=t; cas++) {
        scanf("%d",&n);
        if (n==0) {
            printf("Case #%d: INSOMNIA\n",cas);
            continue;
        }
        memset(dig,0,sizeof(dig));
        int cnt=10;
        int i=0,m,x;
        while (cnt>0) {
            m=++i*n;
            while (m>0) {
                x=m%10;
                if (!dig[x]) {
                    dig[x]=1;
                    cnt--;
                }
                m/=10;
            }
        }
        printf("Case #%d: %d\n",cas,i*n);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
