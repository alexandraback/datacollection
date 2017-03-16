#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
ifstream fin("1.in");
ofstream fout("1.out");
int n,ans,i;
long long r,t;
double temp;
int main(){
  fin>>n;
  for(i=1;i<=n;i++){
	fin>>r>>t;
	temp=1.0-2.0*r+sqrt((2*r-1)*(2*r-1)*1.0+8.0*t);
	ans=floor(0.25*temp);
	fout<<"Case #"<<i<<": "<<ans<<"\n";
  }
  return(0);
}
