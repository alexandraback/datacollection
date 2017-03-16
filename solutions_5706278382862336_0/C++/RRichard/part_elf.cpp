#include<iostream>
#include<fstream>
using namespace std;

pair<long long, long long> eukl(long long a, long long b)
{
    long long x=a, y=b;
    long long c;
    while(x!=0)
    {
        c=y%x;
        y=x;
        x=c;
    }
    return make_pair(a/y, b/y);
}

bool potega(long long b)
{
    long long d=1;
    while(d!=b)
    {
        if(d>b) return false;
        d*=2;
    }
    return true;
}

int main()
{
    fstream wyjscie;
    wyjscie.open("wyjscie.txt", ios::out);
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        wyjscie<<"Case #"<<i+1<<": ";
        long long a, b, ilosc=0;
        char c;
        cin>>a>>c>>b;
        pair<long long, long long> w=eukl(a, b);
        if(!potega(w.second))
        {
            wyjscie<<"impossible\n";
            continue;
        }
        while(w.first<w.second)
        {
            w.second/=2;
            ilosc++;
        }
        wyjscie<<ilosc<<"\n";
    }
}
