#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
return (*(int *)a- *(int * )b);
}

int main()
{
int t,l=1,n,i;
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
scanf("%d",&t);

for(;l<=t;l++){
scanf("%d",&n);
double a[300],sum=0.0f;
for(i=0;i<n;i++){scanf("%lf",&a[i]);sum+=a[i];}
double x=(2.0f*sum)/(double)n,sum2=0.0f;int c=0;
for(i=0;i<n;i++){if(a[i]<x){sum2+=a[i];c++;}}
double x1=(sum+sum2)/c;
printf("Case #%d: ",l);
for(i=0;i<n;i++)if(a[i]>=x)printf("0.000000 ");else printf("%lf ",((x1-a[i])/sum)*100.0f);
printf("\n");}
return 0;
}
