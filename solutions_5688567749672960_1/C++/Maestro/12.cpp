#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[50],cur,x,q,w,sz,se,we;
const int inf=-1337;
int sw(int x){
    sz=0;
    for(;x;){
        a[++sz]=x%10;
        x/=10;
    }
    we=0;
    if(a[1]==0)return inf;
    for(int i=1;i<=sz;++i)
        we=we*10+a[i];
    return we;
}
int res;
bool rdy(int x){
    sz=0;
    for(;x;){
        a[++sz]=x%10;
        x/=10;
    }
    int l=(sz+1)/2;
    for(int i=2;i<=l;++i)
        if(a[i]!=0)return 0;
    if(a[1]!=1)return 0;
    return 1;
}
void solve(){
    cur=x;
    res=1;
    for(;cur!=1;){
        ++res;
        if(rdy(cur)&&cur!=sw(cur))cur=sw(cur);
        else --cur;
    }
}
main(){
   freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int t;
    cin>>t;
    for(int tt=1;tt<=t;++tt){
        cin>>x;
        solve();
        cout<<"Case #"<<tt<<": "<<res<<endl;
    }
}
