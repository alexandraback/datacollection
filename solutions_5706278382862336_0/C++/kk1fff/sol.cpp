#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

bool isp2(int i) {
  bool f = false;
  while(i) {
    if (i & 1) {
      if (!f) {
        f = true;
      } else {
        return false;
      }
    }
    i >>= 1;
  }
  return true;
}

int leftmost1(int i) {
  int c = -1;
  while (i) {
    i >>= 1;
    c++;
  }
  return c;
}

void run(istream& in, int t) {
  int P, Q;
  string s;
  in >> s;
  sscanf(s.c_str(), "%d/%d", &P, &Q);

  // !!!!!!!!

  if (!isp2(Q)) {
    cout << "Case #" << t << ": impossible" << endl;
    return;
  }

  cout << "Case #" << t << ": " << leftmost1(Q >>= leftmost1(P)) << endl;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    run(cin, i + 1);
  }
}
