#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory.h>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long double Double;
typedef vector<int> VInt;
typedef vector< vector<int> > VVInt;
typedef long long Int;
typedef pair<int, int> PII;

#define FOR(i, n, m) for(i = n; i < m; ++i)
#define RFOR(i, n, m) for(i = (n) - 1; i >= (m); --i)
#define CLEAR(x, y) memset(x, y, sizeof(x))
#define COPY(x, y) memcpy(x, y, sizeof(x))
#define PB push_back
#define MP make_pair
#define SIZE(v) ((int)((v).size()))
#define ALL(v) (v).begin(), (v).end()

#define MOD 1000000007LL

char buf[1000];
int singles[3000];

int main()
{
  int T, t;
  scanf("%d", &T);
  for (t = 0; t < T; ++t) {
    vector<string> v;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf("%s", buf);
      v.PB(buf);
    }
    CLEAR(singles, 0);

    for (int i = 0; i < v.size(); ++i) {
      int j;
      for (j = 0; j < v[i].size(); ++j)
	if (v[i][j] != v[i][0])
	  break;
      if (j == v[i].size()) {
	singles[v[i][0]]++;
	//	cout << "single " << v[i] << "(" << i << endl;
	v.erase(v.begin() + i);
	--i;
      }
    }

    bool bad = false;
    Int res = 1;

    for (char c = 'a'; c <= 'z'; ++c) {
      int si, ei, mi;
      si = ei = mi = -1;
      for (int i = 0; i < v.size(); ++i) {
	if (v[i][0] == c) {
	  if (si == -1)
	    si = i;
	  else
	    bad = true;
	}
	if (v[i][v[i].size()-1] == c) {
	  if (ei == -1)
	    ei = i;
	  else
	    bad = true;
	}
	if (si == i) {

	  int p = v[i].rfind(c);
	  while (p > 0 && v[i][p] == c)
	    --p;
	  if (p > 0) {
	    if (mi == -1)
	      mi = i;
	    else
	      bad = true;
	  }

	} else if (ei == i) {

	  int p = v[i].find(c);
	  while (p < v[i].size() && v[i][p] == c)
	    ++p;
	  if (p < v[i].size()) {
	    if (mi == -1)
	      mi = i;
	    else
	      bad = true;
	  }

	} else {

	  int p = v[i].find(c);
	  int rp = v[i].rfind(c);
	  if (p != string::npos) {
	    while (p < rp && v[i][p] == c)
	      ++p;
	    if (p != rp)
	      bad = true;
	    if (mi == -1)
	      mi = i;
	    else
	      bad = true;
	  }

	}	
      }

      if (mi != -1 && (si != -1 || ei != -1 || singles[c]))
	bad = true;
	
      // merge singles
      if (singles[c] && (si != -1 || ei != -1)) {
	while (singles[c]) {
	  res = (res * singles[c]) % MOD;
	  --singles[c];
	}	  
      }

      if (si != -1 && ei != -1) {
	if (si == ei)
	  bad = true;
	else {
	  v[ei] = v[ei] + v[si];
	  v.erase(v.begin() + si);
	}
      }

    }    

    int kg = v.size();
    for (char c = 'a'; c <= 'z'; ++c)
      if (singles[c]) {
	//	cout << "single left " << c << endl;
	++kg;
	while (singles[c]) {
	  res = (res * singles[c]) % MOD;
	  --singles[c];
	}	  
      }

    //    cout << "v.s = " << v.size() << " kg=" << kg << endl;

    while (kg) {
      res = (res * kg) % MOD;
      --kg;
    }
    
    if (bad)
      res = 0;

    printf("Case #%d: %d\n", t+1, (int)res);
  }

  return 0;
};
