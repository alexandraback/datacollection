#include<cstdio>
#include<fstream>
using namespace std;
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B.out","w",stdout);
    int t;
    int x,y;
    int i=0;
    scanf("%d",&t);
    while(i<t)
    {
        printf("Case #%d: ",i+1);
        scanf("%d %d",&x,&y);
        if(x>0)
        {
            int j=0;
            while(j<x)
            {
                printf("WE");
                j++;
            }
        }
        else
        {
            x=-x;
            int j=0;
            while(j<x)
            {
                printf("EW");
                j++;
            }
        }
        if(y>0)
        {
            int j=0;
            while(j<y)
            {
                printf("SN");
                j++;
            }
        }
        else
        {
            y=-y;
            int j=0;
            while(j<y)
            {
                printf("NS");
                j++;
            }
        }
        printf("\n");
        i++;
    }
    return 0;
}
