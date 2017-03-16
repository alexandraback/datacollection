#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SZ(a) ((int)((a).size()))
#define REPSZ(i,v) REP(i,SZ(v))
#define ALL(a) (a).begin(),(a).end()
typedef long long Int;

string in = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
string out = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

int main() {
  int conv[256] = {};
  REPSZ(i, in) conv[ (int)in[i] ] = out[i];

  conv['q'] = 'z';
  conv['z'] = 'q';
  
  int TNO; scanf("%d\n", &TNO);
  for(int tno = 1; tno <= TNO; tno++) {
      printf("Case #%d: ", tno);
      string line; getline(cin, line);
      REPSZ(i, line) cout << (char)conv[line[i]]; cout << endl;
  }
  return 0;
}
