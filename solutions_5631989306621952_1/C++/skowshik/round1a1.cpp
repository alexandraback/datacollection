#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <math.h>

using namespace std;

void lastword(int t, string s){
  string outp;
  for (int i = 0; i < s.length(); i++) {
    string temp1, temp2;
    temp1 += s[i];
    temp1 += outp;
    temp2 += outp;
    temp2 += s[i];

    if (temp1 < temp2) {
      outp = temp2;
    } else {
      outp = temp1;
    }
    
  }

  cout << "Case #" << t << ": ";
  cout << outp << endl;
}


int main() {
  int t;
  string s;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cin >> s;
    lastword(i, s);
  }
}
