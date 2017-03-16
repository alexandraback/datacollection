#include<vector>
#include<iostream>
using namespace std;
#define pb push_back
vector<long long>w;
int f(int c){
long long a,b,res=0;
cin>>a>>b;
for(int i=0;i<w.size();i++){
res+=(w[i]<=b&&w[i]>=a);
}        
cout<<"Case #"<<c<<": "<<res<<"\n";   
}
main(){
w.pb(1);
w.pb(2);
w.pb(3);
w.pb(11);
w.pb(22);
w.pb(101);
w.pb(111);
w.pb(121);
w.pb(202);
w.pb(212);
w.pb(1001);
w.pb(1111);
w.pb(2002);
w.pb(10001);
w.pb(10101);
w.pb(10201);
w.pb(11011);
w.pb(11111);
w.pb(11211);
w.pb(20002);
w.pb(20102);
w.pb(100001);
w.pb(101101);
w.pb(110011);
w.pb(111111);
w.pb(200002);
w.pb(1000001);
w.pb(1001001);
w.pb(1002001);
w.pb(1010101);
w.pb(1011101);
w.pb(1012101);
w.pb(1100011);
w.pb(1101011);
w.pb(1102011);
w.pb(1110111);
w.pb(1111111);
w.pb(2000002);
w.pb(2001002);
w.pb(10000001);
w.pb(10011001);
w.pb(10100101);
w.pb(10111101);
w.pb(11000011);
w.pb(11011011);
w.pb(11100111);
w.pb(11111111);
w.pb(20000002);
int t;
cin>>t;
for(int i=0;i<w.size();i++)w[i]=w[i]*w[i];
for(int i=1;i<=t;i++)f(i);       
}
