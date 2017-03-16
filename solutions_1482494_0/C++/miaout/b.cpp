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

int N;
int A[1001], B[1001], S[1001];
int stars, turns;

// 0 => 2
bool attempt2() {
  REP(i, 0, N) {
    if (S[i]!=0) continue;
    if (A[i]<=stars && B[i]<=stars) {
      S[i] = 2;
      stars += 2;
      // printf("Attempt2 %d\n", i);
      return true;
    }
  }
  return false;
}

bool attempt12() {
  REP(i, 0, N) {
    if (S[i]!=1) continue;
    if (B[i]>stars) continue;
    S[i] = 2;
    stars += 1;
    // printf("Attempt12 %d\n", i);
    return true;
  }
  return false;
}
bool attempt01() {
  int bestIndex = -1;
  int maxB = -1;
  REP(i, 0, N) {
    if (S[i]!=0) continue; // Impossible to get 2 stars here
    if (A[i]>stars) continue;
    if (B[i]>maxB) {
      maxB = B[i];
      bestIndex = i;
    }
  }
  if (bestIndex != -1) {
    S[bestIndex] = 1;
    stars += 1;
    return true;
  }
  return false;
}

void solve(int caseNum) {
  cin>>N;
  REP(i, 0, N) {
    cin>>A[i]>>B[i];
    S[i] = 0;
  }
  turns = stars = 0;
  while (stars < N*2) {
    ++turns;
    if (attempt2()) continue;
    if (attempt12()) continue;
    if (attempt01()) continue;
    break;
  }
  // REP(i, 0, N) cout<<B[i]<<endl;

  if (stars == N*2)
    printf("Case #%d: %d\n", caseNum, turns);
  else
    printf("Case #%d: Too Bad\n", caseNum);
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

