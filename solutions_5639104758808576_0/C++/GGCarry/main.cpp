#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    FILE* f;
    FILE* fo;
    f=fopen("A.txt","r");
    fo=fopen("AO.txt","w");
    int n;
    fscanf(f,"%d",&n);
    for(int i=0;i<n;i++)
    {
        int smax[1002]={0,};
        int scnt;
        fscanf(f,"%d",&scnt);
        for(int j=0;j<=scnt;j++)
        {
            fscanf(f,"%1d",&smax[j]);
        }

        int maxp=0,fr=0;
        for(int j=0;j<=maxp;j++)
        {
            maxp+=smax[j];
            if(maxp>=scnt)break;
            if(maxp<(j+1))
            {
                maxp++;
                fr++;
            }


        }
        fprintf(fo,"Case #%d: %d\n",i+1,fr);
    }
    return 0;
}
