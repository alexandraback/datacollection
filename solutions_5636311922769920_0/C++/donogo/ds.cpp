#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <cstdio>

using namespace std;
typedef long long int LL;


int main(void) {
  int T, t;
  cin >> T;

  for (t = 1; t <= T; t++) {
    LL K, C, S;
    LL x, W, i;
    cin >> K;
    cin >> C;
    cin >> S;

    W = 1;
    for (x = 1; x < C; x++) {
      W *= K;
    }
    cout << "Case #" << t << ":";
    for (i = 0; i < S; i++) {
      cout << " " << 1 + i * W;
    }
    cout << endl;
  }
  return 0;
}
