#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>

typedef long long LL;
char s[1024][16];
int main()
{
    int T;
    scanf("%d",&T);
    for(int tc=1;tc<=T;++tc)
    {
        int a,b,c,n;
        scanf("%d%d%d%d",&a,&b,&c,&n);
        n=std::min(c,n);
        printf("Case #%d: %d\n",tc,a*b*n);
        for(int i=0;i<a;++i)
        {
            for(int j=0;j<b;++j)
            {
                for(int k=0;k<n;++k)
                {
                    printf("%d %d %d\n",i+1,j+1,(i+j+k)%c+1);
                }
            }
        }
    }
    return 0;
}
