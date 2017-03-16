#include <iostream>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <vector>

#define PI 3.14159265359

using namespace std;

int process(int i) {
  long long r, t, res = 0;
  cin >> r;
  cin >> t;

  long long intern_radius = r;
  long long radius = r + 1;
  do {
    t = t - (radius*radius - intern_radius*intern_radius);
    if(t>=0) {
      res++;
      intern_radius += 2;
      radius += 2;
    }
  } while (t > 0);

  cout << "Case #" << i << ": " << res << endl;
  return i;
}

int main() {

  int nb;
  cin >> nb;
  for(int i=1; i<=nb; i++) {
    process(i);
  }
  return 0;
}
