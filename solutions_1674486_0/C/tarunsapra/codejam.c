#include<stdio.h>
#include<stdlib.h>

int t,c,i,j,n,k;
int main()
{
    FILE *fr,*fw;
    fr=fopen("/Users/home/Desktop/A-small-attempt0.in","r");
    fw=fopen("/Users/home/Desktop/output.txt","w");
    
    fscanf(fr,"%d",&t);
    for(c=1;c<=t;c++)
    {
        int a[55][55]={0};
        fprintf(fw,"Case #%d: ",c);
        fscanf(fr,"%d",&n);
        for(i=1;i<=n;i++)
        {
            fscanf(fr,"%d",&k);
            while(k--)
            {
                fscanf(fr,"%d",&j);
                a[i][j]=1;
            }
        }
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                printf("%d\t",a[i][j]);
        printf("\n");
        }*/
        for(k=1;k<=n/* && ans==0*/;k++)
        {
            for(i=1;i<=n/* && ans==0*/;i++)
            {
                if(a[i][k]==1)
                {
                    for(j=1;j<=n/* && ans==0*/;j++)
                    {
                        a[i][j]+=a[k][j];
                        if(a[i][j]>=2)
                        {
                            //printf("i=%d j=%d k=%d\n",i,j,k);
                            goto yes;
                            //ans=1;
                        }
                    }
                }
            }
        }
        fprintf(fw,"No\n");
        continue;
    yes:
        {
            fprintf(fw,"Yes\n");
        }
    }
    return 0;
}
