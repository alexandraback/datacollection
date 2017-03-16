#include<stdio.h>
#include<stdlib.h>

void find(int x, int y)
{
    int end,t=0,min = abs(x),max = abs(y),a[502],i=0,sum=0;
    char c[5];
    if(min>max)
    {
        min = abs(y);
        max = abs(x);
    }
    a[min-1] = 3;
    for(i=0;i<(min)-1;i++)
    {
        if(i%2 == t)
        {
            sum = sum-(i+1);
            a[i] = 1;
        }
        else
        {
            sum = sum+(i+1);
            a[i] = 2;
        }
        if(sum == max)
        break;
    }
    t = 1;
    for(i= min;i<500;i++)
    {
        if(i%2 == t)
        {
            sum = (sum)-(i+1);
            a[i] = 1;
        }
        else
        {
            sum = (sum)+(i+1);
            a[i] = 2;
        }
        if(sum == max)
        break;
    }
    end = i;
    if(abs(y)>abs(x))
    {
        if(x>0)
        {
            c[3] = 'E';
            c[4] = 'W';
        }
        else
        {
            c[3] = 'W';
            c[4] = 'E';
        }
        if(y>0)
        {
            c[1] = 'S';
            c[2] = 'N';
        }
        else
        {
            c[1] = 'N';
            c[2] = 'S';
        }
    }
    else
    {
        if(y>0)
        {
            c[3] = 'N';
            c[4] = 'S';
        }
        else
        {
            c[3] = 'S';
            c[4] = 'N';
        }
        if(x>0)
        {
            c[1] = 'W';
            c[2] = 'E';
        }
        else
        {
            c[1] = 'E';
            c[2] = 'W';
        }
    }
    for(i=0;i<=end;i++)
    {
        printf("%c",c[a[i]]);
    }
    printf("\n");
}
int main()
{
    int i,t,x,y;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&x,&y);
        printf("Case #%d: ",i+1);
        find(x,y);
    }
    return 0;
}
