#include <iostream>
#include <fstream>
#include <string>

using std::istream; using std::ostream;
using std::ifstream; using std::ofstream;
using std::string;

void Test(int caseNum, istream &is, ostream &os) {
  int R, C, W;
  is >> R >> C >> W;
  int score = 0;
  int row_test = (C - W) / W + 1;
  int remain = C - (row_test - 1) * W;
  score = R * row_test;
  if (remain == W)
    score += W - 1;
  else
    score += W;

  os << "Case #" << caseNum << ": " << score << "\n";
}

int main() {
  ifstream is("A-large.in");
  ofstream os("output.txt");
  int T;
  is >> T;
  for (int i = 1; i <= T; i++)
    Test(i, is, os);
  is.close();
  os.close();
  return 0;
}