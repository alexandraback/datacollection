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

int n,j;

int test_one(int val, int base, int mod) {
  int r=0;
  int dec=1;
  for (int d=1; d<n; d++) {
    if (val%2) r += dec;
    dec = (dec*base) % mod;
    val/=2;
  }
  r+=dec;
  return r % mod;
}

int test(int val, int base) {
  if (test_one(val, base, 2) == 0) return 2;
  if (test_one(val, base, 3) == 0) return 3;
  if (test_one(val, base, 5) == 0) return 5;
  if (test_one(val, base, 7) == 0) return 7;
  if (test_one(val, base, 11) == 0) return 11;
  if (test_one(val, base, 13) == 0) return 13;
  return 0;
}

void convert(char* buf, int val) {
  buf[0]='1';
  for (int c=1; c<n; c++) buf[c] = '0';
  int c=n-1;
  while (val) {
    if (val % 2) buf[c] = '1';
    c--;
    val /= 2;
  }
  buf[n]=0;
}

void dostep() {
  cin >> n >> j;
  int a[15];
  char buf[64];
    
  // for each binary number 100..001 of length n without the leading digit.
  for (int val=1; j>0; val+=2) {
    // Find divisors
    for (int base=2; base<=10; base++) {
      a[base] = test(val, base);
      if (a[base]==0) goto next;
    }
    // Convert number to string
    convert(buf, val);
    // Output jamcoin
    cout << buf;
    for (int base=2; base<=10; base++) {
      cout << ' ' << a[base];
    }
    cout << endl;
    j--;
    // jump here if not a jam-coin.
    next:;
  }
}

int main() {
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    cout << "Case #" << i << ": " << endl;
    dostep();
  }
  return 0;
}
 
