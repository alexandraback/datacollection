#include<bits/stdc++.h>
using namespace std;


int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        long long k,c,s;
        scanf("%lld%lld%lld",&k,&c,&s);
        printf("Case #%d:",ti++);
        if(s==k)
        {
            for(int i=0;i<k;i++)
                printf(" %d",i+1);
            puts("");
        }
        else
        {
            long long len=1,st=0;
            for(int i=1;i<c;i++)
                len*=k;
            if(s>=(k+1)/2)
            {
                for(int i=0;i<(k+1)/2;i++)
                {
                    st+=2;
                    printf(" %lld",st);
                    st+=2*len;
                }
                puts("");
            }
            else puts(" IMPOSSIBLE");
        }
    }
	return 0;
}
