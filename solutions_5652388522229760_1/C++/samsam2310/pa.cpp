#include <bits/stdc++.h>
#define F(n) Fi(i,n)
#define Fi(i,n) Fl(i,0,n)
#define Fl(i,l,n) for(int i=l;i<n;i++)
using namespace std;
bool wed[10];
bool check(int x){
    while(x)wed[x%10] = true, x/=10;
    F(10)if(!wed[i])return false;
    return true;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,a,b;
    cin>>t;
    Fl(_,1,t+1){
        cin>>a;
        b = a;
        memset(wed,0,sizeof(wed));
        if(a==0)cout<<"Case #"<<_<<": INSOMNIA"<<endl;
        else{
            while(!check(b))b+=a;
            cout<<"Case #"<<_<<": "<<b<<endl;
        }
    }
}