#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#define FOR(i,x,y) for(int i=x;i<=y;++i)
using namespace std;
int t,n,temp,a[2510];
int main()
{
    cin>>t;
    FOR(i,1,t)
    {
        cout<<"Case #"<<i<<":";
        memset(a,0,sizeof(a));
        cin>>n;
        FOR(j,1,2*n-1)
        {
            FOR(k,1,n)
            {
                cin>>temp;
                a[temp]=(a[temp]+1)%2;
            }
        }
        FOR(j,1,2500) if(a[j]) cout<<" "<<j;
        cout<<endl;
    }
    return 0;
}
