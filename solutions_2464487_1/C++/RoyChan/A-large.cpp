#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
  long T,i,j,k;
  long double r,t,x,x_new;
  cin>>T;
  for (i=1; i<=T; i++){
    cout << "Case #"<<i<<": ";
    cin>>r>>t;
    x=0;
    x_new=1;
    while(abs(x_new-x)>0.01){
      x = x_new;
      x_new=x-(2*x*x+2*x*r-x-t)/(4*x+2*r-1);
    }
    cout << fixed << setprecision(0) << floor(x_new) << endl;
  }
  return 0;
}
