#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <complex>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <assert.h>
#include <array>
#include <cstdio>
#include <cstring>
#include <random>
#include <functional>
#include <numeric>
#include <bitset>
#include <fstream>

using namespace std;

struct before_main{before_main(){cin.tie(0); ios::sync_with_stdio(false);}} before_main;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;
int const inf = 1<<29;

string C, J;
string T;
int csize, jsize;
int minC, minJ, minDiff;

void dfs(int idx) {
  if(idx == csize + jsize) {
    int c = stoi(T.substr(0, csize));
    int j = stoi(T.substr(csize));
    int ab = abs(c-j);
    if(minimize(minDiff, ab)) {
      minC = c, minJ = j;
    } else if(ab == minDiff && minimize(minC, c)) {
      minJ = j;
    } else if(ab == minDiff && minC == c && minimize(minJ, j)) {
    }
    return;
  }
  if(T[idx] == '?') {
    rep(i, 10) {
      T[idx] = i + '0';
      dfs(idx + 1);
      T[idx] = '?';
    }
  } else {
    dfs(idx + 1);
  }
}

int main() {

  int N; cin >> N;
  rep(i, N) {
    cin >> C >> J;
    cout << "Case #" << i+1 << ": ";
    csize = C.size(), jsize = J.size();
    T = C + J;
    minC = inf, minJ = inf, minDiff = inf;
    dfs(0);
    rep(i, csize - to_string(minC).size()) cout << "0";
    cout << minC << " ";
    rep(i, jsize - to_string(minJ).size()) cout << "0";
    cout << minJ << endl;
  }
  
  return 0;
}