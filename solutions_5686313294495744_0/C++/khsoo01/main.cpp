#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int tc,n,dt[88888],len[18][2];
char a[18][2][30];

bool same(int ai, int ab, int bi, int bb) {
    if(len[ai][ab] != len[bi][bb]) return false;
    for(int i=0;i<len[ai][ab];i++) {
        if(a[ai][ab][i] != a[bi][bb][i]) return false;
    }
    return true;
}

int solve(int idx) {
    if(dt[idx]!=-1) return dt[idx];
    dt[idx] = 0;
    int i,j;
    for(i=0;i<n;i++) {
        if((1<<i)&idx) {
            bool f1 = false, f2 = false;
            for(j=0;j<n;j++) {
                if(i==j) continue;
                if((1<<j)&idx) {
                    if(!f1 && same(i,0,j,0)) f1 = true;
                    if(!f2 && same(i,1,j,1)) f2 = true;
                }
            }
            dt[idx] = max(dt[idx], solve(idx-(1<<i))+(f1 && f2));
        }
    }
    return dt[idx];
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k;
    scanf("%d",&tc);
    for(k=1;k<=tc;k++) {
        scanf("%d",&n);
        for(i=0;i<n;i++) {
            for(j=0;j<len[i][0];j++) a[i][0][j] = 0;
            for(j=0;j<len[i][1];j++) a[i][1][j] = 0;
            scanf("%s%s",&a[i][0],&a[i][1]);
            len[i][0] = strlen(a[i][0]);
            len[i][1] = strlen(a[i][1]);
        }
        memset(dt,-1,sizeof(dt));
        printf("Case #%d: %d\n",k,solve((1<<n)-1));
    }
}
