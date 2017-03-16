
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define ALLOF(s) ((s).begin()), ((s).end())

typedef long long integer;

char table[30] = "yhesocvxduiglbkrztnwjpfmaq";

int main(void) {
  int nCases;
  cin >> nCases;
  string s;
  getline(cin, s);
  REP(iCase, nCases) {
    getline(cin, s);
    REP(i, s.size()){
      if(isalpha(s[i])){
	s[i] = table[s[i]-'a'];
      }
    }
    
    cout << "Case #" << (iCase+1) << ": " << s << endl;
  }
  
  return 0;
}
