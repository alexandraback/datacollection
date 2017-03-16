#include <iostream>

using namespace std;

int
generation(long long P, long long Q, int g) {
  int result = 0;

  while((g > 0) && (P < Q)) {
    g--;
    result++;
    P *= 2;
  }

  if((P < Q) || ((P > Q) && (generation(P-Q, Q, g) == -1))) {
    result = -1;
  }

  return result;
}

int
main() {
  int T;

  cin >> T;

  for(int i = 1; i <=T; i++) {
    long long P, Q;
    char c;

    cin >> P >> c >> Q;

    int g = generation(P, Q, 40);

    cout << "Case #" << i << ": ";
    if(g > 0) {
      cout << g << endl;
    } else {
      cout << "impossible" << endl;
    }
  }

  return 0;
}

