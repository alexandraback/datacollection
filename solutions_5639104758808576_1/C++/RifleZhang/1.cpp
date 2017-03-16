#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
using namespace std;

void solve (int tmp) {
  int n, len, now=0, tot = 0;
  string s;
  cin >> n >> s;
  len = s.size();
  for (int i=0; i<len; i++) {
    if ( s[i] == 0 ) continue;
    if ( i > now ) {tot += i-now; now += i-now;}
    now += s[i] - '0';
  }
  cout << "Case #" << tmp << ": " << tot << endl; 
}
int main () {
  
  int t, tmp = 0;
  cin >> t;
  while (t) {
    t--;
    tmp++;
    solve (tmp);
  }
}
