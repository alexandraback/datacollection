#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

const string dic2  = "ynficwlbkuomxsevzpdrjgthaq";
const string dic = "yhesocvxduiglbkrztnwjpfmaq";

string googlerese(string p)
{
  int len = p.length();
  for (int i = 0; i < len; ++i) {
    if (!isspace(p[i])) {
      p[i] = dic[p[i] - 'a'];
    }
  }
  return p;
}

int main()
{
  string s;
  getline(cin, s);

  stringstream ss(s);
  int T;
  ss >> T;

  for (int i = 0; i < T; ++i) {
    getline(cin, s);

    cout << "Case #" << i+1 << ": " << googlerese(s) << endl;
  }
  
  return 0;
}

