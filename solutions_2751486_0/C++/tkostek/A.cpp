#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool tab[1000001];
bool zacz[1000001];
int f(int c){
string s;
int n,sp=0,m;
cin>>s>>n;
for(int i=0;i<s.size();i++){tab[i]=1-(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u');sp+=tab[i];}
int ile=0;
m=s.size();
for(int i=0;i<m;i++)zacz[i]=0;
for(int i=0;i<n;i++)ile+=tab[i];
zacz[0]=(ile==n);
for(int i=1;i<=m-n;i++){ile+=tab[i+n-1]-tab[i-1];zacz[i]=(ile==n);}
long long pop=0,a,b,wynik=0;;
for(int i=0;i<m;i++){
if(zacz[i]==0)continue;
a=i-pop+1;
b=m-i-n+1;
pop=i+1;
wynik+=a*b;        
}
cout<<"Case #"<<c<<": "<<wynik<<"\n";
}
main(){
int t;
cin>>t;
for(int i=1;i<=t;i++)f(i);      
}
