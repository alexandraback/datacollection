#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
FILE *fin = fopen("input.txt","r");
FILE *fout = fopen("output.txt","w");
using namespace std;
void pro()
{
    int tx,ty,step=1;
    int x=0,y=0;
    fscanf(fin,"%d",&tx);
    fscanf(fin,"%d",&ty);

    while(y!=ty&&x!=tx)
    {
        if(ty>y)
        {
            fprintf(fout,"N");
            y+=step;
            if(y>ty)
            {
                int term=y-ty;
                for(int i=0;i<term;i++)
                {
                    step++;
                    fprintf(fout,"N");
                    y+=step;
                    step++;
                    fprintf(fout,"S");
                    y-=step;
                }
            }
        }
        if(ty<y)
        {
            fprintf(fout,"S");
            y-=step;
            if(y<ty)
            {
                int term=ty-y;
                for(int i=0;i<term;i++)
                {
                    step++;
                    fprintf(fout,"S");
                    y-=step;
                    step++;
                    fprintf(fout,"N");
                    y+=step;
                }
            }
        }
        step++;
        if(tx>x)
        {
            fprintf(fout,"E");
            x+=step;
            if(x>tx)
            {
                int term=x-tx;
                for(int i=0;i<term;i++)
                {
                    step++;
                    fprintf(fout,"E");
                    x+=step;
                    step++;
                    fprintf(fout,"W");
                    x-=step;
                }
            }
        }
        if(tx<x)
        {
            fprintf(fout,"W");
            x-=step;
            if(x<tx)
            {
                int term=tx-x;
                for(int i=0;i<term;i++)
                {
                    step++;
                    fprintf(fout,"W");
                    x-=step;
                    step++;
                    fprintf(fout,"E");
                    x+=step;
                }
            }
        }
        step++;
    }
    fprintf(fout,"\n");
}
int main()
{
    int n;
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fprintf(fout,"Case #%d: ",i+1);
        pro();
    }
    return 0;
}
