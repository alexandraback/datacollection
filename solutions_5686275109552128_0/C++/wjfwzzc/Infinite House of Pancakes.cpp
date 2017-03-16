#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1005;
int p[MAXN];
int main() {
    //freopen("B-small-attempt3.in","r",stdin);
    //freopen("B-small-attempt3.out","w",stdout);
    int t,d;
    scanf("%d",&t);
    for(int cas=1; cas<=t; ++cas) {
        scanf("%d",&d);
        int pmax=0;
        for(int i=0; i<d; ++i) {
            scanf("%d",&p[i]);
            pmax=max(pmax,p[i]);
        }
        int ans=pmax;
        for(; pmax>1; --pmax) {
            int tmp=0;
            for(int i=0; i<d; ++i)
                tmp+=(p[i]+pmax-1)/pmax-1;
            ans=min(ans,pmax+tmp);
        }
        printf("Case #%d: %d\n",cas,ans);
    }
}
