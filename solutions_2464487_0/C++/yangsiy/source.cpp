#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream cin("/Users/yangsiyu/Documents/HelloWorld/HelloWorld/in.txt");
ofstream cout("/Users/yangsiyu/Documents/HelloWorld/HelloWorld/out.txt");

const double pi=3.141592653;

long long cal(long long r)
{
    return r*r;
}

int main()
{
    int tt,count=0;
    long long ans,t,r;
    cin>>tt;
    while (tt--)
    {
        count++;
        cin>>r>>t;
        ans=0;
        while (cal(r+1)-cal(r)<=t)
        {
            t-=cal(r+1)-cal(r);
            ans++;
            r+=2;
        }
        cout<<"Case #"<<count<<": "<<ans<<endl;
    }
    return 0;
}