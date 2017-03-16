#include <iostream>
#include <string>

using namespace std;

int
main(int argc, char **argv)
{
  int T;
  int i, j, ret;
  string s;

  cin >> T;
  for(i=1;i<=T;i++) {
    cin >> s;
    ret = 0;
    //    cout << s << endl;
    for(j=0;j<s.size()-1;j++) {
      if (s[j] != s[j+1]) {
	ret++;
      }
    }
    if (s[s.size()-1] == '-') {
      ret++;
    }
    cout << "Case #" << i << ": " << ret << endl;
  }
  return 0;
}
