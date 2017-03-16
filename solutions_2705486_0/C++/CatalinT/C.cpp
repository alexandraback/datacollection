/*
 Catalin-Stefan Tiseanu
 
 Pre-written code is assembled from various sources found online.
 Big thanks to the community for that !
 */

// Pre-written code below

using namespace std;

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
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define DEBUG

#ifdef DEBUG
#define debug(args...)            {dbg,args; cerr<<endl;}
#else
#define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
  template<typename T> debugger& operator , (const T& v)
  {
  cerr<<v<<" ";
  return *this;
  }
} dbg;

// templates
template<typename T> int size(const T& c) { return int(c.size()); }
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }
template<typename T> bool remin(T& x, T y) { if (x <= y) return false; x = y; return true; }
template<typename T> bool remax(T& x, T y) { if (x >= y) return false; x = y; return true; }

// misc
#define EPSILON              1e-7

// types
typedef long long            int64;
typedef unsigned long long   uint64;

// shortcuts
#define all(_xx)             _xx.begin(), _xx.end()

#define pb                   push_back
#define vi                   vector<int>
#define vpii                 vector<pair<int,int> >
#define vpdd                 vector<paid<double,double> >

#define pii                  pair<int,int>
#define pdd                  pair<double, double>
#define mp(XX, YY)           make_pair(XX, YY)
#define fi                   first
#define se                   second

#define ll                   long long
#define SS                   stringstream

// for loops
#define re(II, NN)           for (int II(0), _NN(NN); (II) < (_NN); ++(II))
#define fod(II, XX, YY)      for (int II(XX), _YY(YY); (II) >= (_YY); --(II))
#define fo(II, XX, YY)       for (int II(XX), _YY(YY); (II) <= (_YY); ++(II))
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

// Useful hardware instructions
#define bitcount             __builtin_popcount
#define gcd                  __gcd

// Useful all around
#define checkbit(n,b)        ( (n >> b) & 1)
#define DREP(a)              sort(all(a));a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)       (lower_bound(all(arr),ind)-arr.begin())

// Code written during the competition below

#include <unordered_map>

vector<string> dict;
unordered_map<string, char> mp;
unordered_map<string, char> mp1;
unordered_map<string, char> mp2;
unordered_map<string, char> mp3;

int dp[5000][6], N;
char line[5000];
string S;

void solve_testcase() {
  S = "x" + string(line);
  N = size(S) - 1;
  
  debug(S);
  
  re (i, N + 1)
    re (j, 6)
      dp[i][j] = N + 1;
  
  re (pos, 6)
    dp[0][pos] = 0;
  
  string cur, next;
  int cur_len;
  
  fo (i, 1, N) {
    fo (len, 1, 11) {
      if (i - len >= 0) {
        int j = i - len;
        cur = S.substr(j + 1, len);
        cur_len = size(cur);
        //debug("trying", cur);
        if (mp.count(cur)) {
          //debug("can_fit", i, cur);
          re (pos, 6)
            remin(dp[i][5], dp[j][pos]);
        }
        
        // 1 error
        re (e1, size(cur)) {
          next = cur;
          next[e1] = '*';
          if (mp1.count(next)) {
            int from_start = i - (j + 1 + e1);
            if (from_start > 4) from_start = 5;
            
            int admits =  (4-e1);
            if (admits <= 0) admits = 0;
            
            re (pos, 6)
              if (pos >= admits)
                remin(dp[i][from_start], dp[j][pos] + 1);
          }
        }
        
        re (e1, size(cur))
        fo (e2, e1 + 5, size(cur) - 1) {
          next = cur;
          next[e1] = next[e2] = '*';
          if (mp2.count(next)) {
            int from_start = i - (j + 1 + e2);
            if (from_start > 4) from_start = 5;
            
            int admits =  (4-e1);
            if (admits <= 0) admits = 0;
            
            re (pos, 6)
            if (pos >= admits)
              remin(dp[i][from_start], dp[j][pos] + 2);
          }
        }
        
        re (e1, size(cur))
        fo (e2, e1 + 5, size(cur) - 1)
        fo (e3, e2 + 5, size(cur) - 1) {
          next = cur;
          next[e1] = next[e2] = next[e3] = '*';
          if (mp3.count(next)) {
            int from_start = i - (j + 1 + e3);
            if (from_start > 4) from_start = 5;
            
            int admits =  (4-e1);
            if (admits <= 0) admits = 0;
            
            re (pos, 6)
            if (pos >= admits)
              remin(dp[i][from_start], dp[j][pos] + 3);
          }
        }
      }
    }
  }
  
  int final_res = N + 1;
  
  re (i, 6)
    remin(final_res, dp[N][i]);
  
  printf("%d", final_res);
}

void preprocess() {
  FILE * fin = fopen("garbled_email_dictionary.txt", "r");
  char word[20];
  
  int max_len = 0;
  
  while(fgets(word, 100, fin)) {
    string cur = string(word, strlen(word) - 1);
    //debug(cur);
    if (!mp.count(cur)) {
      mp[cur] = 4;
      dict.pb(cur);
    }
    remax(max_len, size(cur));
  }
  fclose(fin);

  debug("max_len =", max_len, "dict_size =", size(dict));

  re (i, size(dict)) {
    re (k, size(dict[i])) {
      string cur = dict[i];
      cur[k] = '*';
      mp1[cur] = 1;
    }
  }
  
  re (i, size(dict)) {
    if (i % 100000 == 0) {
      debug("build 2", i);
    }
    
    if (size(dict[i]) < 6)
      continue;
    
    re (k, size(dict[i])) {
      fo (l, k + 5, size(dict[i]) - 1) {
        string cur = dict[i];
        cur[k] = cur[l] = '*';
        mp2[cur] = 2;
      }
    }
  }

  re (i, size(dict)) {
    if (i % 100000 == 0) {
      debug("build 3", i);
    }
    if (size(dict[i]) < 11)
      continue;
    re (k, size(dict[i])) {
      fo (l, k + 5, size(dict[i]) - 1) {
        fo (o, l + 5, size(dict[i]) - 1) {
          string cur = dict[i];
          cur[k] = cur[l] = cur[o] = '*';
          mp3[cur] = 3;
        }
      }
    }
  }
}

int main() {
  preprocess();

  int T; scanf("%d \n", &T);
  fo (testcase, 1, T) {
    gets(line);
    printf("Case #%d: ", testcase);
    solve_testcase();
    printf("\n");
  }
  return 0;
}
