#include <iostream>
#include <stdio.h>
using namespace std;
int n,T;
int a[222];
int sum=0;
const double EPS=1e-8;
int tmp[222],cnt;
bool test(int no,double x)
{
    double plus=sum*(1-x);
    double cur=a[no]+sum*x;
    double dec=0;
    int decn=0;
    for(int i=0;i<n;i++) if(i!=no && a[i]<cur) decn++,dec+=cur-a[i];
    return dec>plus;
}
int main()
{
  //  freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    int casno=1;
    cin>>T;
    while(T--)
    {
        scanf("%d",&n);
        sum=0;
        for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
        printf("Case #%d: ",casno++);
        double l,r;
        for(int i=0;i<n;i++)
        {
            double m;
            l=0,r=1;
            while(r-l>EPS)
            {
                m=(l+r)/2.0;
                if(test(i,m)) r=m;
                else l=m;
            }
            if(i) putchar(' ');
            printf("%lf",m*100.0);
        }
        printf("\n");
    }
}
