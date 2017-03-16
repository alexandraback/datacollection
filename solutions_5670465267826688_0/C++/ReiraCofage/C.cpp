#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int M[5][5] = {
    {0,0,0,0,0},
    {0,1,2,3,4},
    {0,2,-1,4,-3},
    {0,3,-4,-1,2},
    {0,4,3,-2,-1}
};

inline int idx(char c) {
    return (c-'i') + 2;
}

inline int vezes(int a, int b) {
    if (a > 0 and b > 0) return M[a][b];
    if (a < 0 and b > 0) return -M[-a][b];
    if (a > 0 and b < 0) return -M[a][-b];
    if (a < 0 and b < 0) return M[-a][-b];
    return 1;
}

int T,C=1,val[10010], L, X;
char aux[10010];

inline bool dah(int a, int b, int v) {
    if (b < a) return false;
    return vezes( (a?val[a-1]:1), v) == val[b];

}

int main() {

    for(scanf("%d",&T);T--;) {
        printf("Case #%d: ",C++);
        scanf("%d %d",&L,&X);
        scanf("%s",aux);
        string a = aux;
        string s = "";
        for (int i=0;i<X;i++)
            s = s + a;

        int n = (int)s.size();
        val[0] = idx(s[0]);

        for (int i=1;i<n;i++)
            val[i] = vezes( val[i-1], idx(s[i]) );

        bool ok=false;
        for (int i=0;i<n;i++) if (dah(0,i,2))
            for (int j=i+1;j<n;j++) if (dah(i+1,j,3))
                if (dah(j+1,n-1,4)) {
                    ok=true;
                    goto asd;
                }
        asd:;
        printf("%s\n",ok?"YES":"NO");
    }
    return 0;
}
