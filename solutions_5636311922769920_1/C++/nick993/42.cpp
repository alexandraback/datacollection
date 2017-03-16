#include <iostream>
#include <cstring>
#include <cstdio>

#define ll unsigned long long

using namespace std;

ll upb(ll a,ll b) {
    return (a/b) + (a%b==0?0:1);
}

ll lob(ll a,ll b) {
    return a/b;
}

ll powVal(ll a,ll b) {
    if(b==0L)    return 1L;
    ll res=powVal(a,b/2);
    if(b%2)
        return res*res*a;
    return res*res;
}

ll func1(ll st,ll en,ll base) {
   // cout<<"Entered Function "<<endl;
    //cout<<st<<" : "<<en<<" : "<<base<<endl;
    ll cnt=0;
    ll res=0;
    for(ll i=en;i>=st;) {
       // cout<<"Loop : "<<i<<endl;
        res+=(i*powVal(base,cnt++));
        if(i>0)
            i--;
        else{
            break;
        }
    }
    return res+1;
}


int main() {
    freopen("f4.txt","r",stdin);
    freopen("o42.txt","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        cout<<"Case #"<<t<<": ";
        ll k,c,s;
        cin>>k>>c>>s;
        ll s_req=upb(k,c);
        ll r=lob(k,c);
        if(s<s_req){
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        if(s_req==1) {
            cout<<func1(0,k-1,k)<<endl;
        }
        else {
            for(ll i=0;i<r;i++) {
                cout<<func1(i*c,(i+1)*c-1,k)<<' ';
            }
            if(r!=s_req){
                cout<<func1(r*c,k-1,k)<<endl;
            }
            else{
                cout<<endl;
            }
        }


    }


}
