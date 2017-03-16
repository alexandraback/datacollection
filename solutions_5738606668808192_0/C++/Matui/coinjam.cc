#include <iostream>
#include <string>
using namespace std;
int T,N,J;
void solve(int,int,int);
string toBin(int,int);
int toBasey(string,int);
int main(){
    cin >> T;
    for(int i=1;i<=T;++i){
        cin>>N>>J;
        solve(i,N,J);
    }
    return 0;
}
void solve(int i,int n,int j){
    cout<<"Case #"<<i<<':'<<endl;
    int x = (n-4)/2;
    string one="1";
    for(int a=0;a<j;++a){
        string s=toBin(a,x);
        s = one + s + one;
        cout<<s+s<<' ';
        for(int b=2;b<=10;++b)
            cout<<toBasey(s,b)<<' ';
        cout<<endl;
    }
}
string toBin(int a,int x){
    string res="";
    for(int i=0;i<x;i++){
        if(a%2==0) res.push_back('0');
        else res.push_back('1');
        a/=2;
    }
    return res;
}
int toBasey(string s,int y){
    int res=0;
    int b = 1;
    for(int i=s.size()-1;i>=0;--i){
        if(s[i]=='1')
            res += b;
        b*=y;
    }
    return res;
}
