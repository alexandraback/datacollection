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

LL E, R, N;
vector<LL> v;
LL ans;

void calc(LL curv, LL cure, int pos) {
  if (pos == N) {
    if (curv > ans) ans = curv;
    return;
  }

  for (int i = 0; i <= cure; ++i) {
    LL a = cure-i+R;
    if (a > E) a = E;
    calc(curv+i*v[pos], a, pos+1);
  }
}

string calc()
{
  cin >> E;
  cin >> R;
  cin >> N;
  v.resize(N);
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }

  ans = 0;
  calc(0, E, 0);

  return int2str(ans);
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
