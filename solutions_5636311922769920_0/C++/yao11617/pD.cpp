#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1024

int main()
{
    int T;
    scanf("%d",&T);
    for(int tc=1;tc<=T;++tc)
    {
        int k,c,s;
        scanf("%d%d%d",&k,&c,&s);
        printf("Case #%d:",tc);
        if(s*c<k)printf(" IMPOSSIBLE");
        else
        {
            for(int i=0;i<k;i+=c)
            {
                int j=0,e=std::min(c,k-i);
                long long p=0,d=1;
                while(j<e)
                {
                    p+=(i+j)*d;
                    ++j,d*=k;
                }
                printf(" %lld",p+1);
            }
        }
        printf("\n");
    }
    return 0;
}
