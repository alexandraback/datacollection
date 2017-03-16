#include <bits/stdc++.h>
#define F(n) Fi(i,n)
#define Fi(i,n) Fl(i,0,n)
#define Fl(i,l,n) for(int i=l;i<n;i++)
using namespace std;
// const int N = 101;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int n,a,b;
    cin>>n;
    Fl(_,1,n+1){
        cin>>s;
        a = s[0] =='-';
        b = s[0] =='+';
        // cout<<"DD: "<<a<<' '<<b<<endl;
        Fl(i,1,s.size()){
            int ta = a, tb = b;
            a = min(ta + (s[i]=='-'?2:0), tb + 1);
            b = min(ta + 1, tb + (s[i]=='+'?2:0));
            // cout<<"DD: "<<a<<' '<<b<<endl;
        }
        cout<<"Case #"<<_<<": "<<min(a,b+1)<<endl;
    }
}