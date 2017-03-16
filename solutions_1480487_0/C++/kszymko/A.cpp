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

#define EPS 1E-9

int T, N, X;
int S[202];

bool can(double L) {
  double have = X;
  REP(i,N) if (S[i] < L) {
    have -= (L - S[i]);
    //cout << "* ";
  }
  //cout << have << endl;
  return have > 0;
}

int main(int argc, char *argv[]) {
  cerr.precision(15);
  cout.precision(15);

  scanf("%d\n",&T);
  REP(testcase,T) {
    scanf("%d ",&N); 
    X = 0;
    double a = 0.0, b = 0.0;
    REP(i,N) {
      scanf("%d ",&S[i]);
      X += S[i];
      a = min(a, (double)S[i]);
      b = max(b, (double)S[i]);
    } b = X;  
    
    double L; int cnt = 0;
    while (b-a > EPS) {
      L = (a + b) / 2.0;
      //cout << a << " " << b << " L: " << L << endl;      
      if (can(L)) {
        a = L;        
      } else {
        b = L;
      }
      
      //cnt++;
      //if (cnt > 1) break;
    }    
    
    printf("Case #%d: ",testcase+1);   
    REP(i,N) {         
      printf("%.6f ", (S[i] >= L) ? 0.0 : (100.0 * (L - S[i])) / X);
    } printf("\n");   
  }

  return 0;
}