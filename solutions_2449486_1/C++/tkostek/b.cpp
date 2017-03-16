#include<iostream>
using namespace std;
int tab[101][101];
int f(int c){
int n,m;
cin>>n>>m;
for(int i=0;i<n;i++){
for(int x=0;x<m;x++)cin>>tab[i][x];        
}       
int maxpoz[n],maxpion[m];
for(int i=0;i<n;i++){
maxpoz[i]=0;
for(int x=0;x<m;x++){if(tab[i][x]>maxpoz[i])maxpoz[i]=tab[i][x];}
}
for(int i=0;i<m;i++){
maxpion[i]=0;
for(int x=0;x<n;x++){if(tab[x][i]>maxpion[i])maxpion[i]=tab[x][i];}     
}
for(int i=0;i<n;i++){
for(int x=0;x<m;x++){
if(tab[i][x]<maxpion[x]&&tab[i][x]<maxpoz[i]){cout<<"Case #"<<c<<": NO\n";return 0;}        
}        
}
cout<<"Case #"<<c<<": YES\n";
}
main(){
int t;
cin>>t;
for(int i=1;i<=t;i++)f(i);       
}
