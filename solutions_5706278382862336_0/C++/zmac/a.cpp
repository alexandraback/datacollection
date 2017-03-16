#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
using namespace std;

long long convert(string a,int num)
{

    bool flag=0;
    long long tmp1 = 0, tmp2 = 0;
    for (int i=0;i<a.length();i++)
    {
        if (a[i]=='/')
        {
            flag=1;
            continue;
        }
        int c=a[i]-'0';
        if (flag==0)
            tmp1=tmp1*10+c;
        else tmp2=tmp2*10+c;
    }
    if (num==1)
        return tmp1;
    return tmp2;
}

long long gcd(long long a, long long b)
{
    if (b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.out","w",stdout);
    int n;
    long long sum=1099511627776;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cout<<"Case #"<<i<<": ";
        long long a,b,r,tmp,gcdd;
        string aa;
        cin>>aa;
        a=convert(aa,1);
        b=convert(aa,2);
        gcdd=gcd(a,b);
        a/=gcdd;
        b/=gcdd;
        r = sum % b;
        if (r!=0)
        {
            cout<<"impossible"<<endl;
            continue;
        }
        tmp=sum;
        r = sum / b;
        a = a * r;
        int cnt=0;
        while (a<tmp)
        {
            ++cnt;
            tmp/=2;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
