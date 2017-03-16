#include <bits/stdc++.h>
#define F(n) Fi(i,n)
#define Fi(i,n) Fl(i,0,n)
#define Fl(i,l,n) for(int i=l;i<n;i++)
using namespace std;
string DFS(string s){
    if(s.size()==1)return s;
    int mxi = 0;
    F(s.size())if(s[i]>=s[mxi])mxi = i;
    string res;
    res += s[mxi];
    if(mxi)res += DFS(s.substr(0,mxi));
    if(mxi < s.size()-1)res += s.substr(mxi+1);
    return res;
}
main(){
    ios_base::sync_with_stdio(false);
    int t;
    string s;
    cin>>t;
    Fl(_,1,t+1){
        cin>>s;
        cout<<"Case #"<<_<<": "<<DFS(s)<<endl;
    }
}