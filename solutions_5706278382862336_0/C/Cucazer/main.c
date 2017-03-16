#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const int dubs[] = {1,2,4,8,16,32,64,128,256,512,1024};

bool isDub(int x)
{
    int j=0;
    while(dubs[j]<x) j++;
    if (dubs[j]==x) return true;
    else return false;
}

int degree(int x)
{
    int j=0;
    while(dubs[j]<x) j++;
    return j;
}

int dubSmaller(int x)
{
    if (dubs[degree(x)]==x) return degree(x);
    else return degree(x)-1;
}

int main()
{
    FILE *f,*fo;
    int j,i,t;
    static long p,q,m[50];
    char c;

    f=fopen("input.txt","r");
    fo=fopen("output.txt","w");
    fscanf(f,"%d",&t);
    for(j=1;j<=t;j++)
    {
        fscanf(f,"%ld%c%ld",&p,&c,&q);
        if (!isDub(q)) fprintf(fo,"Case #%d: impossible\n",j);
        else fprintf(fo,"Case #%d: %d\n",j,degree(q)-dubSmaller(p));
//            {
//                i=0;
//                m[0]=p;
//                while (i>=0)
//                {
//                    if (m[i]<q)
//                    {
//                        i++;
//                        m[i]=m[i-1]*2;
//                    }
//                    else
//                    {
//                        if (m[i]==q)
//                        {
//                            fprintf(fo,"Case #%d: %d\n",j,i);
//                            i=-1;
//                        }
//                        else
//                        {
//                            i--;
//                            if (i==-1) fprintf(fo,"Case #%d: impossible\n",j);
//                            else
//                            {
//                                m[i]--;
//                                i++;
//                                m[i]=m[i-1]*2;
//                            }
//                        }
//                    }
//                }
//            }
    }
    return 0;
}
