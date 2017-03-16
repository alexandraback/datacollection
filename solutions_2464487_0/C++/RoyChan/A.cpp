#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  long T,i,j,k;
  long double r,t;
  cin>>T;
  for (i=1; i<=T; i++){
    cout << "Case #"<<i<<": ";
    cin>>r>>t;
    t -=(r+1)*(r+1)-r*r;
    j=0;
    k=0;
    while(t>=0){
      k++; j++;
      t-=(r+2*k+1)*(r+k*2+1)-(r+k*2)*(r+k*2);
    }
    cout << j << endl;
  }
  return 0;
}
