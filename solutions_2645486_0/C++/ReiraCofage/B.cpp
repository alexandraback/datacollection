#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T, E, R, n, C=1;
int v[32];

int calc(int u, int e) {
    if (u==n) return 0;
    int best = 0;
    for (int g=0;g<=e;g++) {
        int tt = v[u]*g + calc(u+1, min(e-g+R,E));
        best =max(best,tt);
    }
    return best;
}

int main() {

    for(scanf("%d",&T);T--;) {
        scanf("%d %d %d",&E,&R,&n);
        for (int i=0;i<n;i++)
            scanf("%d",v+i);
        printf("Case #%d: %d\n",C++,calc(0,E));
    }

    return 0;
}
