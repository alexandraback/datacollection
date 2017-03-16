//this is the default for Google code jam only
#include <string>
#include <vector>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

#define pii pair<int, int>

using namespace std;

ifstream fi("A-small-attempt0.in");
//ifstream fi("A-large.in");
//ifstream fi("sample.in");
ofstream fo("sample.out");

int test;
int f[27];
string code[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", 
		  "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		  "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string language[3] = {"our language is impossible to understand", 
		      "there are twenty six factorial possibilities", 
		      "so it is okay if you want to just give up"};

void prepare();
void solve();

int main() {
  int ntest;
  fi >> ntest;
  string s;
  getline(fi, s);
  prepare();
  for (test = 1; test <= ntest; test ++) {
    solve();
  }
  fi.close();
  fo.close();
  return 0;
}

void prepare() {
  for (int i = 0; i < 3; i ++)
    for (int j = 0; j < code[i].length(); j ++) 
      if (code[i][j] != ' ')
	f[code[i][j] - 'a' + 1] = language[i][j] - 'a' + 1;
  f[26] = 17;
  f[17] = 26;
  for (int i = 1; i <= 26; i ++)
    cout << i << " " << f[i] << endl;
  
}

void solve() {
  //start code here
  string s;
  
  getline(fi, s);
  for (int i = 0; i < s.length(); i ++)
    if (s[i] != ' ')
      s[i] = 'a' + f[s[i] - 'a' + 1] - 1;
  fo << "Case #" << test << ": " << s << endl;
}
