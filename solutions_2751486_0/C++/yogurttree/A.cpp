#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

bool is_cons (char c) {
  assert(isalpha(c));
  if (isupper(c))
    c = tolower(c);
  switch (c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      return false;
    default:
      return true;
  }
}

bool isokay (char *str, int len, int thresh) {
  int numcons = 0;
  for (int i=0; i<len; i++) {
    char ch = str[i];
    if (is_cons(ch)) {
      numcons += 1;
    } else {
      numcons = 0;
    }
    if (numcons >= thresh) return true;
  }
  return false;
}

int main () {
  int T;
  cin >> T;

  for (int i=0; i<T; i++) {
    char name[10000];
    int consec[10000];
    scanf ("%s", name);
    int L;
    cin >> L;
    int len = strlen (name);
    int nvalue = 0;

    for (int ii=0; ii<len; ii++) {
      for (int j=ii+1; j<=len; j++) {
        if (isokay (name + ii, j-ii, L))
          nvalue += 1;
      }
    }


    cout << "Case #" << (i+1) << ": " << nvalue << endl;
  }

  return 0;
}
