#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <inttypes.h>

using namespace std;

#define foreach(c, i) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

string encrypted =
    "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
string original =
    "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

map<char, char> decryptDict;

void PreSolve() {
  for (int i = 0; i < encrypted.length(); i++) {
    decryptDict[encrypted[i]] = original[i];
  }
  decryptDict['z'] = 'q';
  decryptDict['q'] = 'z';
}

struct Problem {
  char S[256];

  void Input() {
    gets(S);
  }

  void Solve() {
    string res = "";
    string s = S;
    for (int i = 0; i < s.length(); i++) {
      res += decryptDict[s[i]];
    }
    printf("%s", res.c_str());
  }

}; // struct Problem


int main() {
  int T;
  scanf("%d\n", &T);
  PreSolve();
  for (int testCase = 1; testCase <= T; ++testCase) {
    printf("Case #%d: ", testCase);
    Problem p;
    p.Input();
    p.Solve();
    printf("\n");
  }

  return 0;
}
