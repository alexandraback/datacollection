#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct _no {
    bool final;
    _no *filho[26];
} no;

char s[4040];
int n, TT, T, C=1;
int tem[4040][7];
int  PD[4040][7], pQ=0;
no M[3844492];
no *raiz;

no *mymalloc() {
    M[pQ].final = false;
    for (int i=0;i<26;i++)
        M[pQ].filho[i] = NULL;
    pQ++;
    return &M[pQ-1];
}

void insere(char *s, no *r) {
    if (*s=='\0') {
        r->final = true;
        return;
    }
    if (r->filho[ (*s)-'a'] == NULL)
        r->filho[ (*s)-'a'] = mymalloc();
    insere(s+1, r->filho[(*s)-'a']);
}

bool busca(char *s, no *r) {
    if (r==NULL) return false;
    if ((*s)=='\0')
        return r->final;
    if (r->filho[ (*s)-'a'] == NULL) return false;
    return busca(s+1, r->filho[(*s)-'a']);
}

int calc(int u, int proib) {
    if (u==n) return 0;
    if (tem[u][proib]==TT)
        return PD[u][proib];
    int best = 0x3f3f3f3f;
    for (int size=1;size<=10 and u+size-1<n;size++) {
        char aux[12]; for (int i=u;i<u+size;i++) aux[i-u] = s[i];
        aux[size]='\0';
        // nao muda
        if (busca(aux,raiz)) {
            int tt = calc(u+size, max(0,proib-size));
            best = min(best,tt);
        }
        // muda 1
        for (int k=proib;k<size;k++) for (char c='a'; c <= 'z'; c++) if (c != aux[k]) {
            char old = aux[k];
            aux[k] = c;
            if (busca(aux,raiz)) {
                int tt = 1 + calc(u+size, max(0,5-(size-k)) );
                best = min(best,tt);
            }
            aux[k]=old;
        }
        // muda 2
        for (int k=proib;k<size;k++) for (char c='a'; c <= 'z'; c++) if (c != aux[k])
        for (int l=k+5;l<size;l++) for (char cc='a'; cc <= 'z'; cc++) if (cc != aux[l]) {
            char oldk = aux[k], oldl = aux[l];
            aux[k] = c; aux[l] = cc;
            if (busca(aux,raiz)) {
                int tt = 2 + calc(u+size, max(0,5-(size-l)) );
                best = min(best,tt);
            }
            aux[k]=oldk;
            aux[l]=oldl;
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
    raiz = mymalloc();
    for (int i=0;i<521196;i++) {
        scanf("%s",s);
        insere(s,raiz);
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
