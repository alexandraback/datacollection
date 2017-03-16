#include <iostream>
using namespace std;

__int64 zta[150], ztb[150], ztya[150], ztyb[150], zans;
int n, m;

void work(int i, __int64 itmp, int j, __int64 jtmp, __int64 ans) {
    if (i > n || j > m) {
        zans = zans>ans?zans:ans;
        return;
    }
    if (ztya[i] == ztyb[j]) {
        if (itmp < jtmp)
            work(i + 1, zta[i + 1], j, jtmp - itmp, ans + itmp);
        else
            work(i, itmp - jtmp, j + 1, ztb[j + 1], ans + jtmp);
        return;
    }
    work(i + 1, zta[i + 1], j, jtmp, ans);
    work(i, itmp, j + 1, ztb[j + 1], ans);
}

int main() {    
	freopen("cs.in","r",stdin);
	freopen("cs.out","w",stdout);
    int c,cas,i;
    scanf("%d", &cas);
    for(c=1;c<=cas;c++){
        scanf("%d%d",&n,&m);
        for (i = 1;i <= n;i++)
            scanf("%I64d%I64dd",zta + i,ztya + i);
        for (i = 1;i <= m;i++)
            scanf("%I64d%I64d",ztb + i,ztyb + i);
        zans=0;
        work(1, zta[1], 1, ztb[1], 0);
        printf("Case #%d: %I64d\n", c, zans);
    }
    return 0;
}
