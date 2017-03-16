#include<iostream>
using namespace std;
int main()
{
    freopen("a1.in","r",stdin);
    freopen("a1.out","w",stdout);
    long long r,t;
    int T;
    cin>>T;
    for (int TT=1;TT<=T;++TT)
    {
        cin>>r>>t;
        long long b=1,e=t;
        while (b+1<e)
        {
          long long mid=(b+e)>>1;
          if ((r*2+mid*2-1)<=t/mid) b=mid;else e=mid;
        }
        cout<<"Case #"<<TT<<": "<<b<<endl;
    }
} 
