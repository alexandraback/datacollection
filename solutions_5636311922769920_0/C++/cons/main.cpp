#include <cstdio>
#include <iostream>
#define FOR(i,x,y) for(int i=x;i<=y;++i)
using namespace std;
int t,k,c,s;
int main()
{
    cin>>t;
    FOR(i,1,t)
    {
        cout<<"Case #"<<i<<":";
        cin>>k>>c>>s;
        FOR(j,1,s) cout<<' '<<j;
        cout<<endl;
    }
    return 0;
}
