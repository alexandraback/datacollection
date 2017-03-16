#include<cstdio>
#include<algorithm>
using namespace std;
int mp[8][4]=
            {
                0,1,2,3,
                0,4,3,6,
                0,7,4,1,
                0,2,5,4,
                0,5,6,7,
                0,0,7,2,
                0,3,0,5,
                0,6,1,0
            };
char s[150010];
int main()
{
    int T,n,now,t;
    long long k;
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        bool key1=false,key2=false,key3=false;
        scanf("%d%lld",&n,&k);
        scanf("%s",s);
        k=min( 8+(k%4) , k );
        for(int i=1;i<k;i++)
        {
            for(int j=0;j<n;j++)
            s[i*n+j]=s[j];
        }
        now=0;
        int cnt=0;
        for(int i=0;i<n*k;i++)
        {
            if(s[i]=='i')
            t=1;
            if(s[i]=='j')
            t=2;
            if(s[i]=='k')
            t=3;
            now=mp[now][t];

            if(!key1&&now==1)
                {
                    key1=true;
                    cnt++;
                }
            if((!key2)&&key1&&now==3)
                {
                    key2=true;
                    cnt++;
                }
        }

        if(key2&&now==4)
            printf("Case #%d: YES\n",cas);
        else
            printf("Case #%d: NO\n",cas);
    }
    return 0;
}

