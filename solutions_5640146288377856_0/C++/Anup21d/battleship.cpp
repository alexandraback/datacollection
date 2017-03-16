
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;


typedef long long ll;


int main(){
    freopen("sin.in","r",stdin);
    freopen("sout.out","w",stdout);
    int t,r,c,w,ans,i,k;
    cin>>t;
    for(k=1;k<=t;k++){
        ans=0;
        cin>>r>>c>>w;
        for(i=w;i<c-w+1;i+=w)
            ans++;
        i-=w;
        if(c-i>w)
            w++;
        cout<<"Case #"<<k<<": "<<((r-1)*(ans+1)+ans+w)<<"\n";
    }

    return 0;
}
