#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream cin("/Users/yangsiyu/Documents/HelloWorld/HelloWorld/in.txt");
ofstream cout("/Users/yangsiyu/Documents/HelloWorld/HelloWorld/out.txt");

long long r,t;

long long cal(long long n)
{
    return (2*n*n+2*n*r-n);
}

long long find(long long x,long long y)
{
    long long mid;
    while (x<y)
    {
        mid=(x+y)/2;
        if (cal(mid)==t) return mid;
        if (cal(mid)<t)
        {
            if (cal(mid+1)>t) return mid;
            x=mid+1;
        }
        else y=mid-1;
    }
    return min(x,y);
}

int main()
{
    int tt,count=0;
    long long ans;
    cin>>tt;
    while (tt--)
    {
        count++;
        cin>>r>>t;
        ans=1;
        while (cal(ans)<=t)
        {
            ans*=2;
        }
        ans=find(ans/2,ans);
        cout<<"Case #"<<count<<": "<<ans<<endl;
    }
    return 0;
}