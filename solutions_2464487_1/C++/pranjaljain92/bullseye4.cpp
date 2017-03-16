#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

int main()
{
    FILE *fin=fopen("A-large.in","r");
    FILE *fout=fopen("ouput1234567.txt","w");
    unsigned long long int beg,end,p,mid,r;
    int t,x;
    fscanf(fin,"%d",&t);
    for(x=1;x<=t;x++)
    {
        fscanf(fin,"%llu%llu",&r,&p);
        beg=1;
        end=p/(2*r+1);
        while(beg<end)
        {
            mid=(beg+end+1)/2;
            if(((double)p)/mid>=(2*r+2*mid-1))
            beg=mid;
            else
            end=mid-1;
        }
        fprintf(fout,"Case #%d: %llu\n",x,beg);

    }
    return(0);

}
