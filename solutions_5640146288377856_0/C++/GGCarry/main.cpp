#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    FILE * f1;
    FILE * f2;
    f1=fopen("a.in","r");
    f2=fopen("a.txt","w");
    int nn;
    fscanf(f1,"%d",&nn);
    for(int i=0;i<nn;i++)
    {
        int x,y,w;
        fscanf(f1,"%d%d%d",&x,&y,&w);
        int sum=0;
        for(int j=0;j<x-1;j++)
        {
            sum+=y/w;
        }
        sum+=(y/w-1);
        y-=w*(y/w-1);
        if(y==w)sum+=w;
        else sum+=w+1;
        fprintf(f2,"Case #%d: %d\n",i+1,sum);
    }
    return 0;
}
