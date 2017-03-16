#include<cstdio>
#include<iostream>
#include<stdio.h>
int main()
{
    int a[]={1,4,9,121,484,10201};
    int tcn,i,t,a1,b;
    FILE *fp=fopen("input.txt","r");
    FILE *f2=fopen("output.txt","w");
    fscanf(fp,"%d",&t);
    int sz=(sizeof(a)/sizeof(a[0]));
    for(tcn=1;tcn<=t;tcn++)
    {
                 fscanf(fp,"%d%d",&a1,&b);
                 int cnt=0;
                 for(i=0;i<sz;i++)
                 {
                      if(a[i]>=a1 && a[i]<=b)
                      cnt++;
                      }
                  fprintf(f2,"Case #%d: %d\n",tcn,cnt);
    }   
    return 0;
}
