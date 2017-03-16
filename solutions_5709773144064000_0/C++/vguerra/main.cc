// Victor Guerra <vguerra@gmail.com>
// 2014-04-12

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  int T; 
  cin >> T; 
  
  for (int t = 1; t <= T; ++t) {
    double seconds, C, F, X, cps;

    seconds = 0.0;
    cps = 2.0;
    cin >> C >> F >> X; 
    
    bool stop = false;

    while (!stop) {
      double secs_to_farm, secs_to_x, hip_secs_to_x;
      secs_to_x = X / cps;
      secs_to_farm = C / cps;
      hip_secs_to_x = X / (cps + F);

      if (secs_to_x > (hip_secs_to_x + secs_to_farm)) {
        cps += F;
        seconds += secs_to_farm;
      } else {
        stop = true;
        seconds += secs_to_x;
      }
    }
    printf("Case #%d: %.7f\n", t, seconds);
  }


  return 0;
}
