#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if (a<b)
    {
        long long temp=a;
        a=b;
        b=temp;
    }
    long long c=a%b;
    if (c==0) return b;
    else return gcd(b,c);
}

long long two(long long a)
{
    long long b=1,t=0;
    while (1)
    {
        if (b>a || t>40) return -1;
        if (b==a) return t;
        b*=2;
        t++;
    }
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("op.txt", "w", stdout);

    int T,t;
    int i,j,k;



    cin>>t;
    T=t;
    while(t--)
    {
        string s;
        long long a=0,b=0;

        cin>>s;

        bool sin=0;
        for (i=0;i<s.size();i++)
        {
            if (s[i]!='/')
            {
                if (sin==0)
                {
                    a*=10;
                    a+=(long long)(s[i]-'0');
                }
                else
                {
                    b*=10;
                    b+=(long long)(s[i]-'0');
                }
            }
            else sin=1;
        }

        long long c=gcd(a,b);
        a/=c;
        b/=c;

        c=two(b);
        if (c==-1) {cout<<"Case #"<<T-t<<": impossible"<<endl;continue;}

        long long cnt=0,d=1;
        while (d<=a) {d*=2;cnt++;}
        cnt--;

        //cout<<a<<" "<<two(a)<<endl;

        cout<<"Case #"<<T-t<<": "<<c-cnt<<endl;
    }
    return 0;
}
