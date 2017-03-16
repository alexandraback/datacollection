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

/*
1 - 0
i - 1
j - 2
k - 3
-1 - 4
-i - 5
-j - 6
-k - 7
 */

map<string, int> StrToDig;

string MS[8][8] = {
  {"1", "i", "j", "k", "-1", "-i", "-j", "-k"},
  {"i", "-1", "k", "-j", "-i", "1", "-k", "j"},
  {"j", "-k", "-1", "i", "-j", "k", "1", "-i"},
  {"k", "j", "-i", "-1", "-k", "-j", "i", "1"},
  {"-1", "-i", "-j", "-k", "1", "i", "j", "k"},
  {"-i", "1", "-k", "j", "i", "-1", "k", "-j"},
  {"-j", "k", "1", "-i", "j", "-k", "-1", "i"},
  {"-k", "-j", "i", "1", "k", "j", "-i", "-1"}
};

int Mult[8][8];

int Mpow[8][50];

void init() {
  StrToDig["1"] = 0;
  StrToDig["i"] = 1;
  StrToDig["j"] = 2;
  StrToDig["k"] = 3;
  StrToDig["-1"] = 4;
  StrToDig["-i"] = 5;
  StrToDig["-j"] = 6;
  StrToDig["-k"] = 7;

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      Mult[i][j] = StrToDig[MS[i][j]];
    }
  }
  for (int i = 0; i < 8; ++i) {
    Mpow[i][0] = 0;
    for (int j = 1; j < 40; ++j) {
      Mpow[i][j] = Mult[Mpow[i][j-1]][i];
    }
  }
}

char S[10010];

int VS[10010] = {0};

int LeftMult[10010] = {0};
int RightMult[10010] = {0};

int main()
{
  init();
  int T, t;
  scanf("%d", &T);
  for (t = 0; t < T; ++t) {
    Int L, X;
    scanf("%lld%lld", &L, &X);
    scanf("%s", S);

    if (L*X < 3 || L == 1) {
      printf("Case #%d: NO\n", t+1);
      continue;
    }
    for (int i = 0; i < L; ++i) {
      if (S[i] == 'i') VS[i] = 1;
      if (S[i] == 'j') VS[i] = 2;
      if (S[i] == 'k') VS[i] = 3;
    }
    LeftMult[0] = 0; // "1"
    for (int i = 1; i <= L; ++i) {
      LeftMult[i] = Mult[LeftMult[i-1]][VS[i-1]];
    }
    RightMult[L] = 0;
    for (int i = L-1; i >= 0; --i) {
      RightMult[i] = Mult[VS[i]][RightMult[i+1]];
    }

    if (LeftMult[L] != RightMult[0]) {
      printf("\n\n\nRight-Left mult has a problem!!!!\n\n\n");
    }

    // x^4 == 1
    if (X > 20) {
      X = 20 + X % 4;
    }

    bool found = false;

    // cut one twice
    int curLeft = 0;
    for (int g1 = 0; g1 < X && !found; ++g1) {
      int r1 = curLeft;
      for (int p1 = 0; p1 < L && !found; ++p1) {
	if (r1 == 1) {
	  int r2 = VS[p1];
	  for (int p2 = p1+1; p2 <= L && !found; ++p2) {
	    if (r2 == 2) {
	      int r3 = Mult[RightMult[p2]][Mpow[LeftMult[L]][X - g1 - 1]];
	      if (r3 == 3) {
		found = true;
	      }
	    }
	    r2 = Mult[r2][VS[p2]];
	  }
	}
	r1 = Mult[r1][VS[p1]];
      }
      curLeft = Mult[curLeft][LeftMult[L]];
    }

    // cut different
    curLeft = 0;
    for (int g1 = 0; g1 < X-1 && !found; ++g1) {
      int r1 = curLeft;
      for (int p1 = 0; p1 < L && !found; ++p1) {
	if (r1 == 1) {
	  int curMid = RightMult[p1];
	  for (int g2 = 0; g1 + 1 + g2 < X && !found; ++g2) {
	    int r2 = curMid;
	    for (int p2 = 0; p2 < L && !found; ++p2) {
	      if (r2 == 2) {
		int r3 = Mult[RightMult[p2]][Mpow[LeftMult[L]][X - g1 - 1 - g2 - 1]];
		if (r3 == 3) {
		  found = true;
		}
	      }
	      r2 = Mult[r2][VS[p2]];
	    }    
	    curMid = Mult[curMid][LeftMult[L]];
	  }
	}
	r1 = Mult[r1][VS[p1]];
      }
      curLeft = Mult[curLeft][LeftMult[L]];
    }

    if (found) {
      printf("Case #%d: YES\n", t+1);
    } else {
      printf("Case #%d: NO\n", t+1);
    }

    fprintf(stderr, "done %d / %d\n", t+1, T);

  }
  return 0;
};
