#include<iostream>
#include<iomanip>

using namespace std;

int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    cout<<"Case #"<<tc<<": ";
    double C, F, X; cin>>C>>F>>X;
    double t=0, k=0, r=2;
    if (X<=C){
      cout<<setprecision(10)<<X/2<<endl;
      continue;
    }
    while(1){
      t+=C/r;
      if((X-C)/r<X/(r+F))
	break;
      else
	r=r+F;
    }
    t+=(X-C)/r;
    cout<<setprecision(10)<<t<<endl;
  }
  return 0;
}
	
