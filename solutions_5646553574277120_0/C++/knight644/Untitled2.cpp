#include<stdio.h>
int main()
{
    FILE *ip,*op;
    ip=fopen("C:\\Users\\rimpa\\Desktop\\input.in","r");
    op=fopen("C:\\Users\\rimpa\\Desktop\\output.txt","a");
    long long t,c,d,v,i,j,a[30],k,s=0,x,flag=1;
    fscanf(ip,"%lld",&t);
    for(i=1;i<=t;i++)
    {
        fscanf(ip,"%lld%lld%lld",&c,&d,&v);
        for(j=0;j<d;j++)
        {
            fscanf(ip,"%lld",&a[j]);
            //printf("%lld\n",a[j]);
            //getchar();
        }
        fgetc(ip);
        s=0;
        for(j=1;j<=v;j++)
        {
            //printf("%lld\n",j);
            //getchar();
            flag=1;
            x=j;
            if(a[0]>j)
            {
                for(k=d;k>=1;k--)
                {
                    a[k]=a[k-1];
                }
                a[0]=j;
                d++;
                s++;
                //printf("1- %lld  %lld\n",d,s);
                continue;
            }
            for(k=d-1;k>=0;k--)
            {
                if(a[k]>x)
                    continue;
                if(a[k]==x)
                {
                    flag=1;
                    break;
                }
                x=x-a[k];
                flag=0;
                //printf("x=%lld k=%lld a[k]=%lld %lld\n",x,k,a[k],a[0]);
            }
            if(flag==0)
            {
                a[d]=a[d-1]+x;
                d++;
                s++;
                //printf("2- %lld  %lld\n",d,s);
            }
        }
        fprintf(op,"Case #%lld: %lld\n",i,s);
    }
    return 0;
}
