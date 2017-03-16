#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("bs.in","r",stdin);
    freopen("bs.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int C=1;C<=T;C++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("Case #%d: ",C);
        if(a>0)
        {
            for(int i=1;i<=a;i++)
            {
                printf("WE");
            }
        }
        else
        {
            for(int i=1;i<=-a;i++)
            {
                 printf("EW");
            }
        }
        if(b>0)for(int i=1;i<=b;i++)printf("SN");
        else for(int i=1;i<=-b;i++)printf("NS");
        printf("\n");

    }
     return 0;
}
