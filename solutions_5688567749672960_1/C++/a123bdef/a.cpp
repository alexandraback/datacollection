#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    FILE *fr= fopen("a.in","r");
    FILE *fw= fopen("a.out","w");
    int f[16];
    f[1]=1;f[2]=10;
    int a=9,b=9;
    for (int i=3;i<=15;i++) 
    {
        f[i]=f[i-1]+a+b+1;
        int c=a*10+9;a=b;b=c;
    }
    int cas0; fscanf(fr,"%d",&cas0);
    for (int cas=1;cas<=cas0;cas++)
    {
        long long n;fscanf(fr,"%lld",&n);
        if (n<=10) {fprintf(fw,"Case #%d: %lld\n",cas,n); continue;}
        n=n-1;
        long long n0=n;
        int t=0; while (n0>0) {n0/=10; t++;}
        int t0=(t+1)/2;
        int ans1=0,p=1;
        for (int i=0;i<t0;i++)
        {
            ans1=ans1+(n%10)*p;
            n=n/10;
            p=p*10;
        }
        int ans2=0;
        while (n>0)
        {
            ans2=ans2*10+n%10;
            n=n/10;
        }
        int ans;
        if (ans2!=1) ans=ans1+ans2+f[t]+1; else ans=ans1+ans2+f[t];
        fprintf(fw,"Case #%d: %d\n",cas,ans);
    }
    return 0;
}
