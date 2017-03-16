#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

int main()
{
    int T;
    scanf("%d",&T);
    for(int tc=1;tc<=T;++tc)
    {
        int n,k=0;
        int f[10]={},rm=10;
        char s[32];
        scanf("%d",&n);
        if(!n)
        {
            printf("Case #%d: INSOMNIA\n",tc);
            continue;
        }
        while(rm)
        {
            k+=n;
            sprintf(s,"%d",k);
            for(char *p=s;*p;++p)
                if(!f[*p-'0'])f[*p-'0']=1,--rm;
        }
        printf("Case #%d: %d\n",tc,k);
    }
    return 0;
}
