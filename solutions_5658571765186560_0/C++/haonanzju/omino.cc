#include <iostream>
#include <fstream>
#include <string>

using std::istream; using std::ostream;
using std::ifstream; using std::ofstream;
using std::string;

enum Winner {
  RICHARD,
  GABRIEL
};

void Test(int caseNum, istream &is, ostream &os) {
  int X, R, C;
  is >> X >> R >> C;
  if (R < C)
    std::swap(R, C);
  Winner flag;
  if (1 == X) {
    flag = GABRIEL;
  } else if (2 == X) {
    if (R < 2 || (R * C) % 2 != 0)
      flag = RICHARD;
    else
      flag = GABRIEL;
  } else if (3 == X) {
    if (R < 3 || (R == 3 && C == 1) || (R * C) % 3 != 0)
      flag = RICHARD;
    else
      flag = GABRIEL;
  } else if (4 == X) {
    if (R < 4 || (R == 4 && C == 1) || (R == 4 && C == 2))
      flag = RICHARD;
    else
      flag = GABRIEL;
  }
  
  if (RICHARD == flag)
    os << "Case #" << caseNum << ": RICHARD\n";
  else
    os << "Case #" << caseNum << ": GABRIEL\n";
}

int main() {
  ifstream is("D-small-attempt1.in");
  ofstream os("output.txt");
  int T;
  is >> T;
  for (int i = 1; i <= T; i++)
    Test(i, is, os);
  is.close();
  os.close();
  return 0;
}