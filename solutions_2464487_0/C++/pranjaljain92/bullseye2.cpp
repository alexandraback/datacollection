#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

int main()
{
    FILE *fin=fopen("A-small-attempt0.in","r");
    FILE *fout=fopen("ouput12345.txt","w");
    int beg,end,i,j,t,p,mid,r,x;
    fscanf(fin,"%d",&t);
    for(x=1;x<=t;x++)
    {
        fscanf(fin,"%d%d",&r,&p);
        beg=1;
        end=p/(2*r+1);
        while(beg<end)
        {
            mid=(beg+end+1)/2;
            if(p>=(2*r*mid+2*mid*mid-mid))
            beg=mid;
            else
            end=mid-1;
        }
        fprintf(fout,"Case #%d: %d\n",x,beg);

    }
    return(0);

}
