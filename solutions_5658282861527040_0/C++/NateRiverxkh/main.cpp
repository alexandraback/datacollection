#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 5010
#define maxe 500010
#define INF 1<<30
int n,m,len[maxn],id[maxn],nxt[maxn];
char s[110][110];
int main()
{
    int ncase,a,b,c,tt=0,i,j;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d %d %d",&a,&b,&c);
        int ans=0;
        for(i=0;i<a;i++)
            for(j=0;j<b;j++)if((i&j)<c)
                ans++;
        printf("Case #%d: %d\n",++tt,ans);
    }
    return 0;
}
