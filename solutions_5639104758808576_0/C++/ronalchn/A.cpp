#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
  int T;

  cin >> T;

  for (int t=1;t<=T;t++) {
    int n;
    cin >> n;
    string v;
    cin >> v;

    int ans = 0, standing = 0;
    for (int i=0;i<=n;i++) {
      // required?
      int required = i;
      if (standing < required) {
        ans += required - standing;
        standing += required - standing;
      }

      standing += v[i]-'0';
    }
    printf("Case #%d: %d\n",t,ans);
  }

}
