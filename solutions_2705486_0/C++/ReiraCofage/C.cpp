#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

char s[4040];
int n, TT, T, C=1;
set<string> D;
int tem[4040][7];
int  PD[4040][7];

int calc(int u, int proib) {
    if (u==n) return 0;
    if (tem[u][proib]==TT)
        return PD[u][proib];
    int best = 0x3f3f3f3f;
    for (int size=1;size<=10 and u+size-1<n;size++) {
        char aux[12]; for (int i=u;i<u+size;i++) aux[i-u] = s[i];
        aux[size]='\0';
        string d = aux;
        // nao muda
        if (D.find(d) != D.end()) {
            int tt = calc(u+size, max(0,proib-size));
            best = min(best,tt);
        }
        // muda 1
        for (int k=proib;k<size;k++) for (char c='a'; c <= 'z'; c++) if (c != d[k]) {
            char old = d[k];
            d[k] = c;
            if (D.find(d) != D.end()) {
                int tt = 1 + calc(u+size, max(0,5-(size-k)) );
                best = min(best,tt);
            }
            d[k]=old;
        }
        // muda 2
        for (int k=proib;k<size;k++) for (char c='a'; c <= 'z'; c++) if (c != d[k])
        for (int l=k+5;l<size;l++) for (char cc='a'; cc <= 'z'; cc++) if (cc != d[l]) {
            char oldk = d[k], oldl = d[l];
            d[k] = c; d[l] = cc;
            if (D.find(d) != D.end()) {
                int tt = 2 + calc(u+size, max(0,5-(size-l)) );
                best = min(best,tt);
            }
            d[k]=oldk;
            d[l]=oldl;
        }
    }
    tem[u][proib]=TT;
    return PD[u][proib]=best;
}

int main() {

    // I'm reading the dictionary here. I'm suposing that the dictionary is
    // included in the input JUST BEFORE the input itself (I'll do that to test
    // and submit this code). Didn't hardcode the dictory cuz the problem said I
    // shouldn't.
    for (int i=0;i<521196;i++) {
        scanf("%s",s);
        string d = s;
        D.insert(d);
    }
    // The algo itself
    memset(tem,0,sizeof(tem));
    TT=0;
    for(scanf("%d",&T);T--;) {
        scanf("%s",s);
        n = strlen(s);
        TT++;
        printf("Case #%d: %d\n",C++,calc(0,0));
    }

    return 0;
}
