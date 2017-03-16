#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fi,*fo;
    fi = fopen("input.txt","r");
    fo = fopen("output.txt","w");
    int t,n,i,j,k,arr[2500],temp,count;
    fscanf(fi,"%d",&t);
    for(i=0;i<t;i++)
    {
        for(j=0;j<2500;j++)
            arr[j] = 0;
        fscanf(fi,"%d",&n);
        int num[n];
        for(j=0;j<2*n-1;j++)
        {
            for(k=0;k<n;k++)
            {
                fscanf(fi,"%d",&temp);
                arr[temp-1]++;
            }
        }
        count = 0;
        for(j=0;j<2500;j++)
        {
            if(arr[j]%2!=0)
            {
                num[count] = j;
                count++;
            }
        }
        fprintf(fo,"Case #%d: ",i+1);
        for(j=0;j<n;j++)
            fprintf(fo,"%d ",num[j]+1);
        fprintf(fo,"\n");
    }
    return 0;
}
