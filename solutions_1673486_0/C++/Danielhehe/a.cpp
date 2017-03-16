#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
    freopen("result.out","w",stdout);
    freopen("a.in","r",stdin);
    int T,A,B;
    double p[100000],f[100000];
    cin>>T;
    for (int N=1; N<=T; N++)
    {
        cin>>A>>B;
        f[0]=1;
        for (int i=1; i<=A; i++)
        {
            cin>>p[i];
            f[i]=f[i-1]*p[i];
        }
        double min=f[A]*(B-A+1)+(1-f[A])*(B-A+B+2);
        if (min>B+2) min=B+2;
        for (int k=1; k<=A; k++)
        {
            double t=f[A-k]*(k*2+B-A+1)+(1-f[A-k])*(k*2+B-A+1+B+1);
            if (t<min) min=t;
        }
        cout<<"Case #"<<N<<": ";
        printf("%.6f\n",min);
    }
    return 0;
}
