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
        char s[128];
        int pos=0,neg=0;
        scanf("%s",s);
        for(char *p=s;*p;++p)
        {
            if(*p=='+')
            {
                int k=std::min(pos,neg+1);
                neg=pos+1,pos=k;
            }
            else if(*p=='-')
            {
                int k=std::min(neg,pos+1);
                pos=neg+1,neg=k;
            }
            else
            {
                printf("err: invalid symbol");
                return 0;
            }
        }
        printf("Case #%d: %d\n",tc,pos);
    }
    return 0;
}
