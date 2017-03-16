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
using namespace std;

int main(int argc, char* argv[]) {
  string A = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
  string B = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
  char M[300];
  memset(M, 0, sizeof(M));
  M[' '] = ' ';
  M['q'] = 'z';
  M['z'] = 'q';
  for (int i = 0; i < A.size(); ++i)
    M[A[i]] = B[i];
  int nocases;
  cin >> nocases;
  getchar();
  for (int rr = 1; rr <= nocases; ++rr) {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i)
      s[i] = M[s[i]];
    printf("Case #%d: %s\n", rr, s.c_str());
  }
  return 0;
}
