#include<cstdio>
#include<cstring>
#include<cstring>
using namespace std;


int main()
{
    freopen("./D-small-attempt0.in","r",stdin);
    freopen("./out","w",stdout);
    int kase;
    scanf("%d",&kase);
    for(int z = 1;z <= kase;++z)
    {
        int k,c,s;
        scanf("%d %d %d",&k,&c,&s);
        printf("Case #%d:",z);
        for(int i = 1;i <= s;++i)
            printf(" %d",i);
        putchar('\n');
    }

    return 0;
}
