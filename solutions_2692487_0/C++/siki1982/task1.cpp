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

  LU A, N;
  vector<LU> motes;


  for (int nc = 1; nc <= num_case; ++nc) {
    // Init members
    cin >> A >> N;
    motes.clear();
    motes.resize(N, 0);

    for (LU i = 0; i < N; ++i) {
      cin >> motes[i];
    }
    sort(motes.begin(), motes.end());

    int result = 0;
    for (LU i = 0; i < N; ++i) {
      if (A <= motes[i]) {
        int rem = N - i;
        int put = 0;
        LU A2 = A;
        while (A2 <= motes[i] && put <= rem) {
          A2 += A2-1;
          put++;
        }
        if (put < rem) {
          result += put;
          A = A2;
          A += motes[i];
        } else {
          result += rem;
          break;
        }
      } else {
        A += motes[i];
      }
    }

    // Print output for case j
    cout << "Case #" << nc << ": " << result << endl;
  }


  return 0;
}
