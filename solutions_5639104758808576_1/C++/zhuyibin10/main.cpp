#include <cstdio>

using namespace std;

int main()
{
    int T,t;
    freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        int sm,s[1010],i,ans=0,sum=0;
        char S[1010];
        scanf("%d",&sm);
        getchar();
        for(i=0;i<=sm;i++)
        {
            S[i]=getchar();
            s[i]=S[i]-'0';
        }
        printf("Case #%d: ",t);
        for(i=0;i<sm;i++)
        {
            sum+=s[i];
            if((sum+ans)<i+1)
            {
                ans=i+1-sum;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
