#include<stdio.h>
#include<conio.h>
int main()
{
    int t,i,j,k;
    double c,f,x,p,q,farm,n,rate,prate,time,cfarm;
    FILE *y,*z;
    y=fopen("D:\\codejam\\a.in","r");
    z=fopen("D:\\codejam\\q.out","w+");
    fscanf(y,"%d",&t);
    for(i=1;i<=t;i++)
    {
                     fscanf(y,"%lf %lf %lf",&c,&f,&x);
                     if(x/2<c/2)
                     {
                              fprintf(z,"Case #%d: %.7lf\n",i,x/2);
                     }
                     else
                     {
                         rate=2.0;
                         cfarm=0;
                         time=0;
                         p=x/2;
                         q=x/2;
                         while(p>=q)
                         {
                                    p=q;
                                    prate=rate;
                                    farm=c/prate;
                                    cfarm+=farm;
                                    rate+=f;
                                    n=x/rate;
                                    q=cfarm+n;
                         }
                         fprintf(z,"Case #%d: %.7lf\n",i,p);
                     }
                     
    }                                             
    fclose(y);
    fclose(z);
    getch();
}
