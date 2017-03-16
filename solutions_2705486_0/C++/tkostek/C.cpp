#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int con=521196;
//const int con=3;
string s[521196];
int f(int c){
string w;
cin>>w;
int n=w.size(),nie;
int g[n+1][n+1];
for(int i=0;i<n+1;i++){
for(int x=0;x<n+1;x++)g[i][x]=7777777;        
}
for(int i=0;i<n;i++){
for(int x=0;x<con;x++){
if(i+s[x].size()-1>=n)continue;   
nie=0;
for(int j=0;j<s[x].size();j++){
nie+=(w[i+j]!=s[x][j]);
if(nie>g[i][i+s[x].size()])break;
}
g[i][i+s[x].size()]=min(nie,g[i][i+s[x].size()]);    
}        
}
int odl[n+1];
for(int i=0;i<n+1;i++)odl[i]=7777777;
odl[0]=0;
for(int i=0;i<n;i++){
for(int x=0;x<n+1;x++){
if(odl[x]>odl[i]+g[i][x])odl[x]=odl[i]+g[i][x];        
}
}
cout<<"Case #"<<c<<": "<<odl[n]<<"\n";     
}
main(){
for(int i=0;i<con;i++)cin>>s[i];     
int t;
cin>>t;
for(int i=1;i<=t;i++)f(i);       
}
