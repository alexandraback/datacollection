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

typedef map<int, double> MID;

int R, N, M, K;
VI vs;
MID freq;
double bestErr;
VI ans;

void proc(int a1, int a2, int a3) {
  if (a1>a2||a2>a3) return;
  int MN = 3;
  vector<int> as;
  as.push_back(a1);
  as.push_back(a2);
  as.push_back(a3);

  MID cfreq;
  // printf("Proc %d, %d, %d\n", a1, a2, a3);

  double error = 0;
  double stepProb = 1.0 / (1<<N);
  REP(mask, 0, 1<<MN) {
    int p = 1;
    REP(i, 0, MN) {
      if (mask&(1<<i)) {
        p *= as[i];
      }
    }
    // cout<<p<<endl;
    if (cfreq.find(p)==cfreq.end())
      cfreq[p] = 0;
    cfreq[p] += stepProb;
  }

  for (MID::iterator it = freq.begin(); it!=freq.end(); ++it) {
    if (cfreq.find(it->first)==cfreq.end()) {
      // printf("PRUNED\n");
      return;
    }
    error += abs(it->second - cfreq[it->first]);
    // printf("OK %d\n", it->first);
  }
  // printf("OK(%d, %d, %d), Error=%lf\n", a1, a2, a3, error);
  if (error<bestErr) {
    error = bestErr;
    ans = as;
  }
}

void solveR() {
  vs.clear();
  freq.clear();
  bestErr = 10000;
  ans.clear();
  // M=7; N=12;

  REP(i, 0, K) {
    int v; cin>>v;
    vs.push_back(v);
    if (freq.find(v)==freq.end())
      freq[v] = 0;
    freq[v] += (1.0 / K);
    // cout<<freq[v]<<"\n";
  }

  REP(i, 2, M+1) REP(j, 2, M+1) REP(k, 2, M+1) proc(i, j, k);

  REP(i, 0, 3) cout<<ans[i];
  cout<<endl;

}

void solve(int caseNum) {
  cin>>R>>N>>M>>K;

  printf("Case #%d: \n", caseNum);
  REP(i, 0, R)
    solveR();

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

