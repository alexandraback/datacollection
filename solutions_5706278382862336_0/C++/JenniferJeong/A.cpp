#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

long long int gcd(long long int a, long long int b) {
  long long int c = a % b;

  while(c) {
    a = b;
    b = c;
    c = a % b;
  }

  return b;
}

int main() {

  int TC;
  string str;
  long long int a, b;

  cin >> TC;
  for (int tc = 1; tc <= TC; tc++) {
    long long int answer = 0;
    long long int gcdval = 0;
    
    a = b = 0;

    cin >> str;
    int pos = str.find("/");

    for (int i = 0; i < pos; i++) {
      a *= 10;
      a += (str[i] - '0');
    }

    int sz = (int)str.size();
    for (int i = pos+1; i < sz; i++) {
      b *= 10;
      b += (str[i] - '0');
    }

    for (int i = 1; i <= 40; i++) {
      a *= 2;
      gcdval = gcd(a, b);
      a /= gcdval;
      b /= gcdval;

      if ( (double)a/b >= 1) {
	a -= b;
	if (answer == 0) answer = i;
	if (a == 0) break;
      }
    }

    if ( answer && ((a == 1 && b == 1) || (a == 0)) ) {
      printf("Case #%d: %lld\n", tc, answer);
    } else {
      printf("Case #%d: impossible\n", tc); 
    }
  }
  
}
