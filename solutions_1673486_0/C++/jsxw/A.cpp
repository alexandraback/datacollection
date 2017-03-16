#include<iostream>
#include<stdio.h>
using namespace std;
int A,B,l=0;
double p[100010];
void mainwork()
{
    l++;
    double s=1;
    int i;
    cin>>A>>B;
    for (i=1;i<=A;i++)
    {
        scanf("%lf",&p[i]);
        s*=p[i];
    }
 //   cout<<s<<endl;
    double k1=s*(B-A+1)+(1-s)*(B-A+1+B+1);
 //   cout<<k1<<endl;
    double k2=1+B+1;
    double min;
    if (k1<k2)  min=k1;
    else min=k2;
    s=1;
    for (i=1;i<=A;i++)
    {
        s*=p[i];
        double t=(A-i)+s*(B-i+1)+(1-s)*(B-i+B+2);
        if (t<min) min=t;
    }
    printf("Case #%d: %.6lf\n",l,min);
}
int main()
{
    freopen("out.txt","w",stdout);
    freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while (t--)
    mainwork();
    return 0;
}
