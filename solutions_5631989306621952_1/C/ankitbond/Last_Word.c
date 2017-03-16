#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fi,*fo;
    fi = fopen("input.txt","r");
    fo = fopen("output.txt","w");
    int t,i,n,k,j;
    char str[1001],ans[1001];
    fscanf(fi,"%d",&t);
    for(i=0;i<t;i++)
    {
        fscanf(fi,"%s",str);
        n = strlen(str);
        ans[0] = str[0];
        for(k=0;k<n;k++)
        {
            if(str[k] < ans[0])
            {
                ans[k] = str[k];
                ans[k+1] = '\0';
            }
            else
            {
                for(j=k;j>0;j--)
                {
                    ans[j] = ans[j-1];
                }
                ans[0] = str[k];
                ans[k+1] = '\0';
            }
        }
        fprintf(fo,"Case #%d: %s\n",i+1,ans);
    }
    fclose(fo);
    fclose(fi);
    return 0;
}
