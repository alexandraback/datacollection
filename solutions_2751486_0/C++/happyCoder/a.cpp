#include <string>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef unsigned long long ullong;
typedef unsigned long ulong;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef long long llong;

void solve() {
  string str;
  int n;
  cin >> str;
  cin >> n;
  int con = 0;
  int len = str.length();
  int last = 0;
  ullong nval = 0;
  for (int i = 0; i < len; ++i) {
    switch (str[i]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
	/*if (con >= n) {
	  nval += (i-n+1-last)*(len-i+1);
	  last = i-n+1;
	}*/
	con = 0;
	break;
      default:
	++con;
	if (con >= n) {
	  nval += (i-n+2-last)*(len-i);
	  last = i-n+2;
	}
	break;
    }
  }
  if (con >= n) {
    nval += (len-n+1-last)*1;
  }
  cout << nval << endl;
}

int main() {
  int nc;
  cin >> nc;
  for (int i = 1; i <= nc; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
