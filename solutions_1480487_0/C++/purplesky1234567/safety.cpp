#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int test,count,n,i,flag[201],wflag,t;
    double s[201],a[201],temp,total,avr,total2;
    FILE *fin,*fout;
    if((fin=fopen("A-small-attempt3.in","r"))==NULL)exit(0);
    if((fout=fopen("A-small-attempt3.out","w"))==NULL)exit(0);
    fscanf(fin,"%d",&test);
    for(count=1;count<=test;count++)
    {
       fscanf(fin,"%d",&n);
       total=0;
       for(i=1;i<=n;i++){fscanf(fin,"%lf",&s[i]);total+=s[i];flag[i]=1;}
       avr=2*total/n;
       wflag=0;t=0;
       for(i=1;i<=n;i++){if(s[i]>avr){a[i]=0.000000;flag[i]=0;t++;wflag=1;}}
       if(wflag)
       {
                total2=0;
                for(i=1;i<=n;i++){if(flag[i])total2+=s[i];}
                avr=(total+total2)/(n-t);
       }
       for(i=1;i<=n;i++){if(flag[i])a[i]=(avr-s[i])/total*100;}                         
       fprintf(fout,"Case #%d: ",count);
       for(i=1;i<=n;i++)
       {
           if(i!=n)fprintf(fout,"%.6lf ",a[i]);
           else fprintf(fout,"%.6lf\n",a[i]);
       }
    }
    return 0;
}
