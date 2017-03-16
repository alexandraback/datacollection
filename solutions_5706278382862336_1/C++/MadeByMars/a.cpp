#include<cstdio>
#include<cstring>
typedef long long int64;
long long a,b,k;
int t,T;
int64 gcd(int64 a,int64 b){return b?gcd(b,a%b):a;}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);
    for (t=1;t<=T;t++)
    {
        scanf("%I64d/%I64d",&a,&b);
        k=gcd(a,b);
        a/=k;b/=k;
        if ((b&(-b))!=b)printf("Case #%d: impossible\n",t);
        else
        {
        for (k=0;b>a;b>>=1,k++);
        printf("Case #%d: %I64d\n",t,k);
        }
    }
    return 0;
}
