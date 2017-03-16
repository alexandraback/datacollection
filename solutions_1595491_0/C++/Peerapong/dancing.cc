#include <iostream>

#define MIN(x,y) (x < y) ? x : y;

using namespace std;

int main(int argc, char **argv) {
  int T;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    int N, S, p;
    int r1 = 0, r2 = 0;
    
    cin >> N >> S >> p;

    for (int j = 0; j < N; j++) {
      int t, max, smax;

      cin >> t;
      
      if (t == 0) {
	max = 0;
	smax = 0;
      }
      else if (t % 3 == 0) {
	max = t/3;
	smax = max + 1;
      }
      else if (t % 3 == 1) {
	max = t/3 + 1;
	smax = max;
      }
      else if (t % 3 == 2) {
	max = t/3 + 1;
	smax = max + 1;
      }

      if (max >= p) {
	r1++;
      }
      else if (smax >= p) {
	r2++;
      }
    }

    r2 = MIN(r2, S);
    int r = r1 + r2;

    cout << "Case #" << i << ": " << r << endl;
  }
}
