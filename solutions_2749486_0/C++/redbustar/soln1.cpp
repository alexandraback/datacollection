#include<stdio.h>
int main()
{
    int x,y,n,t,i,j,k,mx,my;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        scanf("%d %d",&x,&y);
        while(x!=0)
        {
            if(x>0)
            {
                printf("WE");
                x--;
            }
            else
            {
                printf("EW");
                x++;
            }
        }
        while(y!=0)
        {
            if(y>0)
            {
                printf("SN");
                y--;
            }
            else
            {
                printf("NS");
                y++;
            }
        }
        printf("\n");
    }
    return 0;
}
