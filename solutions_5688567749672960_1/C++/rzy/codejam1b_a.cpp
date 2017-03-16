#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
long long e[15],levelup[15],a[15],b[15];
int i,o,t,j;
long long n,ans,ka,kb;
bool bsmalla()
{
    for (int i=j;i>=0;i--)
    {
        if (b[i]<a[i])return 1;
        if (b[i]>a[i])return 0;
    }
    return 0;
}
int work()
{
    ans=0;
    if (n<=10){ans=n;return 0;}
    for (i=1;i<=14;i++)
        if (n>=e[i])j=i;
    for (i=1;i<=j;i++)ans+=levelup[i];
    if (n==e[j])return 0;
    for (i=0;i<=j;i++)a[i]=n/e[i]%10;
    int k=0;
    for (i=0;i<=(j-1)/2;i++)k+=a[i];
    if (k)
    {
        a[0]=1;
        for (i=1;i<=(j-1)/2;i++)a[i]=0;
    }
    else
    {
        a[(j-1)/2+1]--;
        k=(j-1)/2+1;
        while (a[k]<0)
        {
            a[k]+=10;
            a[++k]-=1;
        }
        a[0]=1;
        for (i=1;i<=(j-1)/2;i++)a[i]=0;
    }
    for (i=0;i<=j;i++)b[i]=a[j-i];
    if (bsmalla())
    {
        ka=0;
        kb=0;
        for (i=0;i<=j;i++)
        {
            ka+=e[i]*a[i];
            kb+=e[i]*b[i];
        }
        ans+=kb-e[j]+n-ka+1;
    }
    else ans+=n-e[j];
}
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    e[0]=1;
    for (i=1;i<=14;i++)e[i]=e[i-1]*10;
    levelup[1]=10;
    levelup[2]=19;
    levelup[3]=109;
    levelup[4]=199;
    levelup[5]=1099;
    levelup[6]=1999;
    levelup[7]=10999;
    levelup[8]=19999;
    levelup[9]=109999;
    levelup[10]=199999;
    levelup[11]=1099999;
    levelup[12]=1999999;
    levelup[13]=10999999;
    levelup[14]=19999999;
    cin>>t;
    for (o=1;o<=t;o++)
    {
        cin>>n;
        work();
        cout<<"Case #"<<o<<": "<<ans<<endl;
    }
}
