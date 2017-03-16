#include<iostream>
#include<stdio.h>
using namespace std;
int n;
int p[222];
double an[222];
int all;
bool ccc(int x,double m)
{
    double ff=p[x]+double(all)*m/100.0;
    double t=0;
    for(int i=1;i<=n;i++)
    {
        if(i==x)continue;
        if(double(p[i])<=ff)
        {
            t=t+(ff-p[i]);
        }
    }
    if(t<double(all)*(100.0-m)/100.0)return false;
    return true;
}
double bbb(int x)
{
    double b=0;
    double d=100.0;
    double m;
    double G=0.000001;
    while(d-b>=G)
    {
        m=(b+d)/2.0;
        bool f=ccc(x,m);
        if(f)
        {
            d=m;
        }
        else
        {
            b=m;
        }
    }
    return d;
}
int main()
{
int t;
cin>>t;
for(int i=1;i<=t;i++)
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    all=0;
    for(int i=1;i<=n;i++)all=all+p[i];
    for(int i=1;i<=n;i++)
    {
        an[i]=bbb(i);
    }
    printf("Case #%d:",i);
    for(int i=1;i<=n;i++)printf(" %.6lf",an[i]);
    printf("\n");
}
return 0;
}
