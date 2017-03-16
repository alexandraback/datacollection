#include <fstream>
#include <string>

using std::istream; using std::ostream;
using std::ifstream; using std::ofstream;
using std::string;

void Test(int caseNum, istream &is, ostream &os) {
  int s_max;
  is >> s_max;
  string str;
  is >> str;
  int sum_stand = 0, sum_add = 0;
  for (int i = 0; i <= s_max; i++) {
    int digit = str[i] - '0';
    int add = 0;
    if (digit > 0 && i > sum_stand)
      add = i - sum_stand;
    sum_stand += digit + add;
    sum_add += add;
  }
  os << "Case #" << caseNum << ": " << sum_add << '\n';
}

int main() {
  ifstream is("A-small-attempt0.in");
  ofstream os("output.txt");
  int T;
  is >> T;
  for (int i = 0; i < T; i++)
    Test(i + 1, is, os);
  is.close();
  os.close();
  return 0;
}