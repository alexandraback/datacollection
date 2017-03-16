#include <iostream>
#include <iomanip>
using namespace std;

double do_case(){
  long double C,F,X;
  cin >> C >> F >> X;
  
  long double best = X/2;
  
  long double prod = 2;
  long double curr = 0;
  
  for(int p=1;;p++){
    long double t = C / prod;
    curr += t;
    prod += F;
    
    long double ans = curr + X / prod;
    if(ans > best) break;
    
    best = ans;
  }
  return best;
}

int main(){
  cout << fixed << setprecision(7);
  int T,C=1;
  cin >> T;
  while(T--)
    cout << "Case #" << C++ << ": " << do_case() << endl;
  return 0;
}
