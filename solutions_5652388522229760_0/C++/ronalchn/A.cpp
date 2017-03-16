#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int T;

  cin >> T;

  for (int t=1;t<=T;t++) {
    int n;
    cin >> n;

    if (n==0) {
      printf("Case #%d: INSOMNIA\n",t);
      continue;
    }

    bool done[10] = {};
    int count = 0;
    int kn = 0;
    for (; count < 10;) {
      kn += n;
      string str = to_string(kn);
      for (int i=0;i<str.length();i++) {
        int d = str[i]-'0';
        if (!done[d]) {
          done[d] = true;
          count++;
        }
      }
    }

    printf("Case #%d: %d\n", t, kn);
  }

}
