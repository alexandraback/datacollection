#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
ifstream fin("1.in");
ofstream fout("1.out");
int n,ans,i,x1,x2,x3;
long long r,t,s;
long double temp;
int main(){
  fin>>n;
  for(i=1;i<=n;i++){
	fin>>r>>t;
	temp=2*r-1.0;
	temp*=temp;
	temp+=8.0*t;
	//temp=1.0-2.0*r+sqrt((2*r-1)*(2*r-1)*1.0+8.0*t);
	temp=temp/16.0;
	temp=0.25*(1.0-2.0*r)+sqrtl(temp);
	ans=floor(temp);
	x1=ans-1;
	x2=ans;
	x3=ans+1;
	if(2*x1+(2*r-1)-t/(x1*1.0)<=0)ans=x1;
	if(2*x2+(2*r-1)-t/(x2*1.0)<=0)ans=x2;
	if(2*x3+(2*r-1)-t/(x3*1.0)<=0)ans=x3;
	fout<<"Case #"<<i<<": "<<ans<<"\n";
  }
  return(0);
}
