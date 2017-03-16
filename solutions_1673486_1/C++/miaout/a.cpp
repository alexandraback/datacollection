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

int A, B;
double prob[100001]; // correctly
double correct[100001];

const double INF = 0x7fffffff;

void solve(int caseNum) {
  cin>>A>>B;
  REP(i, 0, A)
    cin>>prob[i];
  double now = 1.0;
  REP(i, 0, A) {
    now *= prob[i];
    correct[i] = now;
  }

  double best = INF;
  double retypeCost = B + 1;
  REP(i, 0, A+1) {
    int back = A - i;
    double backCost = back + (B-i) + 1;
    double c = (i==0) ? 1.0 : correct[i-1];
    double avg = backCost + (1.0-c) * retypeCost;
    // cout<<backCost<<" "<<retypeCost<<endl;
    // cout<<avg<<endl;
    best = min(best, avg);
  }

  double enterCost = B + 2;
  best = min(best, enterCost);

  printf("Case #%d: %.10lf\n", caseNum, best);
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

