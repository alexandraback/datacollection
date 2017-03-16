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

// For small solution only
const int MB = 1<<20;
const int MN = 201;
int K, N;

bool traversed[MB];
int opened;
int reqs[MN];
VI initKeys;
VI keys;
VI rewards[MN];
VI cand;
VI ans;

bool rec() {
  if (0) {
    printf("Opened=%d\n", opened);
    printf("Keys: "); REP(i, 0, 10) printf("%d ", keys[i]); printf("\n");
  }

  if (cand.size()==N) {
    assert(opened==((1<<N)-1));
    ans = cand;
    return true;
  }

  if (traversed[opened]) return false;
  traversed[opened] = true;

  int nowOpened = opened;

  bool succeed = false;

  REP(i, 1, N+1) {
    if (succeed) break;

    int mask = 1<<(i-1);
    // printf("%d, mask=%d\n", i, mask);
    assert(mask<MB);
    if (opened&mask) continue;
    int key = reqs[i];
    assert(key>=1 && key<=MN);
    if (keys[key]==0) continue;
    assert(keys[key]>0);

    --keys[key];
    opened |= mask;
    cand.push_back(i);
    REP(j, 0, rewards[i].size()) {
      // cout<<"Reward key"<<rewards[i][j]<<endl;
      ++keys[rewards[i][j]];
    }

    succeed = rec();

    ++keys[key];
    opened = nowOpened;
    // opened = opened & ~mask;
    cand.pop_back();
    REP(j, 0, rewards[i].size()) {
      --keys[rewards[i][j]];

      assert(rewards[i][j]>0 && rewards[i][j]<MN);
      assert(keys[rewards[i][j]]>=0);
    }
  }
  return succeed;
}

void solve(int caseNum) {
  cin>>K>>N;
  // printf("Case %d: %d initial keys, %d chests\n", caseNum, K, N);

  cand.clear();
  opened = 0;
  REP(i, 0, MN) {
    keys[i] = 0;
    rewards[i].clear();
  }
  REP(i, 0, MB) {
    traversed[i] = false;
  }

  REP(i, 1, K+1) {
    int v;
    cin>>v;
    ++keys[v];
  }

  REP(i, 1, N+1) {
    int v;
    cin>>v;
    reqs[i] = v;

    int keynum;
    cin>>keynum;
    REP(j, 0, keynum) {
      cin>>v;
      rewards[i].push_back(v);
    }
  }

  initKeys = keys;
  bool succeed = rec();
  assert(keys==initKeys);

  printf("Case #%d: ", caseNum);
  if (succeed) {
    REP(i, 0, ans.size()) {
      if (i!=0) printf(" ");
      printf("%d", cand[i]);
    }
  } else {
    printf("IMPOSSIBLE");
  }

  printf("\n");
}

int main() {
  unittest();

  REP(i, 0, MN)
    keys.push_back(0);

  int caseCount;
  cin>>caseCount;
  REP(i, 1, caseCount+1)
    solve(i);

  return 0;
}

void unittest() {
}

