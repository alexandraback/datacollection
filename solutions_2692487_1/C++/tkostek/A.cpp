#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int tab[1000000];
int f(int c){
int n,r;
cin>>r>>n;
int min=n,w;
for(int i=0;i<n;i++)cin>>tab[i];
if(r==1){cout<<"Case #"<<c<<": "<<n<<"\n";return 0;}
sort(tab,tab+n);
w=0;
for(int x=0;x<n;x++){
while(tab[x]>=r){r+=r-1;w++;}  
r+=tab[x];
if(w+n-x-1<min)min=w+n-x-1;      
}        
cout<<"Case #"<<c<<": "<<min<<"\n";    
}
main(){
int t;
cin>>t;
for(int i=1;i<=t;i++)f(i);       
}
