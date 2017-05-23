#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("A-large.in","r", stdin);
    freopen("A-large.out","w", stdout);
    int t,cs=1,n;
    char s[100005];

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        scanf("%s",s);

        int tot=0, ans=0;
        for(int i=0; i<=n; i++)
        {
            if(tot<i && s[i]!='0')
            {
                ans+= i-tot;
                tot=i;
            }
            tot+= s[i]-'0';
        }
        printf("Case #%d: %d\n",cs++,ans);
    }
}
