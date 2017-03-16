#include <cstdio>
char s[1005];
int main(int argc, char const *argv[])
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int T,n,ca=0;
    scanf("%d",&T);
    while(T--)
    {
        int ans=0,now=0;
        scanf("%d",&n);
        scanf("%s",s);
        for (int i=0;i<=n;i++)
        {
            int need=i;
                if (need>now) {
                    ans+=need-now;
                    now=need+s[i]-'0';
                }
                else now+=s[i]-'0';
        }
        printf("Case #%d: %d\n",++ca,ans );

    }
    return 0;
}