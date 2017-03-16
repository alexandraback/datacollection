#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int v[128];
int comest[64][3];
int semest[64][3];

int n, p, ests, T, C=1;
int PD[128][128];

void gera(int u, int ant) {
    if (u==3) {
        if (v[2]-v[0] > 2) return;
        int soma = v[0]+v[1]+v[2];
        if (v[2]-v[0]==2) // com estrela
            memcpy(comest[soma],v,3*sizeof(int));
        else // sem estrela
            memcpy(semest[soma],v,3*sizeof(int));
        return;
    }
    for (int i=ant;i<=10 and (u==0 or i<=ant+2);i++) {
        v[u] = i;
        gera(u+1,i);
    }
}

// 0, 1, 29 e 30 nao tem vetor com estrela!
int calc(int u, int ests) {
    if (u==n)
        return ests == 0 ? 0 : -0x3f3f3f3f;
    int &pd = PD[u][ests];
    if (pd != 0x3f3f3f3f) return pd;
    int opc1, opc2; opc1=opc2=-0x3f3f3f3f;
    //com ests?
    if (ests > 0 and v[u]!=0 and v[u] != 1 and v[u] != 29 and v[u] != 30)
        opc1 = (comest[v[u]][2] >= p ? 1 : 0) + calc(u+1,ests-1);
    //sem ests?
    opc2 = (semest[v[u]][2] >= p ? 1 : 0) + calc(u+1,ests);

    return pd = max(opc1,opc2);
}

int main() {

    gera(0,0);

    for(scanf("%d",&T);T--;) {
        memset(PD,0x3f,sizeof(PD));
        scanf("%d %d %d",&n,&ests,&p);
        for (int i=0;i<n;i++)
            scanf("%d",v+i);
        printf("Case #%d: %d\n",C++,calc(0,ests));
    }

    return 0;
}
