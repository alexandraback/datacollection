#include <cstdio>
#include <algorithm>

using namespace std;

struct dat
{
    int pl,dig;
}key[1100000];
int n,num[200010],len;
bool ok;

bool cmp(dat a,dat b)
{
    return a.dig<b.dig;
}

void init()
{
    int i,j,s;
    len=0;
    for (i = 1;i<=(1<<n)-1;i++)
    {
        s=0;
        for (j = 1;j<=n;j++)
        if ((i & (1<<(j-1)))!=0) s+=num[j];
        key[++len].dig=s;
        key[len].pl=i;
    }
}

void print(int s)
{
    int coun,i;
    coun=0;
    for (i = 1;i<=n;i++)
    if ((s & (1<<(i-1)))>0)
    {
        if (coun>0) printf(" ");
        printf("%d",num[i]);
        coun++;
    }
    printf("\n");
}

void solve()
{
    int i,j;
    ok=false;
    for (i = 1;i<=len;i++)
        for (j = i-1;j>=1;j--)
        if (key[i].dig==key[j].dig)
        {
            if ((key[i].pl & key[j].pl)==0)
            {
                print(key[i].pl);
                print(key[j].pl);
                ok=true;
                return;
            }
        }
}

int main()
{
    //freopen("Equal.in","r",stdin);
    //freopen("Equal.out","w",stdout);
    int t,tt,i;
    scanf("%d",&tt);
    for (t = 1;t<=tt;t++)
    {
        scanf("%d",&n);
        for (i = 1;i<=n;i++) scanf("%d",&num[i]);
        init();
        sort(key+1,key+1+len,cmp);
        printf("Case #%d:\n",t);
        solve();
        if (!ok) printf("Impossible\n");
    }
}
