#include<stdio.h>
#include<stdlib.h>
struct box
{
    int num,id;
    double out;
};
int cmp(const void *a,const void *b)
{
    return ((box*)b)->num - ((box*)a)->num;
}
int cmp2(const void *a,const void *b)
{
    return ((box*)a)->id - ((box*)b)->id;
}
box arr[205];
int main()
{
    int a,b,n,t;
    double sum,mean,tmp;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&t);
    for(a=0;a<t;a++)
    {
        scanf("%d",&n);
        for(b=0,sum=0;b<n;b++)
        {
            scanf("%d",&arr[b].num);
            arr[b].id=b;
            sum+=arr[b].num;
        }
        qsort(arr,n,sizeof(box),cmp);
        tmp=sum*2;
        mean=tmp/n;
        for(b=0;b<n;b++)
            if(arr[b].num>mean)
            {
                tmp-=arr[b].num;
                arr[b].out=0;
                mean=tmp/(n-b-1);
            }
            else
                arr[b].out=(mean-arr[b].num)/sum*100.0;
        qsort(arr,n,sizeof(box),cmp2);
        printf("Case #%d: ",a+1);
        for(b=0;b<n;b++)
            printf("%lf ",arr[b].out);
        printf("\n");
    }
    scanf(" ");
}
