#include <cstdio>
#include <cstring>

#define min(a, b) (a < b ? a : b)

using namespace std;

int CE, CC[1024], indx[1024], lowlink[1024], Stop, C=1;
int S[1024], I,T,n,m, resp;
bool empilhado[1024];
int amigo[1024];
int nadj[1024], adj[1024][1024];
int nadjinv[1024], adjinv[1024][1024];

int dfsinv(int u, int proib) {
    int r = 1;
    for (int i=0;i<nadjinv[u];i++)
        if (adjinv[u][i] != proib) {
            int tt = 1 + dfsinv(adjinv[u][i], proib);
            if (tt > r)
                r = tt;
        }
    return r;
}

void SCC(int u) {
    indx[u] = lowlink[u] = I++;
    S[++Stop]=u;
    empilhado[u]=true;
    for (int i=0;i<nadj[u];i++) {
        int w = adj[u][i];
        if (indx[w] == -1) {
            SCC(w);
            lowlink[u] = min(lowlink[u],lowlink[w]);
        } else if (empilhado[w])
            lowlink[u] = min(lowlink[u],indx[w]);
    }
    if (lowlink[u] == indx[u]) {
        int cnt=0;
        //desempilha ate u; tudo desempilhado eh uma SCC
        for (;S[Stop] != u;Stop--){
            CC[S[Stop]] = CE;
            cnt++;
            empilhado[S[Stop]]=false;
        }
        // desempilha u
        CC[S[Stop]] = CE;
        cnt++;
        empilhado[S[Stop--]]=false;
        CE++;

        if (cnt > resp)
            resp = cnt;
    }
}

void tarjan() {
    CE=0;
    I=0;
    Stop=-1;
    memset(indx,0xff,sizeof(indx));
    memset(empilhado,false,sizeof(empilhado));
    for (int i=0;i<n;i++) if (indx[i] == -1)
        SCC(i);
}


int main() {

    for(scanf("%d",&T);T--;) {
        printf("Case #%d: ",C++);
        scanf("%d",&n);
        memset(nadj,0,sizeof(nadj));
        memset(nadjinv,0,sizeof(nadjinv));
        for (int i=0;i<n;i++) {
            scanf("%d",amigo+i);
            amigo[i]--;
            adj[i][nadj[i]++] = amigo[i];
            adjinv[amigo[i]][nadjinv[amigo[i]]++] = i;
        }

        resp = 0;
        tarjan();

        // caso a <-> b
        int isso=0;
        for (int i=0;i<n;i++)
            if (amigo[ amigo[i] ] == i) {
                int tt = dfsinv(i, amigo[i]) + dfsinv(amigo[i], i);
                isso += tt;
            }
        isso /= 2;
        if (isso > resp)
            resp = isso;
        printf("%d\n",resp);
    }


    return 0;
}
