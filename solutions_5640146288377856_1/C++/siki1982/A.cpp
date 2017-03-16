#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>


using namespace std;

#define PI acos(-1.)
#define EPS 1e-7
#define LL long long
#define U unsigned int
#define LU long unsigned
#define LLU long long unsigned




int main() {
  // Declare members
  int num_case;
  cin >> num_case;

  int C, R;
  int W;


  for (int nc = 1; nc <= num_case; ++nc) {
    // Init members
    cin >> R >> C;
    cin >> W;

    int res = (R - 1)*C/W;
    if (C % W == 0) res += C/W - 1 + W;
    else res += C/W + W;

    // Print output for case j
    cout << "Case #" << nc << ": " << res << endl;
  }


  return 0;
}
