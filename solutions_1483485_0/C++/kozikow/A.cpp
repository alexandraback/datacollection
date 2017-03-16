#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
string stare[]={
  "ejp mysljylc kd kxveddknmc re jsicpdrysi",
  "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
  "de kr kd eoya kw aej tysr re ujdr lkgc jv",
  "qz"
};
string nowe[]={
  "our language is impossible to understand",
  "there are twenty six factorial possibilities",
  "so it is okay if you want to just give up",
  "zq"
};
char mapping[255];

int main() {
  ios_base::sync_with_stdio(0);
  
  for(int i=0; i<4; i++) {
    assert(nowe[i].size() == stare[i].size());
    for(int j=0; j<nowe[i].size(); j++) {
      mapping[stare[i][j]] = nowe[i][j];
    }
  }
  
  int tests;
  cin >> tests;
  cin.ignore();
  for(int t=1; t<=tests; t++) {
    string s;
    getline(cin, s);
    cout << "Case #" << t << ": ";
    for(int i=0; i<s.size(); i++) {
      cout << mapping[s[i]];
    }
    cout << '\n';
  }
  return 0;
}