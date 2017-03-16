#include <set>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int getRotated(int n, int k) {
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
    set <double> cover;
    int n_pairs = 0;

    cout << "Case #" << i << ": ";
    
    cin >> Astr >> Bstr;
    A = atoi(Astr.c_str());
    B = atoi(Bstr.c_str());
    n_digits = Astr.size();

    for (int n = A; n < B; n++) {

      if (cover.find(n) == cover.end()) {
	
	for (int k = 1; k < n_digits; k++) {
	  int m = getRotated(n, k);

	  if (m > A && m <= B && n < m) {
	    int key = m*B+n;

	    if (cover.find(key) == cover.end()) {
	      cover.insert(key);
	      n_pairs++;
	    }
	  }
	}
      }
    }
    
    cout << n_pairs << endl;
  }

  return 0;
}
