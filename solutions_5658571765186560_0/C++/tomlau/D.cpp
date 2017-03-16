#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const string richard = "RICHARD";
const string gabriel = "GABRIEL";

int main() {
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    int X, R, C;
    cin >> X >> R >> C;
    if (R < C) swap(R, C);
    int RC = R*10 + C;
    string winner;
    if (X == 1) winner = gabriel;
    else if (X == 2) winner = (RC==11 || RC==31 || RC==33) ? richard : gabriel;
    else if (X == 3) winner = (RC==32 || RC==33 || RC==43) ? gabriel : richard;
    else if (X == 4) winner = (RC==43 || RC==44) ? gabriel : richard;
    cout << "Case #" << t << ": " << winner << endl;
 }
}
