#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct atak{
int czas,sila,p,k;      
};
bool comp(atak a,atak b){
return a.czas<b.czas;     
}
int f(int c){
int n;
int d,nr,p,k,s,dd,druch,ds;
vector<atak>v;
atak at;
cin>>n;
for(int i=0;i<n;i++){
cin>>d>>nr>>p>>k>>s>>dd>>druch>>ds;
at.czas=d;
at.p=3*p+2+1000;
at.k=3*(k+1)+1000;
at.sila=s;
v.push_back(at);
for(int j=0;j<nr-1;j++){
at.czas+=dd;
at.p+=3*druch;
at.k+=3*druch;
at.sila+=ds;        
v.push_back(at);
}        
}
sort(v.begin(),v.end(),comp);   
int wys[2000];
int nowy[2000];
for(int i=0;i<2000;i++)wys[i]=nowy[i]=0;
int ud=0,ost=-1;
bool ok=0;
for(int i=0;i<v.size();i++){
//cout<<v[i].czas<<" "<<v[i].sila<<" "<<v[i].p<<" "<<v[i].k<<"\n";
if(v[i].czas!=ost){
for(int j=0;j<2000;j++)wys[j]=nowy[j];     
}
ok=0;
for(int j=v[i].p;j<=v[i].k;j++){
if(v[i].sila>wys[j])ok=1;        
}
ud+=ok;
//cout<<ok<<"\n";
for(int j=v[i].p;j<=v[i].k;j++){
nowy[j]=max(nowy[j],v[i].sila);       
}
ost=v[i].czas;        
} 
cout<<"Case #"<<c<<": "<<ud<<"\n";
}
main(){
int t;
cin>>t;
for(int i=1;i<=t;i++)f(i);       
}
