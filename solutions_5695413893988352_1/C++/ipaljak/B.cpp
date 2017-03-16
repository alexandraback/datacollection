#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

#define fst first
#define snd second

typedef long long llint;
typedef pair<int, int> pii;

const int B = 27397, MOD = 1e9 + 7;
const int B1 = 33941, MOD1 = 1e9 + 9;

int T; 

string s1, s2;

int diff() {
  llint a = 0, b = 0;
  for (int i = 0; i < s1.length(); ++i) {
    a *= 10LL; a += (llint) (s1[i] - '0');
    b *= 10LL; b += (llint) (s2[i] - '0');
  }
  return abs(a - b); 
}

void finish(int ptr, bool less) {
  for (int i = ptr; i < s1.length(); ++i) {
    if (s1[i] == '?') 
      if (less) s1[i] = '9'; else s1[i] = '0';
    if (s2[i] == '?')
      if (less) s2[i] = '0'; else s2[i] = '9';
  }
}

void solve(int t) {
  
  cin >> s1; 
  cin >> s2; 

  string tmp_s1 = s1;
  string tmp_s2 = s2;

  string sol1, sol2; 
  llint min_diff = (llint) 1000000000 * 1000000000; 

  for (int i = 0; i < s1.length(); ++i) {

    if (s1[i] != s2[i] && s1[i] != '?' && s2[i] != '?') {
      finish(i + 1, s1[i] < s2[i]);
      if (diff() == min_diff) {
        if (s1 < sol1 || (s1 == sol1 && s2 < sol2)) {
          sol1 = s1; sol2 = s2;
        }
      }
      if (diff() < min_diff) {
        min_diff = diff();
        sol1 = s1; sol2 = s2;
      }
      break; 
    }

    if (s1[i] != '?' && s2[i] != '?') {
      if (i == s1.length() - 1) {
        sol1 = s1; 
        sol2 = s2;
      }
      continue; 
    }

    for (int j = 0; j < 10; ++j) {
      for (int k = 0; k < 10; ++k) {
        
        if (j == k) continue;
        if (s1[i] == '?') s1[i] = j + '0';
        if (s2[i] == '?') s2[i] = k + '0';

        finish(i + 1, s1[i] < s2[i]);
        if (diff() == min_diff) {
          if (s1 < sol1 || (s1 == sol1 && s2 < sol2)) {
            sol1 = s1; sol2 = s2;
          }
        }
        if (diff() < min_diff) {
          min_diff = diff();
          sol1 = s1; sol2 = s2;
        }

        s1 = tmp_s1; s2 = tmp_s2; 

      }
    }


    if (s1[i] != '?') s2[i] = s1[i];
    if (s2[i] != '?') s1[i] = s2[i];

    if (s1[i] == '?') s1[i] = s2[i] = '0';
    tmp_s1 = s1; tmp_s2 = s2; 

    if (i == s1.length() - 1) {
      sol1 = s1; sol2 = s2;
    }

  }

  printf("Case #%d: ", t);
  cout << sol1 << " " << sol2 << endl;

}

int main(void) {

  scanf("%d", &T);
  for (int t = 0; t < T; ++t) 
    solve(t + 1);  

  return 0;

}

