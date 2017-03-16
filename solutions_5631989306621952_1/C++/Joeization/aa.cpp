#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,a,b;
void init(){
}
void solve(){
}
void build(){
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie();cout.tie();
    cin>>t;
    string s;
    for(int ti=1;ti<=t;ti++){
        cin>>s;
        string as="";
        as+=s[0];
        for(int i=1;i<s.length();i++){
            if(s[i]>=as[0])as=s[i]+as;
            else as+=s[i];
        }
        cout<<"Case #"<<ti<<": ";
        cout<<as<<endl;
    }
}