#include<iostream>
using namespace std;
int f(int c){
int x,y;
cin>>y>>x;
cout<<"Case #"<<c<<": ";
if(x>=0){
for(int i=0;i<x;i++)cout<<"SN";         
}    
else{
for(int i=0;i<-x;i++)cout<<"NS";       
}
if(y>=0){
for(int i=0;i<y;i++)cout<<"WE";         
}    
else{
for(int i=0;i<-y;i++)cout<<"EW";       
}
cout<<"\n";
}
main(){
int t;
cin>>t;
for(int i=1;i<=t;i++)f(i);       
}
