#include<stdio.h>
#include<stdlib.h>

int comp(const void *a,const void *b);
long long a[1000];
int main()
{
long long  somme,s,n,i,test,t,cnt;

scanf("%lld",&test);
for(t=1;t<=test;t++)
{
scanf("%lld %lld",&s,&n);

for(i=0;i<n;i++)
scanf("%lld",&a[i]);
qsort(a,n,sizeof(long long),comp);
somme=s;
cnt=0;

for(i=0;i<n;i++)
{
        if(a[i]<somme)
        somme+=a[i];
        else
        {
                if((2*somme-1)>a[i])
                {
                cnt++;
                somme=2*somme-1+a[i];
                }
                else
                {
                cnt=cnt+n-i;
                break;
                }
        }
}

printf("Case #%lld: %lld\n",t,cnt);

}

return 0;

}
int comp(const void *a,const void *b)
{
const long long *p=(long long *)a;
const long long *q=(long long *)b;
return *p-*q;

}
