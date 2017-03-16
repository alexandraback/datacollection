#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,k,t;
    FILE* fin = fopen("A.in","r");
    FILE* fout= fopen("A.out","w");
    fscanf(fin,"%d",&t);
    for (i=1;i<=t;++i)
    {
        int n,s[1000],sum=0;
        double mpoint, mvote[1000]={0}, mean;
        fscanf(fin, "%d",&n);
        for (j=0;j<n;++j)
        {
            fscanf(fin, "%d",&s[j]);
            sum += s[j];
        }
        fprintf(fout,"Case #%d:",i);
        mean = (double)sum*2/n;
        mpoint = sum;
        int temp=0;
        for (j=0;j<n;++j)
        {
            if (s[j] < mean)
            {
                     temp++;
                     mpoint += s[j];
            }
        }
        mpoint = mpoint / temp;
        for (j=0;j<n;++j)
        {
            if (s[j] < mean) mvote[j] = 100*(mpoint - s[j])/sum;
        }
        for (j=0;j<n;++j)
        {

            fprintf(fout," %.6lf",mvote[j]);
        }
 
        fprintf(fout,"\n");
    }
    return 0;
}
        
        
