#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int K, C, S;

int main() {
  int nnn;
  cin >> nnn;
  for (int iii = 0; iii < nnn; ++iii) {
    cout << "Case #" << iii+1 << ":";
    cin >> K >> C >> S;
    vector<long long> ans;
    for (int p = 0; p < K; p += C) {
      long long v = 0;
      for (int i = 0; i < C; ++i) {
	int d = p + i;
	if (d >= K) d = 0;
	v = v * K + d;
      }
      ans.push_back(v);
    }
    if ((int)ans.size() <= S) {
      for (auto v : ans) {
	cout << " " << v+1;
      }
    } else {
      cout << " IMPOSSIBLE";
    }
    cout << endl;
  }
}
