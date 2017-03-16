#include <iostream>
#include <algorithm>
using namespace std;
int res;
int n,v[11],R,E;
void func(int e, int i, int g)
{
    if (i==n) {
        res=max(res,g);
        return;
    }
    for(int k=0;k<=e;++k)
        func(min(E,e-k+R), i+1, g+v[i]*k);
}
int main()
{
    int T; cin>>T;
    for(int t=1;t<=T;++t) {
        cin>>E>>R>>n;
        for(int i=0;i<n;++i) cin>>v[i];
        res=0;
        for(int i=0;i<=E;++i) func(i,0,0);
        cout<<"Case #"<<t<<": "<<res<<endl;
    }
    return 0;
}
