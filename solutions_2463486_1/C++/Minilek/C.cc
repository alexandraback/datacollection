#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <sstream>
#include <stdlib.h>
using namespace std;

char is_pal(long long n) {
  string num1, num2;
  ostringstream c;
  c << n;
  num1 = c.str();
  num2 = num1;
  reverse(num2.begin(), num2.end());
  return num1 == num2;
}

int main(int argc, char* argv[]) {
  vector<long long> fas;
  for (int i = 1; i <= 3; ++i)
    fas.push_back(i*i);
  for (int i = 1; i <= 9999; ++i) {
    string a, num1, num2;
    ostringstream c;
    c << i;
    num1 = c.str();
    num2 = num1;
    reverse(num2.begin(), num2.end());
    string pos[11] = {"", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
    for (int j = 0; j < 11; ++j) {
      if (i>=1000 && j) break;
      a = num1 + pos[j] + num2;
      long long x = 0, p10 = 1;
      for (int k = a.size()-1; k>=0; k--, p10*=10)
	x += (a[k]-'0')*p10;
      long long y = x * x;
      if (is_pal(y))
	fas.push_back(y);
    }
  }
  int nocases;
  cin >> nocases;
  for (int rr = 1; rr <= nocases; ++rr) {
    int cnt = 0;
    long long a, b;
    cin >> a >> b;
    for (int i = 0; i < fas.size(); ++i)
      if (fas[i]>=a && fas[i]<=b)
	++cnt;
    printf("Case #%d: %d\n", rr, cnt);
  }
  return 0;
}
