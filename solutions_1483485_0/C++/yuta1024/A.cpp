#include <iostream>
#include <string>
using namespace std;

const string tbl = "yhesocvxduiglbkrztnwjpfmaq";        

int main()
{
  int T;
  cin >> T;
  for (int testcase = 1; testcase <= T; ++testcase) {
    string s;
    if (testcase == 1)
      getline(cin, s);
    getline(cin, s);

    for (unsigned int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ')
	continue;
      s[i] = tbl[s[i]-'a'];
    }
    cout << "Case #" << testcase << ": " << s << endl;
  }
  return 0;
}
