#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=1000010;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        printf("Case #%d: ",++cas);
        int x,y,i;
        scanf("%d%d",&x,&y);
        if(x>0)
        {
            for(i=0;i<x;i++)
            {
                printf("WE");
            }
        }
        else
        {
            for(i=0;i<abs(x);i++)
            {
                printf("EW");
            }
        }
        if(y>0)
        {
            for(i=0;i<y;i++)
            {
                printf("SN");
            }
        }
        else
        {
            for(i=0;i<abs(y);i++)
            {
                printf("NS");
            }
        }
        printf("\n");
    }


    
    fclose(stdin);
    fclose(stdout);
    return 0;
}