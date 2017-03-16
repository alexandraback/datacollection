#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll gcd (ll a,ll b){
    if (a==0) return b;
    return gcd (b%a,a);
}

int main(){
    freopen ("out.out","w",stdout);
    int tcs;
    cin>>tcs;
    for (int tc=1;tc<=tcs;tc++){
        cout <<"Case #"<<tc<<": ";
        string s;
        cin>>s;
        ll a=0;
        ll b=0;
        int v=0;
        for (int i=0;i<s.size();i++){
            if (s[i]=='/'){
                v=1;
            }
            else{
                if (v==0){
                    a*=10;
                    a+=(s[i]-'0');
                }
                if (v==1){
                    b*=10;
                    b+=(s[i]-'0');
                }
            }
        }
        ll gcdd;
        while ((gcdd=gcd(a,b))>1){
            a/=gcdd;
            b/=gcdd;
        }
        ll t=1;
        int f=0;
        for (int i=0;i<40;i++){
            t*=2;
        }
        if (b<=t&&t%b==0){
            a*=t/b;
            b*=t/b;
            for (ll i=40;i>=0;i--){
                if (((ll)1<<i)&a){
                    cout <<(40-i)<<endl;
                    break;
                }
            }
        }
        else{
            cout <<"impossible"<<endl;
        }
    }
}
