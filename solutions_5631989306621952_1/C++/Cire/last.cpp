#include <iostream>

using namespace std;


string opt(string s) {
  if (s.length()<=1)
    return s;
  char c='A';
  int l=0;
  for(int i=0; i < s.length(); i++) {
    if (s.at(i)>c) {
      c=s.at(i);
      l=i;
    }
  }
  string ans=opt(s.substr(0,l));
  for(int i=l; i < s.length(); i++) {
    if (s.at(i)==c)
      ans=c+ans;
    else
      ans=ans+s.at(i);
  }
  return ans;
}



int main() {
  int T;
  cin >> T;
  for(int t =1; t <= T; t++) {
    string s;
    cin >> s;
    cout << "Case #" << t << ": " << opt(s) << endl;
  }
  return 0;
}
