#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for(int caseno=1;caseno<=cases;caseno++) {
    string s;
    int n;
    cin >> s >> n;
    int last=0;
    long long ret=0;
    int lastgood=-1;
    for (int i=0;i<(int)s.length();i++) {
      if (s[i]=='a'||s[i]=='o'||s[i]=='e'||s[i]=='u'||s[i]=='i') {
        last=0;
      } else {
        last=last+1;
      }
      if (last >= n) {
        lastgood=i-n+1;
      }
      ret += lastgood+1;
    }
    cout << "Case #" << caseno << ": " << ret << '\n';
  }
  return 0;
}
