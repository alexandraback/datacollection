#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    #ifdef CODEBLOCKS
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CODEBLOCKS

    int t;
    scanf("%d",&t);

    for(int ti=1;ti<=t;ti++)
    {
        int n;
        scanf("%d",&n);

        char s[1010];
        scanf("%s",s);

        int ans=0;

        int now=0;

        for(int i=0;i<=n;i++)
        {
            int tmp=s[i]-'0';
            if(now<i)
            {
                ans+=i-now;
                now=i+tmp;
            }
            else
            {
                now=now+tmp;
            }
        }

        cout<<"Case #"<<ti<<": "<<ans<<endl;
    }
    return 0;
}
