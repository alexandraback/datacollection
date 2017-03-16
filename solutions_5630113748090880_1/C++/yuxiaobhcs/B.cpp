#include<stdio.h>
#include<memory.h>
using namespace std;
int main() {
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);

    int T,n;
    int h[3000];
    scanf("%d",&T);
    for (int cas=1; cas<=T; cas++) {
        scanf("%d",&n);
        memset(h,0,sizeof(h));
        int x;
        for (int i=0; i<2*n-1; i++)
        for (int j=0; j<n; j++) {
            scanf("%d",&x);
            h[x]++;
        }
        printf("Case #%d:",cas);
        for (int i=1; i<=2500; i++) {
            if (h[i] & 1) printf(" %d",i);
        }
        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
