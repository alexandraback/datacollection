#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream in("data.in");
ofstream out("data.out");

long long gcd(long long a, long long b) {
  long long r;
  while (b!=0) {
    r = a%b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  int T;
  in >> T;
  for (int curcase = 1; curcase <= T; curcase++) {
    long long P=0,Q=0;
    string s;
    in >> s;
    bool denom=false;
    for (int i=0; i<s.size(); i++) {
      if (s[i] == '/') {
	denom = true;
      } else if (denom) {
	Q *= 10;
	Q += int(s[i] - '0');
      } else {
	P *= 10;
	P += int(s[i] - '0');
      }
    }

    long long d = gcd(P,Q);
    P /= d;
    Q /= d;

    int k=0;
    long long x=1;
    while (x < Q) {
      k++;
      x*=2;
    }
    
    out << "Case #" << curcase << ": ";

    if (Q != x) {
      out << "impossible" << endl;
      continue;
    }

    int j=1;
    long long y=x/2;
    while (P < y) {
      j++;
      y/=2;
    }

    out << j << endl;    
  }
}
