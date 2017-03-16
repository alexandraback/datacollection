#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int T;

  cin >> T;

  vector<int> p(1000);
  for (int t=1;t<=T;t++) {
    int D;
    cin >> D;

    for (int i=0;i<D;i++) {
      cin >> p[i];
    }

    int ans = 10000;
    for (int mx = 1;mx<=1000;mx++) {
      int special = 0;
      for (int i=0;i<D;i++) {
        special += (p[i]-1)/mx;
      }
      int result = special + mx;
      ans = min(ans,result);
    }
    printf("Case #%d: %d\n",t,ans);
  }

}
