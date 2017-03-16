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

string s;

// 0,1,2,3 are 1,i,j,k
inline pair<int, int> mul(pair<int, int> x, pair<int, int> y) { 
  pair<int, int> ret = make_pair(0, 0);
  int a = x.second, b = y.second;
  if (a == 0)
    ret.first = 1, ret.second = b;
  else if (a == 1) {
    if (b == 0)
      ret.first = 1, ret.second = 1;
    else if (b == 1)
      ret.first = -1, ret.second = 0;
    else if (b == 2)
      ret.first = 1, ret.second = 3;
    else if (b == 3)
      ret.first = -1, ret.second = 2;
  } else if (a == 2) {
    if (b == 0)
      ret.first = 1, ret.second = 2;
    else if (b == 1)
      ret.first = -1, ret.second = 3;
    else if (b == 2)
      ret.first = -1, ret.second = 0;
    else if (b == 3)
      ret.first = 1, ret.second = 1;
  } else if (a == 3) {
    if (b == 0)
      ret.first = 1, ret.second = 3;
    else if (b == 1)
      ret.first = 1, ret.second = 2;
    else if (b == 2)
      ret.first = -1, ret.second = 1;
    else if (b == 3)
      ret.first = -1, ret.second = 0;
  }
  ret.first *= x.first * y.first;
  return ret;
}

inline pair<int,int> convert(char c) { return make_pair(1, c-'i'+1); }

int main(int argc, char* argv[]) {
  int nocases;
  cin >> nocases;
  getchar();
  for (int rr = 1; rr <= nocases; ++rr) {
    long long L, X;
    cin >> L >> X >> s;
    string t = s;
    long long left = X - 1;

    while (left && (s.size() < 650001)) {
      left--;
      s += t;
    }

    bool bad = false;

    pair<int, int> cur = make_pair(1, 0), cur2;
    int at = 0, sign;
    while (at<s.size()) {
      cur = mul(cur, convert(s[at++]));
      if (cur.first==1 && cur.second==1)
	break;
    }
    if (at==s.size()) {
      bad = true;
      goto done;
    }

    cur = make_pair(1, 0);
    while (at<s.size()) {
      cur = mul(cur, convert(s[at++]));
      if (cur.first==1 && cur.second==2)
	break;
    }
    if (at==s.size()) {
      bad = true;
      goto done;
    }

    cur = make_pair(1, 0);
    while (at<s.size())
      cur = mul(cur, convert(s[at++]));
    
    cur2 = make_pair(1, 0);
    for (int i = 0; i < t.size(); ++i)
      cur2 = mul(cur2, convert(t[i]));
    sign = cur2.first;
    cur2.first = 1;
    if (left%4 == 2)
      cur2 = make_pair(-1, 0);
    else if (left%4 == 3)
      cur2.first = -1;
    else if (left%4 == 0)
      cur2 = make_pair(1, 0);
    if (left%2 == 0)
      sign = 1;
    cur2.first *= sign;
    
    cur = mul(cur, cur2);
    if (cur.first!=1 || cur.second!=3)
      bad = true;

  done:  
    printf("Case #%d: %s\n", rr, bad ? "NO" : "YES");
  }
  return 0;
}
