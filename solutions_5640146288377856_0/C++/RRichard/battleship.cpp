#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

fstream a;

int main()
{
    a.open("wyjscie.txt", ios::out);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int r, w, c;
        cin>>r>>c>>w;
        int b=0;
        if(c%w!=0) b=1;
        a<<"Case #"<<i<<": "<<r*(c/w)+w-1+b<<"\n";
    }
}
