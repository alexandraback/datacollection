#include <iostream>
#include <string>
#include <cmath>
using namespace std;

typedef long long int LL;

int main(){
  
  LL T;
  cin >> T;
  for(LL t = 0; t < T; t++){
    // area for n-cm filled circle Ac = pi*n*n
    // area for i-th thick ring Ar = Ac[i] - Ac[i-1]
    LL R, _T;
    cin >> R >> _T;
    
    cout << "Case #" << t+1 << ": ";
    

    double r = (double)R;
    double a = (double)_T;
    LL start = max((LL)((-(2*r-1) + sqrt(pow(2*r - 1,2) + 8*a)) / 4.)-10, (LL)0) ;
    for(LL  i =start;;i++){
      if(_T < (i+1)*(2*(R+1+i)-1)){
	cout << i << endl;
	break;
      }
    }
  }
}
