#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t,tt;
    scanf("%d",&tt);
    for(t=0;t < tt;t++)
    {
        int r,p;
        scanf("%d %d",&r,&p);
        int count = 1;
        p -= (r+1)*(r+1)-r*r;
        for(int i = r+3;true;i+=2)
        {
            // draw
            int area = i*i - (i-1)*(i-1);
            if(p >= area) {
                count++;
                p-= area;
            }
            else
                break;
        }
        printf("Case #%d: %d\n",t+1,count);
    }
}
