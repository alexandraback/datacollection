#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t,n,i,j,k, d_war,war;
    double a[1000]={0.0},b[1000]={0.0};
    FILE *y,*z;
    y=fopen("D:\\codejam\\a.in","r");
    z=fopen("D:\\codejam\\q.out","w+");
    fscanf(y,"%d",&t);
    for(k=1;k<=t;k++)
    {
                     d_war=0;
                     war=0;
                     fscanf(y,"%d",&n);
                     printf("%d",n);
                     for(j=0;j<n;j++)
                     fscanf(y,"%lf",&a[j]);
                     for(j=0;j<n;j++)
                     fscanf(y,"%lf",&b[j]);
                     sort(a,a+n);
                     sort(b,b+n);
                    
                     i=0,j=0;
                     while(i<n&&j<n)
                     {
                                    if(a[i]>b[j])
                                    {
                                                       d_war++;
                                                       i++;
                                                       j++;
                                    }
                                    else
                                    i++;
                     }
                     i=0,j=0;
                     while(i<n&&j<n)
                     {
                                    if(a[i]<b[j])
                                    {
                                                       war++;
                                                       i++;
                                                       j++;
                                    }
                                    else
                                    j++;
                     }
                     fprintf(z,"Case #%d: %d %d\n",k,d_war,n-war);
    }                                             
    fclose(y);
    fclose(z);
    //getch();
}

