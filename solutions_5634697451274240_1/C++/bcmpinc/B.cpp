#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>

using namespace std;

void dostep() {
  char buf[128];
  cin >> buf;
  int flips = 0;
  char *c=buf;
  if (*c=='-') {
    flips++;
    while(*c=='-') c++;
  }
  for(; *c; c++) {
    if (*c=='-') {
      flips+=2;
      while(*c=='-') c++;
    }
  }
  cout << flips << endl;
}

int main() {
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    cout << "Case #" << i << ": ";
    dostep();
  }
  return 0;
}
 
