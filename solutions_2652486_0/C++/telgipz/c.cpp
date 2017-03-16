#include <cstdio>
using namespace std;

int main() {
    int t, r, n, m ,k;
    freopen("c.in", "r", stdin);
    freopen("c.sol", "w", stdout);
    scanf("%d", &t);
    scanf("%d %d %d %d", &r, &n ,&m , &k);
    
    printf("Case #1: \n");
    
    for (int tx=0; tx<r; tx++) {
        int list[101];
        for (int i=0; i<k; i++) {
            scanf("%d", &list[i]);
        }
        int a=0;
        for (int i=2; i<=m&&!a; i++) {
            for (int j=2; j<=m&&!a; j++) {
                for (int x=2; x<=m&&!a; x++) {
                    
                    int y=0;
                    for (; y<k; y++) {
                        if (list[y]==1*1*1) continue;
                        if (list[y]==i*1*1) continue;
                        if (list[y]==1*j*1) continue;
                        if (list[y]==1*1*x) continue;
                        if (list[y]==i*j*1) continue;
                        if (list[y]==i*1*x) continue;
                        if (list[y]==1*j*x) continue;
                        if (list[y]==i*j*x) continue;
                        break;
                    }
                    
                    
                    if(y==k) {
                        printf("%d%d%d\n",i,j,x);
                        a=1;
                    }
                }
            }
        }
        
        
    }
    
    return 0;
}