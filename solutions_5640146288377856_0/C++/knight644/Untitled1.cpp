#include<stdio.h>
int main()
{
    FILE *ip,*op;
    ip=fopen("C:\\Users\\rimpa\\Desktop\\input.in","r");
    op=fopen("C:\\Users\\rimpa\\Desktop\\output.txt","a");
    long long t,r,c,w,i,j,s;
    fscanf(ip,"%lld",&t);
    for(i=1;i<=t;i++)
    {
        fscanf(ip,"%lld%lld%lld",&r,&c,&w);
        s=c/w;
        s=s*r;
        if(c%w==0)
            s=s+w-1;
        else
            s=s+w;
        fprintf(op,"Case #%lld: %lld\n",i,s);
        s=0;
    }
    return 0;
}
        
