#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>
#include<math.h>
#include<assert.h>
#include<ctime>
#include<fstream>
clock_t beg=clock();

inline double elapse(clock_t x)
{
    return (double)(x-beg)/CLOCKS_PER_SEC;
}

using namespace std;



int main()
{
    int t;
    long long int pow2[62];
    pow2[0]=1;
    pow2[1]=2;
    for(int i=2;i<=61;i++)
        pow2[i]=2*pow2[i-1];

    FILE *ptr1,*ptr2;
    ptr1=fopen("inp.txt","r");
    ptr2=fopen("ops.txt","w");

    fscanf(ptr1,"%d",&t);
    //scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int a,b;
        fscanf(ptr1,"%d/%d",&a,&b);

        int flag=0;
        for(int j=0;j<=62;j++)
        {
            if(b==pow2[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            fprintf(ptr2,"Case #%d: impossible\n",i);

        else
        {
            int count=1;
            double x=a/(double)b;
            x*=2;

            for(;;)
            {
               if(x>=1)
                break;

                x*=2;
                count++;
            }
            fprintf(ptr2,"Case #%d: %d\n",i,count);
        }


    }


    fclose(ptr1);
    fclose(ptr2);
    return 0;
}
