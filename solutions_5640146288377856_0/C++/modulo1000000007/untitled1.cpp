#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    FILE *ftr=fopen("input.txt","r");
    FILE *ftr1=fopen("output.txt","w");
    fscanf(ftr,"%d",&t);

    for(int i=1;i<=t;i++)
    {
        int r,c,w;
        fscanf(ftr,"%d%d%d",&r,&c,&w);
        int answer=0;

        if(c%w==0)
        {
            answer=c/w+w-1;
        }
        else
        {
            answer=c/w+w;
        }
        fprintf(ftr1,"Case #%d: %d\n",i,answer);
    }
return 0;}