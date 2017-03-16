#include<cstdio>
#include<map>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
long long br,k;
void rec(int n,int y,int l,int r,int cap)
{
    if(n==0)
    {
        if(l>=y)br++;
        k++;
        return;
    }
    if(l<cap)rec(n-1,y,l+1,r,cap);
    if(r<cap)rec(n-1,y,l,r+1,cap);
}
void solve()
{
    int n,x,y,m,p=1,c=0,po=0;
    cin>>n>>x>>y;
    m=(abs(x)+abs(y))/2;
    while(m>0)
    {
        m--;
        c+=p;
        p+=4;
        po+=2;
    }
    if(n<=c)
    {
        cout<<"0.0\n";
        return;
    }
    if(n>=c+p)
    {
        cout<<"1.0\n";
        return;
    }
    if(x==0)
    {
        cout<<"0.0\n";
        return;
    }
    br=0;
    k=0;
    rec(n-c,y+1,0,0,po);
    double d=double(double(br)/double(k));
    printf("%.6lf\n",d);
}
int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
}
