#include <cstdio>
#include <cstring>
int a[110][110];
int x,y;
int findmin(int n,int m)
{
    int tmp = 1000;
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
    if(a[i][j]&&a[i][j]<tmp)
    {
        tmp = a[i][j];
        x = i;
        y = j;
    }
    return tmp;
}
bool judge(int n,int m)
{
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
    if(a[i][j]) return 0;
    return 1;
}
bool clean(int x,int y,int n,int m)
{
    int tmp = a[x][y];
    bool yes = 1,ans = 0;
    for(int i=0; yes&&i<m; i++)
    if(a[x][i]&&a[x][i]!=tmp) yes = 0;
    if(yes)
    {
        for(int i=0; yes&&i<m; i++) a[x][i] = 0;
        ans = 1;
    }
    yes = 1;
    for(int i=0; yes&&i<n; i++)
    if(a[i][y]&&a[i][y]!=tmp) yes = 0;
    if(yes)
    {
        for(int i=0; yes&&i<n; i++) a[i][y] = 0;
        ans = 1;
    }
    return ans;
}
int main()
{
    freopen("a.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        scanf("%d",&a[i][j]);
        printf("Case #%d: ",t);
        if(judge(n,m))
        {
            puts("YES");
            continue;
        }
        int tmp;
        bool yes = 1;
        while((tmp=findmin(n,m))!=1000)
        {
            if(!clean(x,y,n,m))
            {
                yes = 0;
                break;
            }
        }
        if(yes) puts("YES");
        else puts("NO");
    }
    return 0;
}
