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
#define uint32_t unsigned int

uint32_t decide(const uint32_t &score, const uint32_t &p, uint32_t &S) {
  uint32_t max = 0;
  if (score%3 == 0) {
    max = score/3;
    if (score == 0 && max < p) return 0;
  } else if (score%3 == 1) {
    max = (score - 1)/3 + 1;
    if (max >= p) return 1;
    else return 0;
  } else if (score%3 == 2) {
    max = (score - 2)/3 + 1;
  }

  if (max >= p) return 1;
  if (max == p - 1 && S > 0) {
    S-=1;
    return 1;
  }
  return 0;
}


int main() {
  // Declare members
  uint32_t num_case;
  cin >> num_case;

  uint32_t N, S, p, score;


  for (uint32_t j = 1; j <= num_case; j++) {
    // Init members
    cin >> N;
    cin >> S;
    cin >> p;
    uint32_t num = 0;
    for (uint32_t i = 0; i < N; ++i) {
      cin >> score;
      num += decide(score, p, S);
    }

    // Print output for case j
    cout << "Case #" << j << ": " << num << endl;
  }


  return 0;
}
