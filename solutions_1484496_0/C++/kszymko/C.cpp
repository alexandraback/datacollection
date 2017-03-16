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

string i2bs (unsigned long long n, long b=64) {
  string res = "0000000000000000000000000000000000000000000000000000000000000000";
  int c = b; --b;
  while (n) {res[b] += (n&1); --b; n >>= 1;}
  return res.substr(0,c);
}

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

int T, N;
Int S[505];
vector<int> SUM[2000000];

int main(int argc, char *argv[]) {
  cerr.precision(15);
  cout.precision(15);

  scanf("%d\n",&T);
  REP(testcase,T) {
    scanf("%d",&N);
    Int UL = 0;    
    REP(i,2000000) {
      SUM[i].clear();
    }
    
    REP(i,N) {
      cin >> S[i];
      UL += S[i];
    }   

    bool found = false;   
    for(int maskA = 1; maskA < (1<<N); maskA++) { 
      int zum = 0;      
      for (int i = 0; i < N; i++) {
        if ((maskA & (1 << i)) > 0) {
          zum += S[i];
        }
      }      
        FORU(it,SUM[zum].begin(),SUM[zum].end()) {
          //cout << i2bs(*it) << " " << i2bs(maskA) << endl;
          if (((*it) & maskA) == 0) {
            found = true;
            printf("Case #%d: \n",testcase+1);
            
            for (int i = 0; i < N; i++) {
              if (((*it) & (1 << i)) > 0) {
                cout << S[i] << " ";
              }
            } cout << endl;             
                        
            for (int i = 0; i < N; i++) {
              if ((maskA & (1 << i)) > 0) {
                cout << S[i] << " ";
              }
            } cout << endl;  
            
          }
        }      
      SUM[zum].PB(maskA);  
      if (found) break;
    }      

    if (!found) printf("Case #%d: Impossible\n",testcase+1);     
  }

  return 0;
}