#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

typedef long long int int64;
typedef vector<int> VI;
#define REP(i,a,b) for (int i=int(a); i<int(b); ++i)
void unittest();

const int MN=100;

int N, M;
// int heights[MN][MN];
bool usedX[MN];
bool usedY[MN];
bool nowX[MN];
bool nowY[MN];

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef map<int, VPII> MIVPII;
MIVPII hmap;

bool judge() {
  hmap.clear();
  cin>>N>>M;

  REP(i, 0, N) {
    usedX[i] = false;
  }
  REP(i, 0, M) {
    usedY[i] = false;
  }

  REP(i, 0, N) {
    REP(j, 0, M) {
      int height;
      cin>>height;
      hmap[height].push_back(PII(i, j));
    }
  }

  for (MIVPII::reverse_iterator it=hmap.rbegin(); it!=hmap.rend(); ++it) {
    REP(i, 0, N) {
      nowX[i] = false;
    }
    REP(i, 0, M) {
      nowY[i] = false;
    }

    const VPII& points = it->second;
    REP(i, 0, points.size()) {
      PII pos = points[i];
      int x = pos.first, y=pos.second;
      if (usedX[x] && usedY[y])
        return false;
      nowX[x] = nowY[y] = true;
    }

    REP(i, 0, N) {
      if (nowX[i]) usedX[i]=true;
    }
    REP(i, 0, M) {
      if (nowY[i]) usedY[i]=true;
    }
  }
  return true;
}

void solve(int caseNum) {
  printf("Case #%d: %s\n", caseNum, judge()?"YES":"NO");
}

int main() {
  unittest();

  int caseCount;
  cin>>caseCount;
  REP(i, 1, caseCount+1)
    solve(i);

  return 0;
}

void unittest() {
}

