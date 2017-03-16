#include <cstdio>
#include <cstring>

using namespace std;

int T, C=1, n, amigo[1024], v[1024];
int tam; bool foi[1024];

bool vai(int u) {
    if (u==tam) {
        for (int i=0;i<tam;i++)
            if (!(amigo[ v[i] ] == v[(i+1)%tam] or amigo[v[i]] == v[(i-1+tam)%tam]))
                return false;
        return true;
    }
    for (int i=0;i<n;i++) if (!foi[i]) {
        v[u] = i;
        foi[i]=true;
        if (vai(u+1)) return true;
        foi[i]=false;
    }
    return false;
}

int main() {

    for(scanf("%d",&T);T--;) {
        printf("Case #%d: ",C++);
        scanf("%d",&n);
        for (int i=0;i<n;i++) {
            scanf("%d",amigo+i);
            amigo[i]--;
        }
        memset(foi,false,sizeof(foi));
        for (tam=n;tam>=1;tam--)
            if (vai(0))
                break;
        printf("%d\n",tam);
    }

    return 0;
}
