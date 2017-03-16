//mishraiiit
#include<bits/stdc++.h>
#define ll long long int
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
typedef pair <ll, ll> pll;

#ifdef TRACE
  #include "trace.h"
#else
  #define trace1(x)
  #define trace2(x, y)
  #define trace3(x, y, z)
  #define trace4(a, b, c, d)
  #define trace5(a, b, c, d, e)
  #define trace6(a, b, c, d, e, f)
#endif

set<int> F, S;

int convert(string & s) {
  return stoi(s);
}

void populate(set<int> & SET, string str) {
  if(str.size() == 1) {
    for(int i = 0; i < 10; i++) {
      string t = str;
      if(str[0] == '?') t[0] = '0' + i;
      SET.insert(convert(t));
    }
  } else if(str.size() == 2) {
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < 10; j++) {
        string t = str;
        if(str[0] == '?') t[0] = '0' + i;
        if(str[1] == '?') t[1] = '0' + j;
        SET.insert(convert(t));
      }
    }
  } else {
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < 10; j++) {
        for(int k = 0; k < 10; k++) {
          string t = str;
          if(str[0] == '?') t[0] = '0' + i;
          if(str[1] == '?') t[1] = '0' + j;
          if(str[2] == '?') t[2] = '0' + k;
          SET.insert(convert(t));
        }
      }
    }
  }
}

pair<int, int> check(pair<int, int> A, pair<int, int> B) {
  if(abs(A.first - A.second) == abs(B.first - B.second) ) {
    if(A.first < B.first) {
      return A;
    } else if(A.first > B.first) {
      return B;
    } else {
      if(A.second < B.second) return A;
      else return B;
    }
  } else if(abs(A.first - A.second) < abs(B.first - B.second) ) {
    return A;
  } else {
    return B;
  }
}

string toString(int n) {
  if(n < 0) return "-" + toString(-n);
  if(n == 0) return "0";
  vector<char> s;
  while(n != 0) {
    s.push_back('0' + (n % 10));
    n = n / 10;
  }
  return string(s.rbegin(), s.rend());
}



string makeOk(int len, int num) {
  string str = toString(num);
  assert(len >= str.size());
  if(len > str.size())
    return string(len - str.size(), '0') + str;
  return str;
}

int main() {
    fastScan;
    int t;
    cin >> t;
    for(int ii = 1; ii <= t; ii++) {
        F.clear(); S.clear();
        string s, t;
        cin >> s >> t;
        int len = s.size();
        populate(F, s);
        populate(S, t);
        pair<int, int> ans = { *F.begin(), *S.begin()};
        for(auto x : F) {
          for(auto y : S) {
            ans = check(ans, make_pair(x, y));
          }
        }
        cout << "Case #" << ii << ": ";
        cout << makeOk(len, ans.first) << " " << makeOk(len, ans.second) << endl;
    }

    return 0;
}
