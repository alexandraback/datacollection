#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> MaskToPos(int mask, int c) {
  vector<int> pos;
  pos.push_back(0);
  for (int i = 0; i < c; ++i) {
    if (mask & (1<<i)) {
      pos.push_back(i + 1);
    }
  }
  pos.push_back(c+1);
  return pos;
}


vector<vector<int>> SolveAfterHitTable;
int SolveAfterHit(int variants, int hits, int w) {
  if (SolveAfterHitTable[variants][hits] >= 0) {
    return SolveAfterHitTable[variants][hits];
  }
  
  if (variants == 1) { return w - hits; }
  int best = numeric_limits<int>::max();
  for (int i = 0; i < variants - 1; ++i) {
    int cur = 1 + max(SolveAfterHit(i + 1, hits+1, w),
		      SolveAfterHit(variants - i - 1, hits, w));
    best = min(best, cur);
  }
  return SolveAfterHitTable[variants][hits] = best;
}

bool CouldContainShip(vector<int> const &v, int w) {
  bool could = false;
  for (int i = 0; i < v.size() - 1 && !could; ++i) {
    could = (v[i+1] - v[i] - 1 >= w);
  }
  return could;
}

vector<int> SolveWithShipInRowTable;
int SolveWithShipInRow(int mask, int w, int c) {
  if (SolveWithShipInRowTable[mask] >= 0) {
    return SolveWithShipInRowTable[mask];
  }
  auto nonhits = MaskToPos(mask, c);
  int best = numeric_limits<int>::max();
  for (int i = 0; i < nonhits.size() - 1; ++i) {
    int len = nonhits[i+1] - nonhits[i] - 1;
    if (len < w) {
      continue;
    }
    for (int j = nonhits[i]+1; j <= nonhits[i+1]-1; ++j) {
      int new_mask = mask | (1 << (j-1));
      int right = min(j, nonhits[i+1] - w);
      int left = nonhits[i] + 1;
      int cur = SolveAfterHit(right - left + 1, 1, w);
      if (CouldContainShip(MaskToPos(new_mask, c), w)) {
	cur = max(cur, SolveWithShipInRow(new_mask, w, c));
      }
      best = min(best, 1 + cur);
    }
  }

  return SolveWithShipInRowTable[mask] = best;
}

vector<int> SolveWithoutShipInRowTable;
int SolveWithoutShipInRow(int mask, int w, int c) {
  if (SolveWithoutShipInRowTable[mask] >= 0) {
    return SolveWithoutShipInRowTable[mask];
  }

  auto nonhits = MaskToPos(mask, c);
  if (!CouldContainShip(nonhits, w)) {
    return SolveWithoutShipInRowTable[mask] = 0;
  }
  
  int best = numeric_limits<int>::max();
  for (int i = 0; i < nonhits.size() - 1; ++i) {
    int len = nonhits[i+1] - nonhits[i] - 1;
    if (len < w) {
      continue;
    }
    for (int j = nonhits[i]+1; j <= nonhits[i+1]-1; ++j) {
      int new_mask = mask | (1 << (j-1));
      best = min(best, 1 + SolveWithoutShipInRow(new_mask, w, c));
    }
  }

  return SolveWithoutShipInRowTable[mask] = best;
}

int solve_case() {
  int r, c, w;
  cin >> r >> c >> w;

  SolveAfterHitTable.clear();
  SolveAfterHitTable.resize(c+1, vector<int>(w+1, -1));
  SolveWithShipInRowTable.clear();
  SolveWithShipInRowTable.resize(1<<c, -1);
  SolveWithoutShipInRowTable.clear();
  SolveWithoutShipInRowTable.resize(1<<c, -1);
  if (r == 1) {
    return SolveWithShipInRow(0, w, c);
  } else {
    int x = SolveWithoutShipInRow(0, w, c);
    int y = SolveWithShipInRow(0, w, c);
    return (r-1)*x + y;
  }
}

int main() {
  int n_tests; cin >> n_tests;
  for (int t = 1; t <= n_tests; ++t) {
    cout << "Case #" << t << ": " << solve_case() << endl;
  }
  
  return 0;
}
