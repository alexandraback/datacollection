#include <iostream>
#include <iomanip>
using namespace std;

int main() {

  int T;

  cin >> T;

  for ( int i = 0; i < T; i++ ) {

    double C, F, X;

    cin >> C >> F >> X;

    double spd = 2.00;

    double ans = X / spd;

    double timer = 0.00;

    while( true ) {

      ans = min( ans, timer + X / spd );

      timer += C / spd;

      if ( timer > ans ) break;

      spd += F;

    }

    cout << "Case #" << i+1 << ": ";

    cout << fixed << setprecision(8) << ans << endl;

  }

  return 0;

}
