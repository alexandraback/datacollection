#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 15;
const int MAXE = 10;
int main()
{
   freopen("B-small.in","r",stdin);
   freopen("B-small.out","w",stdout);
   int cas,T,E,R,N,i,j,k;
   int value[MAXN];
   int f[MAXN][MAXE];
   scanf("%d",&T);
   for(cas = 1;cas <= T;++cas) {
    scanf("%d %d %d",&E,&R,&N);
    for(i = 1;i <= N;++i) {
        scanf("%d",&value[i]);
    }
    memset(f,0,sizeof(f));
    for(i = N;i >= 1;--i) {
        for(j = 0;j <= E;++j) {
            for(k = 0;k <= j;++k) {
                f[i][j] = max(f[i][j],value[i] * k + f[i + 1][min(E,j - k + R)]);
            }
        }
    }
    printf("Case #%d: %d\n",cas,f[1][E]);
   }
}
