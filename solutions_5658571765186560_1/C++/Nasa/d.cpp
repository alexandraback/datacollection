#include <iostream>
using namespace std;

int main(){
  int t,u,ok,x,r,c,i,j;
  cin>>t; for (u=0; u<t; u++){
    cin>>x>>r>>c; ok=1; if (r>c) swap(r,c);
    if (x>=7 || (r*c)%x || c<x || r<(x+1)/2 || c<1+(x-(x+1)/2)) ok=0;
    if (ok && r==(x+1)/2){
      if (x==4 && r==2) ok=0;
      if (x==5 && r==3 && c<3+3) ok=0;
      if (x==6 && r==3) ok=0;
    }
    cout<<"Case #"<<(u+1)<<": "<<((!ok)?"RICHARD":"GABRIEL")<<endl;
  }
  return 0;
}
