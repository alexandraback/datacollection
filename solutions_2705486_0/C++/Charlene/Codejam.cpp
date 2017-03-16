//
//  Codejam.cpp
//  Topcoder
//
//  Created by Charlene Jiang on 4/27/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> II;
typedef long long LL;
#define FOR(i,b,e) for(int (i)=(int)b;(i)<(int)(e);++(i))
#define FORIT(it,c) for(typedef((c).begin()) it=(c).begin();it!=(c).end();++it)
#define INF 987654321


vector<string> words;
int f[100][100];
bool caled[100][100];
string S;

void globalinit()
{
  ifstream fin("/Users/yingjiang/TopCoder/Codejam/2C.in.txt");
  string line;
  while (fin >> line)
  {
    words.push_back(line);
  }
  
//  cout << words.size() << endl;
}

void init()
{
  memset(caled, false, sizeof(caled));
  cin >> S;
}

int isOK(const string& word, int& lastDiff, int off)
{
  if (off + word.length() - 1 >= S.length()) return -1;
  int ret = 0;
  
  for (int i = 0; i < word.length(); ++i)
  {
    if (word[i] != S[off + i])
    {
      int nowdiff = off + i;
      if (nowdiff - lastDiff < 5 && lastDiff != -1) return -1;
      ret++;
      lastDiff = nowdiff;
    }
  }
  return ret;
}

int getF(int off, int last)
{
  if (caled[off][last + 1]) return f[off][last + 1];
  caled[off][last + 1] = true;
  int & ret = f[off][last + 1];
  
  if (off == S.length()) return ret = 0;
  ret = 999999;
  for (int i = 0; i < words.size(); ++i)
  {
    int lastDiff = last;
    int r = (isOK(words[i], lastDiff, off));
    if (r >= 0)
      ret = min(ret, r + getF(off + (int) words[i].length(), lastDiff));
  }
  return ret;
}

string deal()
{
  int ans = getF(0, -1);
  ostringstream ostr;
  ostr << ans;
  return ostr.str();
}

int main()
{
  freopen("/Users/yingjiang/Downloads/C-small-attempt1.in.txt", "r", stdin);
  freopen("/Users/yingjiang/TopCoder/Codejam/2C.out.txt", "w", stdout);
  globalinit();
  
  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test)
  {
    init();
    cout << "Case #" << test << ": " << deal() << endl;
  }
  return 0;
}

