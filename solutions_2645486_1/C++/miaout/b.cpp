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
typedef vector<int64> VI;
#define REP(i,a,b) for (int i=int(a); i<int(b); ++i)
void unittest();

typedef pair<int64, int64> PII;
typedef vector<PII> VPII;
typedef map<int64, int64> MII;

int64 E, R, N;
VI weights;
VPII pq;
MII limits;
MII alimits;

void solve(int caseNum) {
  weights.clear();
  pq.clear();
  limits.clear();
  alimits.clear();

  int64 ans=0;

  cin>>E>>R>>N;
  REP(i, 0, N) {
    int64 w; cin>>w;
    weights.push_back(w);
    pq.push_back(PII(w, i));
  }

  sort(pq.begin(), pq.end(), greater<PII>());
  REP(i, 0, N) {
    int64 w = pq[i].first;
    int64 idx= pq[i].second;

    MII::iterator rit = limits.upper_bound(idx);
    MII::iterator lit = rit;

    int64 curEnergy = E;

    if (lit!=limits.begin()) {
      --lit;
      if (lit!=limits.end()) {
        int64 leftIdx = lit->first;
        int64 recover = alimits[leftIdx] + R * (idx-leftIdx);
        curEnergy = min(E, recover);
        // printf("Recover: %lld/%lld\n", curEnergy, E);
      }
    }

    int64 afterEnergy = 0;

    if (rit!=limits.end()) {
      int64 rightIdx = rit->first;
      int64 rightReq = rit->second;

      afterEnergy = rightReq - R * (rightIdx-idx);
      // printf("RLIMIT=%lld (%lld, %lld, %lld, %lld)\n", afterEnergy, rightReq, R, rightIdx, idx);
      afterEnergy = max(afterEnergy, 0LL);
    }

    // printf("Cur/After: %lld/%lld\n", curEnergy, afterEnergy);

    int64 consumeEnergy = curEnergy - afterEnergy;
    // if (consumeEnergy<0) { printf("PANIC!\n"); exit(0); }
    assert(consumeEnergy>=0);
    assert(consumeEnergy<=E);

    ans += w * consumeEnergy;

    // printf("Idx: %lld, Weight: %lld, Cur: %lld, After: %lld, Gain: %lld, Score: %lld\n", idx, w, curEnergy, afterEnergy, w*consumeEnergy, ans);

    limits[idx] = curEnergy;
    alimits[idx] = afterEnergy;
  }

  // REP(i, 0, N) {
  //   int64 w = pq[i].first;
  //   int64 idx= pq[i].second;
  //   MII::iterator mit = limits.upper_bound(idx);
  //   int64 req = E;
  //   if (mit!=limits.end()) {
  //     int64 nextIdx = mit->first;
  //     int64 nextReq = mit->second;
  //     int64 usedLimit = nextReq - (idx - nextIdx) * R;
  //     limit = max(0LL, limit);
  //     printf("RLIMIT=%lld\n", limit);
  //     req = min(req, limit);
  //   }
  //   if (mit!=limits.begin()) {
  //     --mit;
  //     if (mit!=limits.end()) {
  //       int64 prevIdx = mit->first;
  //       int64 prevReq = mit->second;
  //       int64 limit = (idx - prevIdx) * R;
  //       limit = max(0LL, limit);
  //       printf("LLIMIT=%lld\n", limit);
  //       req = min(req, limit);
  //     }
  //   }

  //   limits[idx] = req;

  //   ans += req * w;
  //   // printf("Idx %lld, Weight %lld, Req %lld, Score %lld, Now %lld\n", idx, w, req, req*w, ans);
  // }

  printf("Case #%d: %lld\n", caseNum, ans);
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

