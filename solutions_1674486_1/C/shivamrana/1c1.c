#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int a[1005][1005];
int main()
{
	FILE *in,*out;
	in=fopen("1c1.in","r");
	out=fopen("1c1.out","w");
    int t,ch=0;
    fscanf(in,"%d",&t);
    while(t--)
    {
              ch++;
              int n;
              fscanf(in,"%d",&n);
              int i,j,k;
              for(i=0;i<=n;i++)
              {
                               for(j=0;j<=n;j++)
                               {
                                                a[i][j]=0;
                                                }
                                                }
                                                int m,num;
                                                for(i=1;i<=n;i++)
                                                {
                                                                 fscanf(in,"%d",&m);
                                                                 for(j=1;j<=m;j++)
                                                                 {
                                                                                  fscanf(in,"%d",&num);
                                                                                  a[i][num]++;
                                                                                  }
                                                                                  }
                                                                                  for(k=1;k<=n;k++)
                                                                                  {
                                                                                                   for(i=1;i<=n;i++)
                                                                                                   {
                                                                                                                    for(j=1;j<=n;j++)
                                                                                                                    {
                                                                                                                    if(a[i][k]>0&&a[k][j]>0)
                                                                                                                    {
                                                                                                                    a[i][j]++;
                                                                                                                    }
                                                                                                                    }
                                                                                                                    }
                                                                                                                    }
                                                                                                                    k=0;
                                                for(i=1;i<=n;i++)
                                                {
                                                for(j=1;j<=n;j++)
                                                {
                                                if(a[i][j]>=2)
                                                {
                                                k=1;
                                                fprintf(out,"Case #%d: Yes\n",ch);
                                                break;
                                                }
                                                }
                                                if(k==1)
                                                break;
                                                }
                                                if(!k)
                                                fprintf(out,"Case #%d: No\n",ch);
                                                }
                                                return 0;
                                                }
