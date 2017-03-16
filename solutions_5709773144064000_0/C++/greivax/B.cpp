#include <iomanip>
#include <iostream>
using namespace std;

int main(){
  cout.setf(ios::fixed);
  cout.precision(10);
  int T;
  cin >> T;
  for(int c=1; c<=T; ++c){
    double C, F, X;
    cin >> C >> F >> X;
    double r = 2.0, t = 0.0;
    bool done = false;
    while(not done){
      double t1 = X / r;
      double t2 = C / r + X / (r + F);
      if(t1 < t2){
        t += t1;
	done = true;
      } else {
        t += C / r;
	r += F;
      }
    }
    cout << "Case #" << c << ": " << t << endl;
  }
}
