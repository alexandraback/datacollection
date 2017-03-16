#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

long long i,j,k,l,m,n, cur , r,c,w,test,s,t, mx, a[1005],d, ii,x,ans;
string str;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w", stdout);
    cin>>t;

    while(t--){
        cin>>r>>c>>w;
        test++;
        ans = 0;
        while (c>=2*w){
            ans++;
            c-=w;
        }
        if (c==w) {ans+=w;} else {ans+=w+1;}
        cout<<"Case #"<<test<<": "<<ans<<"\n";
    } 
    return 0;
}
