#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)
#define all(v) v.begin(),v.end()

typedef long long int tint;

long double calc(tint r,long double k)
{
    return 2*k*k+(2*r-1)*k;
}

tint calc(tint r,tint k)
{
    return 2*k*k+(2*r-1)*k;
}

int main()
{
    int T;
    cin>>T;
    forn(t,T)
    {
        tint r,p;
        cin>>r>>p;
        long double a=1,b=1e20,c;
        while(b-a>1e-5)
        {
            c=(a+b)/2;
            //cout<<c<<" "<<calc(r,c)<<endl;
            if(calc(r,c)<p+1e-5)a=c;else b=c;
        }
        tint res=a-1e-10;
        if(calc(r,res+1)<=p)res++;
        cout<<"Case #"<<t+1<<": "<<res<<endl;
    }
}
