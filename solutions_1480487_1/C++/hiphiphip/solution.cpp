#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct yo
{
    double a;
    int ind;
}s[300];
double ans[300];
int compare(const void *x, const void *y)
{
    if(((yo*)x)->a>((yo*)y)->a) return 1;
    else if(((yo*)x)->a==((yo*)y)->a) return 0;
    else return -1;
}
main()
{
    FILE *fin = fopen("A.in","r");
    FILE *fout = fopen("B.out","w");
    int t,n;
    double sum,left;
    fscanf(fin,"%d",&t);
    for(int ll=0;ll<t;ll++)
    {
        for(int i=0;i<n;i++) ans[i]=0.0;
        fscanf(fin,"%d",&n);
        sum=0.0;
        for(int i=0;i<n;i++)
        {
            fscanf(fin,"%lf",&s[i].a);
            sum+=s[i].a;
            s[i].ind=i;
        }
        s[n].a=1000000.0;
        qsort(s,n,sizeof(yo),compare);
        left=sum;
        for(int i=0;i<n&&left>0.0;i++)
        {
            if(left>1.0*(s[i+1].a-s[i].a)*(i+1))
            {
                for(int j=0;j<=i;j++)
                {
                    ans[s[j].ind]+=s[i+1].a-s[i].a;
                }
                left-=1.0*(s[i+1].a-s[i].a)*(i+1);
            }
            else
            {
                for(int j=0;j<=i;j++)
                {
                    ans[s[j].ind]+=1.0*left/(i+1);
                }
                left=0.0;
            }
        }
        //sum*=2.0;
        fprintf(fout,"Case #%d: ",ll+1);
        for(int i=0;i<n;i++) fprintf(fout,"%.6lf ",100.0*ans[i]/sum);
        
        
        
        /*for(int i=0;i<n;i++)
        {
            if((2.0/n-a[i]/sum)*100.0<=0.0) fprintf(fout,"%.6lf ",0);
            else fprintf(fout,"%.6lf ",(2.0/n-a[i]/sum)*100.0);
        }*/
        fprintf(fout,"\n");
    }
    
    
    
    
    
    //scanf(" ");
}
