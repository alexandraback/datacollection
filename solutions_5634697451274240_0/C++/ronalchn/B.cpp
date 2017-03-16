#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int T;

  cin >> T;

  for (int t=1;t<=T;t++) {
    string s;
    cin >> s;

    s += "+";
    int ans=0;
    for (int i=1;i<s.length();i++)
    {
      if (s[i]!=s[i-1]) ans++;
    }

    printf("Case #%d: %d\n", t, ans);
  }

}
