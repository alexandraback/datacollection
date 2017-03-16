#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int R, C, M, E;
int map[57][57];

void reprint(string text, int n) {
  for (int i = 0; i < n; ++i)
    cout << text;
}

void fillMap(char c) {
  cout << "c";
  string sc = string(1, c);
  reprint(sc, C - 1);
  cout << endl;
  for (int i = 1; i < R; ++i) {
    reprint(sc, C);
    cout << endl;
  }
}

int main()
{
  int T;
  cin >> T;
  for (int Ti = 1; Ti <= T; Ti++) {
    // input
    cin >> R >> C >> M;
    E = R * C - M;
    //cout << "Case #" << Ti << ":" << R << " " << C << " " << M << endl;
    cout << "Case #" << Ti << ":" << endl;
    
    // special cases
    if (R == 1) {
      cout << "c";
      reprint(".", E - 1);
      reprint("*", M);
      cout << endl;
      continue;
    }
    if (C == 1) {
      cout << "c" << endl;
      reprint(".\n", E - 1);
      reprint("*\n", M);
      continue;
    }
    if (E == 1) {
      fillMap('*');
      continue;
    }
    if (M == 0) {
      fillMap('.');
      continue;
    }
    if (E <= 3 || E == 5 || E == 7) {
      cout << "Impossible" << endl;
      continue;
    }
    if ((R == 2 || C == 2) && E % 2 != 0) {
      cout << "Impossible" << endl;
      continue;
    }
    
    // usual case (1 <= M <= RC - 4 && max(R, C) >= 3)
    
    // first two rows have identical number
    int H = min(C, E / 2);
    if (E - 2 * H == 1)
      H--;
    cout << "c";
    reprint(".", H - 1);
    reprint("*", C - H);
    cout << endl;
    reprint(".", H);
    reprint("*", C - H);
    cout << endl;
    //cout << " E = " << E << "; H = " << H << endl;
    E -= 2 * H;
    
    // subsequent rows
    for (int i = 2; i < R; ++i) {
      if (E <= 3)
        H = E;
      else if (C >= E)
        H = E;
      else
        H = min(C, E - 2);
      
      reprint(".", H);
      reprint("*", C - H);
      //cout << " E = " << E << "; H = " << H << endl;
      cout << endl;
      
      E -= H;
    }
  }
  return 0;
}
