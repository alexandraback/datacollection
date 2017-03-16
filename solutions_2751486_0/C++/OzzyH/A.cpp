//#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

ifstream cin ("A-small.in");
ofstream cout ("A-small.out");


bool isCons(char c) {
 if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return false;
 return true;
}


long long run() {
  string s; int n;
  cin >> s >> n;
  int sc = 0;
  int last = -1;
  bool br = 0;
  long long ans = 0;
  for (int i=0; i<s.length(); i++) {
    if (isCons(s[i])) sc++;
    else {sc=0; br = 1;};
    if (sc>=n) {
      long long ans1 = s.length()-i;
      if (br)
        ans1*=(long long)(i-n-last+1);
      ans += ans1;
      last = i-n+1;
      br = 0;
    }
  }
  return ans;
}

int main () {
  int T; cin >> T;
  for (int i=1; i<=T; i++) {
    cout << "Case #" << i << ": " << run() << endl;
  }
  return 0;
}
