#include <set>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

inline int getRotated(int n, int k) {
  char tmp[9];
  char val[9];
  int len;

  sprintf(tmp, "%d", n);
  len = strlen(tmp);

  for (int i = 0; i < len; i++) {
    val[i] = tmp[(i+k)%len];
  }
  
  val[len] = '\0';

  return atoi(val);
}

int main(int argc, char **argv) {
  int T;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    string Astr, Bstr;
    int A, B, n_digits;
    set <int> cover;
    long n_pairs = 0;

    cout << "Case #" << i << ": ";
    
    cin >> Astr >> Bstr;
    A = atoi(Astr.c_str());
    B = atoi(Bstr.c_str());
    n_digits = Astr.size();

    for (int n = A; n <= B; n++) {
      
      if (cover.find(n) == cover.end()) {
	set <int> unique;
	unique.insert(n);
	cover.insert(n);

	for (int k = 1; k < n_digits; k++) {
	  int m = getRotated(n, k);
	
	  if (m >= A && m <= B && unique.find(m) == unique.end()) {
	    unique.insert(m);
	    cover.insert(m);
	  }
	}

	int nu = unique.size();
	n_pairs += ((nu-1)*nu)/2;
      }
    }
    
    cout << n_pairs << endl;
  }

  return 0;
}
