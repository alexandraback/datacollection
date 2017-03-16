#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n, N, M, R, K, lixo;
bool fora[1024];
int v[128]; // numeros possiveis
vector<int> possiveis[1024];

void gera(int u, int atu) {
    if (u==N) {
        v[n++] = atu;
        int d1 = atu%10;
        int d2 = (atu/10)%10;
        int d3 = (atu/100)%10;
        possiveis[atu].clear();
        possiveis[atu].push_back(1);
        possiveis[atu].push_back(d1);
        possiveis[atu].push_back(d2);
        possiveis[atu].push_back(d3);
        possiveis[atu].push_back(d1*d2);
        possiveis[atu].push_back(d1*d3);
        possiveis[atu].push_back(d2*d3);
        possiveis[atu].push_back(d1*d2*d3);
        return;
    }
    for (int d=2;d<=M;d++)
        gera(u+1,10*atu+d);
}

int main() {

    scanf("%d",&lixo);
    scanf("%d %d %d %d",&R,&N,&M,&K);
    printf("Case #1:\n");
    n=0;
    gera(0,0);

    while (R--) {
        memset(fora,false,sizeof(fora));
        for (int i=0;i<K;i++) {
            int prod;
            scanf("%d",&prod);
            for (int j=0;j<n;j++) if (!fora[v[j]]) {
                bool tem=false;
                for (int k=0;k<(int)possiveis[v[j]].size();k++)
                    if (possiveis[v[j]][k] == prod) {
                        tem=true;
                        break;
                    }
                if (!tem) fora[v[j]]=true;
            }
        }
        for (int i=0;i<n;i++) if (!fora[v[i]]) {
            printf("%d\n",v[i]);
            break;
        }
    }

    return 0;
}
