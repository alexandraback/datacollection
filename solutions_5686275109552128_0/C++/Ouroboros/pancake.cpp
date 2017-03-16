#include <iostream>
#include <vector>

using namespace std;

int test(int clip,vector<int> diners) {
  int special = 0;
  for (auto &d : diners) {
    special += (d - 1) / clip;
  }
  return special + clip;
}

int main() {
  int T;
  cin >> T;
  for (int Case = 1;Case <= T;Case++) {
    int n;
    vector<int> diners;
    cin >> n;
    while (n--) { int a; cin >> a; diners.push_back(a); }

    int ans = 1000;
    for (int clip = 1; clip <= 1000;clip++) {
      int res = test(clip,diners);
      if (res < ans) ans = res;
    }
    printf("Case #%d: %d\n",Case,ans);
  }
}
