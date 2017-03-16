#include<iostream>
using namespace std;

int main(){
cout.precision(10);
int t;
cin>>t;
for(int i=1;i<=t;i++){
int a,b;
cin>>a>>b;
long double s=1;
long double m=b+2;
for(int j=1;j<=a;j++){
long double t;
cin>>t;
s*=t;
long double r=a-j+b-j+1+(1-s)*(b+1);
if(r<m)m=r;
}
cout<<"Case #"<<i<<": "<<m<<endl;
}
return 0;
}
