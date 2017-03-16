/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

// define strategy

string flip(int n, string s1) {
  string s2 = s1;
  for (int i = 0; i < n; i++) {
    s2[i] = s1[n-i-1] == '+' ? '-' : '+';
  }
  return s2; 
}

int f(string s) {
  int n = s.size();
  if (s.size() == 0) return 0;
  if (s[n-1] == '+') return f(s.substr(0, n - 1));
  if (s[0] == '-') return 1 + f(flip(n, s));
  int m = 0;
  while(s[m] == '+') { m++;}
  return 1 + f(flip(m, s));
}

int main()
{
  assert(flip(4, "++++") == "----"); 
  assert(flip(4, "----") == "++++"); 
  assert(flip(3, "----") == "+++-"); 
  assert(flip(2, "-+") == "-+"); 

  assert(f("") == 0);
  assert(f("+") == 0);
  assert(f("+++++++") == 0);
  assert(f("-") == 1);
  assert(f("-+") == 1);
  assert(f("+-") == 2);
  assert(f("--+-") == 3);
  assert(f("+++-") == 2);
  
  int N;
  string s;
  cin >> N;

  for(int i = 1; i<= N ; i++) {
    cin >> s;
    int res = f(s);
    printf("Case #%d: %d\n", i, res);
  }
}
