#include <cstdio>
#include <cstring>

#define MAX 10000000

using namespace std;

inline int inv(int d) {
    int r = 0;
    while (d) {
        r = 10*r + (d%10);
        d /= 10;
    }
    return r;
}

int T, C=1, n, Qini, Qfim, Q[MAX+3], dist[MAX+3];
int enfilered[MAX+3], TT;

int main() {

    memset(enfilered,0,sizeof(enfilered));
    TT=0;
    for(scanf("%d",&T);T--;) {
        printf("Case #%d: ",C++);
        scanf("%d",&n);
        Qini = Qfim = 0;
        TT++;
        Q[Qini++] = 1;
        enfilered[1] = TT;
        dist[1] = 1;
        while (Qini != Qfim) {
            int d = Q[Qfim++];
            if (d == n) break;
            if (d+1 <= MAX and enfilered[d+1] != TT) {
                Q[Qini++] = d+1;
                dist[d+1] = dist[d]+1;
                enfilered[d+1]=TT;
            }
            int id = inv(d);
            if (id <= MAX and enfilered[id] != TT) {
                Q[Qini++] = id;
                dist[id] = dist[d]+1;
                enfilered[id] = TT;
            }
        }
        printf("%d\n",dist[n]);
    }

    return 0;
}
