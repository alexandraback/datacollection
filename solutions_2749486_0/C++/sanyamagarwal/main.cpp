#include <cstdio>
#include <string.h>

int main()
{
    int test;
    scanf("%d",&test);

    for(int i=1;i<=test;i++)
    {
        int x, y;
        scanf("%d %d",&x,&y);
        char way[10000];
        int pointer=0;

        strcpy(way,"");

        while(!(x==0&&y==0))
        {
            if(x<0)
            {
                strcat(way,"EW");
                x++;
            }
            if(x>0)
            {
                strcat(way,"WE");
                x--;
            }if(y<0)
            {
                strcat(way,"NS");
                y++;
            }if(y>0)
            {
                strcat(way,"SN");
                y--;
            }
        }

        printf("Case #%d: %s\n",i,way);

    }
}
