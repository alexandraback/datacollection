#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    freopen("1.in","r",stdin);
    freopen("2.txt","w",stdout);
    int T;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        printf("Case #%d: ",++cas);
        int x,y;
        scanf("%d%d",&x,&y);
        while(y)
        {
            if(y<0)
            {
                printf("NS");
                y++;
            }
            else
            {
                printf("SN");
                y--;
            }
        }
        while(x)
        {
            if(x<0)
            {
                printf("EW");
                x++;
            }
            else
            {
                printf("WE");
                x--;
            }
        }
        puts("");
    }
}
