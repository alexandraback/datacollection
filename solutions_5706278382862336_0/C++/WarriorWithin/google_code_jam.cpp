#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <bitset>
#define mod 1000000009
using namespace std;

long long int gcd(long long int a, long long int b)
{
    //cout<<"gcd: "<<a<<" "<<b<<endl;
    if(a<b)
    {
        long long int temp = a;
        a = b;
        b = temp;
    }
    //cout<<a<<" "<<b<<endl;
    while(a%b!=0)
    {
        long long int temp = a;
        a = b;
        b = temp%b;
        //cout<<a<<" "<<b<<endl;
    }
    return b;
}

bool check(long long int n)
{
    long long int start = 1;
    int ctr = 0;
    while(1)
    {
        //cout<<n<<" "<<start<<" "<<ctr<<endl;
        if(n<start)
        {
            ctr = 1;
            break;
        }
        if(n==start)
        {
            ctr = 0;
            break;
        }
        start = start*2;
    }
    if(ctr==0)
        return true;
    else
        return false;
}

int main()
{
    long long int t, i, p ,q;
    cin>>t;
    //cout<<t<<endl;
    for(i=1; i<=t; i++)
    {
        string word;
        cin>>word;
        //cout<<i<<" "<<word<<endl;
        p = 0;
        q = 0;
        long long int pos = 0;
        while(word[pos]!='/')
        {
            p = p*10 + word[pos]-'0';
            pos++;
        }

        pos++;
        while(pos<word.length())
        {
            q = q*10 + word[pos]-'0';
            pos++;
        }

        //cout<<word<<" "<<p<<" "<<q<<endl;
        long long int g = gcd(p,q);
        //cout<<g<<endl;
        //cout<<p<<" "<<q<<" "<<g<<endl;
        p = p/g;
        q = q/g;
        //cout<<p<<" "<<q<<" "<<g<<endl;
        bool c = check(q);
        if(c)
        {
            double gen = 1;
            double given = ((double)p/q);
            long long int ans = 0;
            while(given<gen)
            {
                ans++;
                gen = gen/2;
            }
            if(ans==0)
                ans = 1;

            cout<<"Case #"<<i<<": "<<ans<<endl;
        }
        else
            cout<<"Case #"<<i<<": impossible\n";
    }

    return 0;
}
