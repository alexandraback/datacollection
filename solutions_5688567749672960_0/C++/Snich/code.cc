#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl; 

long long mpow(long long a, int b) {
  long long c = 1;
  while (b) {
    if (b & 1) c *= a;
    a *= a;
    b >>= 1;
  }
  return c;
}

int len(long long x) {
  return to_string(x).length();
}

long long calc(long long n) {
  if (len(n) == 1) return n; 

  if (n % 10 == 0) return calc(n - 1) + 1;

  long long ret = 10;
  long long k = 10;
  while (len(k) < len(n)) {
    long long z = mpow(10, (len(k) + 1) / 2);
    ret += z;
    z = mpow(10, len(k) / 2);
    ret += z - 1;
    k *= 10;
  }

  string s = to_string(n);

  string first_half = s.substr(0, s.length() / 2);
  string second_half = s.substr(s.length() / 2, string::npos);
  reverse(first_half.begin(), first_half.end());
  //dbg(first_half);
  //dbg(second_half)
  //dbg(ret)
  long long fh = stol(first_half), sh = stol(second_half);
  //dbg(fh);
  //dbg(sh)
  ret += sh + fh;
  if (stol(s.substr(0, s.length() / 2)) == mpow(10, s.length() / 2 - 1)) --ret;
  //dbg(first_half);
  //dbg(s.length() / 2);
  return ret;
}


int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": ";
        
        long long n;

        cin >> n;
        cout << calc(n);

        cout << endl;
    }
    return 0;
}
