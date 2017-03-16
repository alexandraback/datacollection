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

string int2str(LL a) {
  stringstream ss;
  ss << a;
  return ss.str();
}

// NOTE: when the result is float and the problem requires 
// absolute or relative error small enough, use
// ss.precision(18);
string calc()
{
  LL r, t;
  cin >> r >> t;

  LL l = 1;
  LL h = t;
  while (l < h) {
    LL m = (l + h + 1) / 2;
    if (2*m + 2*r - 1 <= t/m) {
      l = m;
    } else {
      h = m - 1;
    }
  }

  return int2str(l);
  // return line;
}

int main(void)
{
  string line;
  getline(cin, line);
	int N = str2int(line);

	for (int i=1; i<=N; ++i) {
		cout << "Case #" << i << ": " << calc() << endl;
	}

	return 0;
}
