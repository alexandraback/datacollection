#include <iostream>
#include <string>
using namespace std;
unsigned long T,N,J;
void solve(unsigned long,unsigned long,unsigned long);
string toBin(unsigned long,unsigned long);
unsigned long toBasey(string,unsigned long);
int main(){
    cin >> T;
    for(unsigned long i=1;i<=T;++i){
        cin>>N>>J;
        solve(i,N,J);
    }
    return 0;
}
void solve(unsigned long i,unsigned long n,unsigned long j){
    cout<<"Case #"<<i<<':'<<endl;
    unsigned long x = (n-4)/2;
    string one="1";
    for(unsigned long a=0;a<j;++a){
        string s=toBin(a,x);
        s = one + s + one;
        cout<<s+s<<' ';
        for(unsigned long b=2;b<=10;++b)
            cout<<toBasey(s,b)<<' ';
        cout<<endl;
    }
}
string toBin(unsigned long a,unsigned long x){
    string res="";
    for(unsigned long i=0;i<x;i++){
        if(a%2==0) res.push_back('0');
        else res.push_back('1');
        a/=2;
    }
    return res;
}
unsigned long toBasey(string s,unsigned long y){
    unsigned long res=0;
    unsigned long b = 1;
    for(int i=s.size()-1;i>=0;--i){
        if(s[i]=='1')
            res += b;
        b*=y;
    }
    return res;
}
