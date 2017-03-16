#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, C = 1;
  cin >> n;
  while (n--) {
    vector<string> B;
    for (int i = 0; i < 4; ++i) {
      string R;
      cin >> R;
      B.push_back(R);
    }

    bool full = true;
    vector<set<char>> X(10);
    for (int i = 0; i < 4; ++i) {
      X[0].insert(B[i][i]);
      X[1].insert(B[3-i][i]);
      for (int j = 0; j < 4; ++j) {
	if (B[i][j] == '.')
	  full = false;
	X[2 + i].insert(B[i][j]);
	X[6 + j].insert(B[i][j]);
      }
    }

    bool winx = false, wino = false;
    for (auto x : X) {
      string xs(x.begin(), x.end());
      if (xs == "X" || xs == "TX") winx = true;
      if (xs == "O" || xs == "OT") wino = true;
    }
    
    cout << "Case #" << C++ << ": ";
    if (winx) cout << "X won";
    else if (wino) cout << "O won";
    else if (full) cout << "Draw";
    else cout << "Game has not completed";
    cout << endl;
  }
}
