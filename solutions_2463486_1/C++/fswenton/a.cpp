#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <cmath>
// #include "Rational.h"

// !!! Don't forget to canonicalize() Rational's after input!
#include <gmpxx.h>
#include <gmp.h>
#define Integer mpz_class
#define Rational mpq_class
#define Float mpf_class

using namespace std;

bool debug = true;

int main(void) {
  int iTest, nTests; cin >> nTests;

  set<Integer> squares;

  Integer i(1), iMax(1000000);
  for (; i <= iMax; ++i) {
    string s0 = i.get_str(), s;
    int j, n = s.length();
    
    {
      s = s0;
      s += s0;
      for (j = 0; j < n; ++j)
	s[n+j] += s[n-1 - j];
      Integer base(s);
      
      Integer square = base*base;
      string sSquare = square.get_str();
      int k, n2 = sSquare.length();
      for (k = 0; k < n2/2; ++k)
	if (sSquare[k] != sSquare[n2-1 - k])
	  break;
      if (k >= n2/2) {
	squares.insert(square);
	if (debug)
	  cerr << i << ": " << base << "^2 = " << sSquare << "\n";
      }
    }

    {
      s = s0;
      s += s0.substr(1);
      for (j = 0; j < n-1; ++j)
	s[n+j] += s[n-2 - j];
      Integer base(s);
      
      Integer square = base*base;
      string sSquare = square.get_str();
      int k, n2 = sSquare.length();
      for (k = 0; k < n2/2; ++k)
	if (sSquare[k] != sSquare[n2-1 - k])
	  break;
      if (k >= n2/2) {
	squares.insert(square);
	if (debug)
	  cerr << i << ": " << base << "^2 = " << sSquare << "\n";
      }
    }

  }

  for (iTest = 1; iTest <= nTests; ++iTest) {
    cerr << iTest << "/" << nTests << "\n";

    Integer A, B;
    cin >> A >> B;

    cout << "Case #" << iTest << ": ";
    
    Integer count(0);
    set<Integer>::iterator it;
    for (it = squares.begin(); it != squares.end(); ++it)
      if (*it >= A && *it <= B)
	++count;
      else if (*it > B) 
	break;

      cout << count;
    
    cout << "\n";
  }

  return 0;
}
