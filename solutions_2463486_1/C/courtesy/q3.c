#include<stdio.h>
#include<math.h>
typedef long long ll;
ll p[1000],ind;
int palin(ll n)
{
    int a[20],i,j,k;
    for(i=0;n>0;i++,n/=10)a[i]=n%10;
    for(i--,j=0;i>j;i--,j++)
    {
        if(a[i]!=a[j])return 0;
    }
    return 1;
}
int main()
{
    freopen("C:\\Users\\vivek\\Desktop\\in.txt","r",stdin);
    freopen("C:\\Users\\vivek\\Desktop\\out.txt","w",stdout);

    int k,t,cs;
    ll a,b,i,j,l;
    for(i=1;i<=10000000;i++)
    {
        if(palin(i)&&palin(i*i))p[ind++]=i*i;
    }
    scanf("%d",&cs);
    for(t=1;t<=cs;t++)
    {
        scanf("%lld %lld",&a,&b);
        for(i=0;(i<ind)&&(p[i]<a);i++);
        for(j=ind-1;(j>=0)&&(p[j]>b);j--);
        k=j-i+1;
        if(k<0)k=0;
        printf("Case #%d: %d\n",t,k);
    }
    return 0;
}
