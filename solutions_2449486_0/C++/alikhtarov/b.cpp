#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, C = 1;
  cin >> n;
  int nr, nc;
  while (n-- && cin >> nr >> nc) {
    vector<vector<int>> B(nr, vector<int>(nc));
    for (int i = 0; i < nr; ++i)
      for (int j = 0; j < nc; ++j)
	cin >> B[i][j];

    vector<int> MR(nr, 0), MC(nc, 0);
    for (int i = 0; i < nr; ++i)
      for (int j = 0; j < nc; ++j) {
	MR[i] = max(MR[i], B[i][j]);
	MC[j] = max(MC[j], B[i][j]);
      }

    bool good = true;
    for (int i = 0; i < nr; ++i)
      for (int j = 0; j < nc; ++j)
	if (B[i][j] < MR[i] && B[i][j] < MC[j])
	  good = false;

    cout << "Case #" << C++ << ": " << (good ? "YES" : "NO") << endl;
  }
}
