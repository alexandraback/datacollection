#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=1000+10;
struct level
{
    int a,b;
} l[MAXN];
int n;
int f[MAXN];

bool cmp(level x,level y)
{
    return x.b<y.b;
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
    int tot;
    scanf("%d",&tot);
    for (int tc=1;tc<=tot;++tc)
    {
        scanf("%d",&n);
        int cur=0,ans=0,passed=0;
        memset(f,0,sizeof(f));
        for (int i=0;i<n;++i)
            scanf("%d%d",&l[i].a,&l[i].b);
        sort(l,l+n,cmp);
        while (true)
        {
            for (int j=0;j<n;++j)
                if (f[j]!=2 && l[j].b<=cur)
                {
                    cur+=2-f[j];
                    ++ans;
                    f[j]=2;
                    ++passed;
                }
            if (passed == n) break;
            int opt=-1,val=0;
            for (int j=n-1;j>=0;--j)
                if (f[j]==0 && l[j].a <=cur)
                {
                    val=l[j].b;
                    opt=j;
                    break;
                }
            if (opt==-1)
            {
                ans=-1;
                break;
            }
            f[opt]=1;
            ++cur;
            ++ans;
        }
        printf("Case #%d: ", tc);
        if (ans<0)
            puts("Too Bad");
        else
            printf("%d\n", ans);
    }
    return 0;
}
