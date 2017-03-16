#include <iostream>
using namespace std;

int main(){
  int t,u,ok,x,r,c,i,j;
  cin>>t; for (u=0; u<t; u++){
    cin>>x>>r>>c; ok=1; if (r>c) swap(r,c);
    if (x>=7 || (r*c)%x || c<x || r<(x+1)/2 || c<1+(x-(x+1)/2)) ok=0;
    if (ok && r==(x+1)/2){
      for (i=0; i<=x-r; i++){
	for (j=i; j<=c-(1+(x-r-i)); j++) if ((j*r-i)%x==0) break;
	if (j>c-(1+(x-r-i))) break;
      }
      if (i<=x-r) ok=0; 
    }
    cout<<"Case #"<<(u+1)<<": "<<((!ok)?"RICHARD":"GABRIEL")<<endl;
  }
  return 0;
}
