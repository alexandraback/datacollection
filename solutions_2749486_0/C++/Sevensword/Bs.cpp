#include<stdio.h>
#include<math.h>
#include<iostream>
#include<mem.h>

int main()
{
    int i,j,k,n,t,r,v,x,y;
    long long now,temp;
    int min,time;
    scanf("%d",&t);
    //scanf("%c",&fre);
    for(k=1;k<=t;k++)
    {

        scanf("%d %d",&x,&y);
        printf("Case #%d: ",k);
        if(abs(x)<=abs(y))
        {
            i=1;
            if(x!=0)
            {
                    while(i*(i+1)/2<abs(x))
                    {
                        i++;
                    }
                    if(x>0)
                    {
                        for(j=1;j<=i;j++) printf("E");
                        n = i*(i+1)/2;
                        //printf("%d",n);
                        for(j=1;j<=n-x;j++) { printf("EW"); i+=2; }
                    }
                    else
                    {
                        for(j=1;j<=i;j++) printf("W");
                        n = i*(i+1)/2;
                        for(j=1;j<=x+n;j++) { printf("WE"); i+=2; }
                    }
                    i++;
            }
            //printf("i=%d",i);
            if(y!=0)
            {
                    temp =0;

                    if(y>0)
                    {
                        while(temp<y)
                        {
                            //i++;
                            temp+=i;
                            i++;
                            printf("N");

                        }
                        //for(j=1;j<=i;j++) printf("E");
                        //n = i*(i+1)/2;
                        for(j=1;j<=temp-y;j++) { printf("NS"); i+=2; }
                    }
                    else
                    {
                        while(temp>y)
                        {
                            //i++;
                            temp-=i;
                            i++;
                            printf("S");

                        }
                        //for(j=1;j<=i;j++) printf("E");
                        //n = i*(i+1)/2;
                        for(j=1;j<=y-temp;j++) { printf("SN"); i+=2; }
                    }
            }

        }

        else
        {
            i=1;
            if(y!=0)
            {
                    while(i*(i+1)/2<abs(y))
                    {
                        i++;
                    }
                    if(y>0)
                    {
                        for(j=1;j<=i;j++) printf("N");
                        n = i*(i+1)/2;
                        //printf("n=%d",n);
                        for(j=1;j<=n-y;j++) { printf("NS"); i+=2; }
                    }
                    else
                    {
                        for(j=1;j<=i;j++) printf("S");
                        n = i*(i+1)/2;
                        //printf("n=%d y=%d",n,y);
                        for(j=1;j<=y+n;j++) { printf("SN"); i+=2; }
                    }
                    i++;
            }
            if(x!=0)
            {
                    temp =0;

                    if(x>0)
                    {
                        while(temp<x)
                        {
                            //i++;
                            temp+=i;
                            i++;
                            printf("E");

                        }
                        //for(j=1;j<=i;j++) printf("E");
                        //n = i*(i+1)/2;
                        for(j=1;j<=temp-x;j++) { printf("EW"); i+=2; }
                    }
                    else
                    {
                        while(temp>x)
                        {
                            //i++;
                            temp-=i;
                            i++;
                            printf("W");

                        }
                        //for(j=1;j<=i;j++) printf("E");
                        //n = i*(i+1)/2;
                        for(j=1;j<=x-temp;j++) { printf("WE"); i+=2; }
                    }
            }

        }
        printf("\n");
    }

    return 0;
}
