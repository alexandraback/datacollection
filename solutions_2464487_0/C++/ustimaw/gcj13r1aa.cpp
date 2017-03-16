#include<iostream>
#include<cmath>

using namespace std;

int main(){
  int T;
  cin>>T;
  for(int i=1;i<=T;i++){
    long long r,t;
    cin>>r>>t;
    long long l=0,h=1e18;
    while(h-l>=2){
      long long m=(l+h)/2;
      double dm=m;
      if((2*dm*(dm-1)+(2*r+1)*dm)<=t){
	l=m;
      }else{
	h=m;
      }
    }
    cout<<"Case #"<<i<<": "<<l<<endl;
  }
  return 0;
}
