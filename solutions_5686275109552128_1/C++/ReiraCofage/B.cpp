#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T, C=1, n, v[1024];

int PD[1024][1024], tem[1024][1024], TT;

int calc(int u, int panqs) {
    if (u==n) return panqs;
    if (tem[u][panqs] == TT) return PD[u][panqs];

    int best = 0x3f3f3f3f;
    for (int i=1;i<=v[u];i++) { // qnts partes?
        int tt = (i-1) + calc(u+1, max(panqs, (v[u]+i-1)/i) );
        best = min(best, tt);
    }

    PD[u][panqs] = best;
    tem[u][panqs] = TT;
    return best;
}

int main() {

    memset(tem,0,sizeof(tem));
    TT=0;
    for(scanf("%d",&T);T--;) {
        printf("Case #%d: ",C++);
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d",v+i);

        TT++;
        printf("%d\n",calc(0,0));
    }

    return 0;
}
