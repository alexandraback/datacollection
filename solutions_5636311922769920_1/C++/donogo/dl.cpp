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

    cout << "Case #" << t << ":";

    if (S * C < K) {
      cout << " IMPOSSIBLE";
    } else {
      LL a, b;
      LL pos, coef;
      int done = 0;
      for (a = 0; a < S; a++) {
	pos = 0;
	for (b = 0; b < C; b++) {
	  coef = a * C + b;
	  pos = pos * K + coef;
	  if (coef == K - 1) {
	    done = 1;
	    break;
	  }
	}
	cout << " " << pos + 1;
	if (done) {
	  break;
	}
      }
    }
    cout << endl;
  }
  return 0;
}
