#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long i64;
double c(int n,int m)
{
    double res=1.0;
    for(int i=0;i<m;++i)
        res=res*(n-i+0.0)/(i+1.0);
    return res;
}
double cal(int n,int m,int k)
{
    if(k>m) return 0.0;
    if(k==n)return 0.0;
    if(m>=k+n-1)    return 1.0;
    if(m==2*n-2)  return 1.0;
    double res=0.0;
    for(int i=0;i<k&&i<=m;++i)if(m-i<n-1)
        res+=c(m,i);
    res*=pow(0.5,m);
    for(int i=n-1;i<=m&&m-(n-1)<k;++i)
        res+=c(i-1,n-2)*pow(0.5,i);
    return 1.0-res;
}
int a[3]={1,5,9};
double ask(int n,int x,int y)
{
    int d=(abs(x)+abs(y))/2;
    if(d>3) return 0.0;
    for(int i=0;i<d;++i)    n-=a[i];
    if(n<=0)    return 0.0;
    if(d<2&&n>=a[d])    return 1.0;
    return cal(2*d+1,n,abs(y)+1);
}
int main()
{
   // //freopen("B-small-attempt3.in","r",stdin);
   // freopen("B-small-attempt3.out","w",stdout);
    int tes,n,x,y;
    cin>>tes;
    for(int h=1;h<=tes;++h)
    {
        cin>>n>>x>>y;
    //  if(h==21)
     // cout<<n<<' '<<x<<' '<<y<<endl;
        printf("Case #%d: %.10lf\n",h,ask(n,x,y));
        //int hh=1;
    }
    return 0;
}
