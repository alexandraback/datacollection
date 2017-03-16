#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <sstream>
using namespace std;

typedef long long LL;
typedef unsigned int UINT32;

int str2int(const string &s) {
  stringstream ss(s);
  int a;
  ss >> a;
  return a;
}

string int2str(int a) {
  stringstream ss;
  ss << a;
  return ss.str();
}

bool check(vector<string> &b, char ch) {
  int i, j;
  for (i = 0; i < 4; ++i) {
    for (j = 0; j < 4; ++j) {
      if (b[i][j] != ch) break;
    }
    if (j == 4) return true;
  }
  for (j = 0; j < 4; ++j) {
    for (i = 0; i < 4; ++i) {
      if (b[i][j] != ch) break;
    }
    if (i == 4) return true;
  }
  for (i = 0; i < 4; ++i) {
    if (b[i][i] != ch) break;
  }
  if (i == 4) return true;

  for (i = 0; i < 4; ++i) {
    if (b[i][3-i] != ch) break;
  }
  if (i == 4) return true;

  return false;
}

string calc()
{
  vector<string> b(4);
  cin >> b[0] >> b[1] >> b[2] >> b[3];
  int tr = -1;
  int tc = -1;
  int i, j;
  bool hasdot = false;
  for (i = 0; i < 4; ++i) for (j = 0; j < 4; ++j) {
    if (b[i][j] == 'T') {tr =i; tc = j;}
    if (b[i][j] == '.') {hasdot = true; }
  }
  if (tr != -1) {
    b[tr][tc] = 'X';
  }
  if (check(b, 'X')) {
    return "X won";
  }
  if (tr != -1) {
    b[tr][tc] = 'O';
  }
  if (check(b, 'O')) {
    return "O won";
  }
  if (hasdot) {
    return"Game has not completed";
  }
  return "Draw";
}

int main(void)
{
  // NOTE: if using getline() to read the input, the following two lines should be
  // added to read the line sepeartor in the first line. 
  string line;
  getline(cin, line);
	int N = str2int(line);

	for (int i=1; i<=N; ++i) {
		cout << "Case #" << i << ": " << calc() << endl;
	}

	return 0;
}
