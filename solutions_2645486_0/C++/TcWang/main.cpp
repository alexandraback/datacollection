#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int Maxn=1000;
int E,R,N,v[Maxn],f[Maxn][Maxn];

void Enlarge(int i,int j) {
    //printf("%d %d %d\n",i,j,f[i][j]);
    for (int x=0;x<=j;x++)
        if (f[i+1][min(E,j-x+R)]<f[i][j]+v[i+1]*x)
            f[i+1][min(E,j-x+R)]=f[i][j]+v[i+1]*x;
}

int main()
{
    int T;
    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    freopen("output.txt","w",stdout);
    for (int cases=1;cases<=T;cases++) {
        memset(f,0,sizeof(f));
        scanf("%d%d%d",&E,&R,&N);
        for (int i=1;i<=N;i++) scanf("%d",&v[i]);
        Enlarge(0,E);
        for (int i=1;i<N;i++)
            for (int j=0;j<=E;j++)
                Enlarge(i,j);
        int ans=f[N][0];
        for (int i=1;i<=E;i++) if (f[N][i]>ans) ans=f[N][i];
        printf("Case #%d: %d\n",cases,ans);
    }

    return 0;
}
