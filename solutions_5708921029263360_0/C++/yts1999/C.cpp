#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct Data {
    int x,y,z;
    Data() {}
    Data(int tx,int ty,int tz) {
        x = tx;
        y = ty;
        z = tz;
    }
};

Data d[1010];
int v1[1000],v2[1000],v3[1000];

int main() {
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ",t);
        memset(v1,0,sizeof(v1));
        memset(v2,0,sizeof(v2));
        memset(v3,0,sizeof(v3));
        int a,b,c,K;
        scanf("%d%d%d%d",&a,&b,&c,&K);
        int tot = 0;
        for (int i = 1; i <= c; i++)
            for (int j = 1; j <= b; j++)
                for (int k = 1; k <= a; k++)
                    if (v1[i * 11 + j] < K && v2[j * 11 + k] < K && v3[i * 11 + k] < K) {
                        d[++tot] = Data(k,j,i);
                        v1[i * 11 + j]++;
                        v2[j * 11 + k]++;
                        v3[i * 11 + k]++;
                    }
        printf("%d\n",tot);
        for (int i = 1; i <= tot; i++)
            printf("%d %d %d\n",d[i].x,d[i].y,d[i].z);
    }
    return 0;
}

