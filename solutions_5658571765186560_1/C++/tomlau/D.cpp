#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const string richard = "RICHARD";
const string gabriel = "GABRIEL";

int main() {
  int T, X, R, C;
  cin >> T;
  for (int t=1; t<=T; t++) {
    cin >> X >> R >> C;
    if (R < C) swap(R, C);
    string winner;
    if (X >= 7 || R*C % X > 0) winner = richard;
    else if (X == 1) winner = gabriel;
    else if (X == 2) winner = (C==1 && R%2) ? richard : gabriel;
    else if (X == 3) winner = (C==1) ? richard : gabriel;
    else if (X == 4) winner = (C<=2) ? richard : gabriel;
    else if (X == 5) winner = (C<=2 || C==3 && R==5) ? richard : gabriel;
    else if (X == 6) winner = (C<=3) ? richard : gabriel;
    cout << "Case #" << t << ": " << winner << endl;
  }
}
