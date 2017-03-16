#include <iostream>
#include <vector>
#include <map>

#define PI 3.141592654

using namespace::std;


long amount(long r) {
  return r * r - (r - 1) * (r - 1);
}

int main(int argc, char *argv[]) {
  int n_cases;
  cin >> n_cases;

  for (int i = 0; i < n_cases; i++) {
    long start_rad, n_paint;
    cin >> start_rad >> n_paint;

    long k, j;
    for (k = start_rad+1, j = 0; ; k+=2, j++) {
      n_paint -= amount(k);

      if (n_paint < 0) break;
    }

    cout << "Case #" << i+1 << ": " << j << endl;
  }
}
