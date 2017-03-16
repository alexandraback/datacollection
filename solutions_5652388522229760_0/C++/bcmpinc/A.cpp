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
  int n;
  cin >> n;
  bool a[15]={};
  int todo=10;
  for (int i=1; i<100; i++) {
    int val = i*n;
    while (val) {
      int digit = val % 10;
      val /= 10;
      if (!a[digit]) {
        a[digit] = true;
        todo--;
      }
    }    
    if (todo==0) {
      cout << i*n << endl;
      return;
    }
  }
  cout << "INSOMNIA" << endl;
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
 
