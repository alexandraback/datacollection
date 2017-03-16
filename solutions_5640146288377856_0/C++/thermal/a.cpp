#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,r,c,w;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        cin>>r>>c>>w;
        int ans = (r-1)*(c/w);
        ans+=c/w-1;
        if(c%w==0){
            ans += w;
        }else{
            ans += w+1;
        }
        cout<<"Case #"<<cs<<": "<<ans<<endl;
    }
}
