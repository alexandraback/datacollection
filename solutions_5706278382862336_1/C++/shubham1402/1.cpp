//coded by shubham1402

#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a ,long long b)
{
    if(a == 0)
    return b;
    if(b == 0)
    return a;
    if(a == 1)
    return 1;
    if(b == 1)
    return 1;
    return gcd(b,a%b);
}
long long power(long long a, long long b)
{
    if(b == 0)
    return 1;
    if(b == 1)
    return a;
    if(b%2 == 0)
    {
        long long temp = pow(a,b/2);
        return temp*temp;
    }
    else
    {
        long long temp = pow(a,b/2);
        return temp*temp*a;
    }
}


int main()
{
    ifstream cin("in1.txt");
    ofstream cout("out1.txt");
    long long t;
    cin>>t;
    long long k = 0;
    while(t--)
    {
        k++;
        long long p,q;
        char z;
        cin>>p>>z>>q;
        long long g = gcd(p,q);
        p = p/g;
        q = q/g;
        long long val = log2(q);
        long long Flag = 0;
        if(pow(2,val) != q)
        {
            Flag = 1;
        }
        long long ans = 0;
        ans = val - (long long)log2(p);
        if(p == 0)
        Flag = 1;
        //cout<<"vAL: "<<val<<" p"<<log2(p)<<endl;
        if(Flag)
        {
            cout<<"Case #"<<k<<": "<<"impossible"<<endl;
        }
        else
        {
             cout<<"Case #"<<k<<": "<<ans<<endl;
        }
    }
    return 0;
}
