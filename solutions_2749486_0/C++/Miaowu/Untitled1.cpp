#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct
{
    int x,y;
}Point;

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int T,i,j,n,cnt=1;
    Point end;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&end.x,&end.y);
        printf("Case #%d: ",cnt++);
        for (i=0;i<abs(end.x);i++)
        {
            if (end.x>0) printf("WE");
            else printf("EW");
        }
        for (i=0;i<abs(end.y);i++)
        {
            if (end.y>0) printf("SN");
            else printf("NS");
        }
        printf("\n");
    }
    return 0;
}
