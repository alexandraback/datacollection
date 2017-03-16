#include <iostream>
#include <vector>
#include <set>

using namespace std;

//#define NAME "my"
#define NAME "D-small-attempt2"
//#define NAME "D-large"

void solveCase(int tc) {
  int X, a, b;
  cin >> X >> a >> b;
  if (a > b) swap(a, b);

  bool can;
  if (X == 1) can = false;
  else if (X == 2) can = ((a * b) % 2 != 0);
  else if (X == 3) can = ((a * b) % 3 != 0) || (a == 1);
  else can = ((a * b) % 4 != 0) || (a <= 2);

  string answer = can ? "RICHARD" : "GABRIEL";
  cout << "Case #" << (tc + 1) << ": " << answer << endl;
  cerr << "Case #" << (tc + 1) << ": " << answer << endl;
}

void initialize() {
}

int main() {
  freopen(NAME".in", "rt", stdin);
  freopen(NAME".out", "wt", stdout);
  int T;
  cin >> T;
  initialize();
  for (int i = 0; i < T; i++) {
    solveCase(i);
  }
  return 0;
}
