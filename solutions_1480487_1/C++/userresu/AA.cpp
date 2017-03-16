#include <cstdio>
#include <algorithm>
using namespace std;

int N,X[201];
int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
    scanf("%d",&N);
    long long S=0;
    for (int i=1;i<=N;++i) scanf("%d",&X[i]),S+=X[i];
    printf("Case #%d: ", z);
    for (int i=1;i<=N;++i) {
        double l=0,r=1;
        while (r-l>=10e-12) {
              double m=(l+r)/2;
              double mm=X[i]+S*m;
              double sum=0;
              for (int j=1;j<=N;++j) if (j!=i && X[j]<=mm) sum+=(mm-X[j])/S;
              if (sum>=1-m) r=m;
              else l=m;
        }
        printf("%lf",100*l);
        if (i!=N) printf(" ");
    }
    printf("\n");
    }
    return 0;
}
