#ifndef INCLUDES

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <unistd.h>
#include <utility>
#include <vector>
using namespace std;

#endif

#ifndef MACROS

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define SZ(c) ((int)(c).size())
#define CLR(c,v) memset(c, v, sizeof(c))
#define REP(i,e) for(int i = 0; i < (signed)(e); ++i)
#define REPS(i,c) for(int i = 0; i < (int) (c).size(); ++i)
#define FORU(i,b,e) for(__typeof(b) i = (b); i != (e); ++i)
#define FORD(i,b,e) for(__typeof(b) i = (b); i != (e); --i)
#define FORC(i,c) FORU(i,c.begin(),c.end())
typedef vector<int> vi; typedef long long Int;

#endif

#ifndef TOOLS

template <class T> T s2t(string s) {istringstream i(s); T x; i>>x; return x;}
template <class T> string t2s(T x) {ostringstream o; o << x; return o.str();}

vector<string> split (string s, string del = " ") { vector<string> res;
  int ss = s.size(), sdel = del.size();
  for (int p = 0, q; p < ss; p = q+sdel) {
    if ((q = s.find(del, p)) == (signed)string::npos) q = ss;
    if (q-p>0) res.push_back(s.substr(p,q-p));
  } return res;
}

vector<int> splitInts (string s, string del = " ") { vector<int> res;
  vector<string> t = split(s,del);
  for (int i = 0; i < t.size(); ++i) {
    if (t[i].size() > 10 || (t[i].size()==10 && t[i][0]>='2')) {
      res.push_back(2000000000);
    } else { res.push_back(atoi(t[i].c_str())); }
  } return res;
}

#endif

int C, BT, TT;
vector< pair<Int, int> > B;
vector< pair<Int, int> > T;
Int num; int type;
Int maxBoxed;
Int memo[101][101];

Int go(int iB, Int atB, int iT, Int atT) { 
  if (iB >= BT) return 0;
  if (iT >= TT) return 0;
  
  // cout << iB << "(" << atB << ")" << " " << iT << "(" << atT << ")" << endl;
  
  if (atB == 0 && atT == 0) {
    if (memo[iB][iT] != -1) return memo[iB][iT];
  }
  
  Int result = 0;
  
  if (B[iB].ND == T[iT].ND) {    
    Int match = min(B[iB].ST - atB, T[iT].ST - atT);
    result += match;
    atB += match;
    atT += match;
  }

  // throw out the box type
  
  Int resultBT = result + go(iB+1, 0, iT, atT);
  
  // throw out the toy type

  Int resultTT = result + go(iB, atB, iT+1, 0); 
  
  if (atB == 0 && atT == 0) {
    memo[iB][iT] = max(resultBT, resultTT);
  }
  
  return max(resultBT, resultTT);
}

int main(int argc, char *argv[]) {
  cerr.precision(15);
  cout.precision(15);

  scanf("%d\n",&C);
  REP(testcase,C) {
    scanf("%d %d\n",&BT,&TT); 
    B.clear();
    T.clear();
    CLR(memo, -1);
    
    REP(i,BT) {
      cin >> num >> type;
      B.PB(MP(num,type));
    }
    REP(i,TT) {
      cin >> num >> type;
      T.PB(MP(num,type));
    }
    
    maxBoxed = 0LL;
    maxBoxed = go(0, 0LL, 0, 0LL);
    
    solution:
    printf("Case #%d: ",testcase+1);
    cout << maxBoxed << endl;    
  }

  return 0;
}