#include <cstdio>
#include <cstring>
int main()
{
    freopen("a.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cas = 0;
    int n,s,p,a[110];
    while(t--)
    {
        scanf("%d%d%d",&n,&s,&p);
        for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
        int ans = 0;
        int cnt = 0;
        for(int i=0; i<n; i++)
        if(a[i]>=3*p-2)
        ans++;
        else if(a[i]>=3*p-4&&p>=2)
        cnt++;
        ans+=(cnt>s)?s:cnt;
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
