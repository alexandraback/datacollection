#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;


class SUM
{
    public:
    int sum,mask;
}sums1[(1<<20)+5],sums2[(1<<20)+5];
bool operator < (const SUM &a,const SUM &b)
{
    return a.sum<b.sum;
}
int arr[25];
int n;

void print(int mask1,int mask2)
{
    int c,c2;
    bool f=0;
    for (c=0;c<n;c++)
        if (mask1&(1<<c))
        {
            if (f)printf(" ");
            f=1;
            printf("%d",arr[c]);
        }
    printf("\n");
    f=0;
    for (c=0;c<n;c++)
        if (mask2&(1<<c))
        {
            if (f)printf(" ");
            f=1;
            printf("%d",arr[c]);
        }
    printf("\n");
    return ;
}
int lower_bound(SUM sum)
{
    int s=0,e=(1<<n)-2;
    int reti=-1;
    while (s<=e){
        int mid = (s+e)/2;
        if (sums2[mid].sum == sum.sum)reti=mid;
        if (sums2[mid].sum>=sum.sum)e=mid-1;
        else s=mid+1;
    }
    return reti;
}
int upper_bound(SUM sum)
{
    int s=0,e=(1<<n)-2;
    int reti=-1;
    while (s<=e){
        int mid = (s+e)/2;
        if (sums2[mid].sum == sum.sum)reti=mid;
        if (sums2[mid].sum<=sum.sum)s=mid+1;
        else e=mid-1;
    }
    return reti;
}


int main()
{
    FILE *in=fopen("sums.in","r");
    freopen("sums.out","w",stdout);
    int c,c2;
    int tests;
    fscanf(in,"%d",&tests);
    for (int test=1;test<=tests;test++)
    {
        printf("Case #%d:\n",test);
        fscanf(in,"%d",&n);
        for (c=0;c<n;c++)
            fscanf(in,"%d",&arr[c]);
        int nn=(1<<n)-1;
        for (c=1;c<(1<<n);c++)
        {
            int sum=0;
            for (c2=0;c2<n;c2++)
                if (c&(1<<c2))
                    sum+=arr[c2];
            sums1[c-1].sum=sums2[c-1].sum=sum;
            sums1[c-1].mask=sums2[c-1].mask=c;
        }
        sort(sums2,sums2+nn);
        for (c=0;c<nn;c++)
        {
            int s = lower_bound(sums1[c]);
            int e = upper_bound(sums1[c]);
            if (s==-1)continue;
            for (c2=s;c2<=e;c2++)
                if (!(sums1[c].mask & sums2[c2].mask)){
                    print(sums1[c].mask,sums2[c2].mask);
                    goto barra;
                }
        }    
        printf("Impossible\n");
        barra:continue;
    }
    
//    system("pause");
    return 0;
}
