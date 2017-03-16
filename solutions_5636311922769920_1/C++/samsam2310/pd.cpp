#include <bits/stdc++.h>
#define F(n) Fi(i,n)
#define Fi(i,n) Fl(i,0,n)
#define Fl(i,l,n) for(int i=l;i<n;i++)
using namespace std;
long long powLL(long long x, int p){
    long long tmp = 1;
    while(p--)tmp *= x;
    return tmp;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,k,c,s;
    cin>>t;
    Fl(_,1,t+1){
        cout<<"Case #"<<_<<":";
        cin>>k>>c>>s;
        if(s*c<k)cout<<" IMPOSSIBLE"<<endl;
        else if(k==1)cout<<" 1"<<endl;
        else{
            long long tmp = 1, ans = 0, pK = powLL(k,c);
            F(k){
                ans += tmp*i;
                tmp *= k;
                if(tmp >= pK){
                    cout<<' '<<ans+1;
                    ans = 0;
                    tmp = 1;
                }
            }
            if(tmp>1)cout<<' '<<ans+1;
            cout<<endl;
        }
    }
}