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
  int K, L, S;
  char c;

  map<char, int> tw;
  string target;

  int maxd;
  for (int nc = 1; nc <= num_case; ++nc) {
    // Init members
    cin >> K >> L >> S;
    tw.clear();

    for (int i = 0; i < K; ++i) {
      cin >> c;
      tw[c]++;
    }

    cin >> target;

    double expd = 1.0;
    for (int i = 0; i < L; ++i) {
      if (tw.find(target[i]) == tw.end()){
        expd*=0;
        break;
      }
      else {
        expd = expd*((double)tw[target[i]])/K;
      }
    }
    //cerr << "Exp: " << expd << endl;

    expd *= (S - L + 1);


    if (expd != 0.0) {
      int min = 1;
      for (int j = 1; j < L; ++j) {
        int k = 0;
        while (j + k < L) {
          if (target[k] == target[j + k]) {
            ++k;
          } else {
            break;
          }
        }
        if (j + k == L) {
            break;
        } else {
          ++min;
        }
      }

      //cerr << "Min: " << min << endl;

      if (L == min) maxd = S/L;
      else maxd = (S - (L - min))/min;

      //cerr << "Max: " << maxd << endl;

    }

    double res;
    if (expd == 0.0) res = 0.0;
    else res = (double)maxd - expd;

    // Print output for case j
    cout << "Case #" << nc << ": " << std::setprecision(7) << res << endl;
  }


  return 0;
}
