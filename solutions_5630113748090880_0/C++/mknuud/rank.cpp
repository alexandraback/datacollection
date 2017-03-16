#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dw(uint caseNo) {
  uint N;
  cin >> N;

  uint maxHt = 0, minHt = -1;
  vector<uint> allHts;
  for (uint i = 0; i < 2 * N - 1; i++) {
    for (uint j = 0; j < N; j++) {
      uint height;
      cin >> height;
      allHts.push_back(height);
    }
  }
  sort(allHts.begin(), allHts.end());

  vector<uint> ans;
  uint i = 0;
  while (i < allHts.size()) {
    if (i + 1 < allHts.size() && allHts[i] == allHts[i + 1]) {
      i = i + 2;
    } else {
      ans.push_back(allHts[i]);
      i++;
    }
  }

  cout << "Case #" << caseNo << ": ";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i + 1 < ans.size()) {
      cout << " ";
    }
  }
  cout << endl;
}

int main() {
  uint T;
  cin >> T;
  for (uint t = 0; t < T; t++) {
    dw(t + 1);
  }
  return 0;
}
