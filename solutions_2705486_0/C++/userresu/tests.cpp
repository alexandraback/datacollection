#include <cstdio>
#include <cstring>
using namespace std;

char s[522000][100];
int x[522000];
char a[100];
int best[51];
int main () {
    int n=521196;
    FILE *in;
    in = fopen("a.txt","r");
    for (int i=1;i<=n;++i) fscanf(in,"%s",s[i]),x[i]=strlen(s[i]);
    int T=1;
    freopen("input.txt","r",stdin);scanf("%d",&T);
    freopen("output.txt","w",stdout);
    for (int z=1;z<=T;++z) {
        scanf("%s",a);
        for (int p=0;p<=50;++p) best[p]=2000000000;
        int sz=strlen(a);
        best[sz]=0;
        for (int i=sz-1;i>=0;--i) {
            for (int j=1;j<=n;++j) {
                if (x[j]-1+i>=sz) continue;
                int cur=0;
                int last=-100;
                for (int k=0;k<x[j];++k) {
                    if (s[j][k]==a[k+i]) continue;
                    else if (k-last<5) {
                        cur=1000000000;
                        break;
                    }
                    else ++cur,last=k;
                }
                if (best[i]>best[i+x[j]]+cur) best[i]=best[i+x[j]]+cur;
            }
        }
        printf("Case #%d: %d\n",z,best[0]);
    }
    return 0;
}
