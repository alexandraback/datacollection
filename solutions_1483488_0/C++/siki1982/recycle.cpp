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

set<pair<uint32_t, uint32_t> > pairs;

void genpairs(uint32_t a, uint32_t b, uint32_t n) {
  int length = 1;
  uint32_t base = 10;
  while (n % base != n) {
    length++;
    base *= 10;
  }

  base = 10;
  for (int i = 1; i < length; ++i) {
    uint32_t rec = n % base;
    uint32_t recd = (n - rec)/base + rec*pow(10, length - i);
    if (recd >= a && recd <= b && n < recd) {
      pairs.insert(pair<uint32_t, uint32_t>(n, recd));
    }
    base *= 10;
  }
}

int main() {
  // Declare members
  uint32_t num_case;
  cin >> num_case;

  uint32_t a, b;


  for (uint32_t j = 1; j <= num_case; j++) {
    // Init members
    pairs.clear();
    cin >> a;
    cin >> b;

    for (uint32_t i = a; i <= b; ++i) {
      genpairs(a, b, i);
    }

    // Print output for case j
    cout << "Case #" << j << ": " << pairs.size() << endl;
  }


  return 0;
}
