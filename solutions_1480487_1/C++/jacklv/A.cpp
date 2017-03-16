#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=211;
struct T1
{
    double po,ans;
    int num;
};
bool cmp(T1 a,T1 b)
{
    return a.po<b.po;
}
bool cmp2(T1 a, T1 b)
{
    return a.num<b.num;
}
double sum,sum1;
T1 b[maxn];
int n,nn;
double max(double a,double b)
{
    if (a>b) return a ; else
    return b;
}
void init()
{
    cin>>n;  nn=n;
    sum=0; sum1=0;
    for (int i=1; i<=n; i++)
    {
        scanf("%lf",&b[i].po);
        sum+=b[i].po;
        b[i].num=i;
        b[i].ans=0;
    }
    sum1=sum;
    sort(b+1,b+1+n,cmp);
    for (int i=n; i>=1; i--)
    if (sum+sum1-n*b[i].po<0.000000001)
    {
        sum1-=b[i].po;
        n--;
    }
}
int main()
{
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int T; cin>>T;
    for (int tt=1; tt<=T; tt++)
    {
        init();
        if (sum1>0.000000001)
        for (int i=1; i<=n; i++)
        b[i].ans=(sum+sum1-n*b[i].po)/(n*sum),b[i].ans=b[i].ans*100;
        else
        {
            for (int i=1; i<=n; i++)
            b[i].ans=100.0/n;
        }
        printf("Case #%d:",tt);
        sort(b+1,b+1+nn,cmp2);
        for (int i=1; i<=nn; i++)
        printf(" %lf",b[i].ans);
        printf("\n");
    }
}

