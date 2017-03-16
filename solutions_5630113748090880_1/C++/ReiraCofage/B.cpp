#include <cstdio>
#include <cstring>

#define MAX 2505

using namespace std;

int C=1, T, n, oc[MAX];
int v[1024][1024];

int main() {

    for(scanf("%d",&T);T--;) {
        printf("Case #%d:",C++);
        scanf("%d",&n);
        memset(oc,0,sizeof(oc));
        int m = 2*n-1;
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++) {
                scanf("%d",&v[i][j]);
                oc[v[i][j]]++;
            }

        for (int i=1;i<MAX;i++)
            if (oc[i]&1)
                printf(" %d",i);
        printf("\n");
    }

    return 0;
}
