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
#define REP(i,a,b) for (int64 i=int64(a); i<int64(b); ++i)
void unittest();

const int64 MN = 10000000 + 1;
VI likes;

void solve(int caseNum) {
  int64 lower, upper;
  cin>>lower>>upper;

  int ans=0;

  REP(i, 0, likes.size()) {
    int64 v = likes[i];
    if (v>=lower && v<=upper)
      ++ans;
  }

  printf("Case #%d: %d\n", caseNum, ans);
}

bool palindrome(int64 i) {
  char buf[1024];
  sprintf(buf, "%lld", i);

  char *front, *back;
  front=back=buf;
  while(*back) ++back;
  --back;

  while(front<back) {
    if (*front!=*back) {
      return false;
    }
    ++front; --back;
  }

  return true;
}

void precompute() {
  REP(i, 1, MN) {
    int64 i2 = i*i;
    if (palindrome(i) && palindrome(i2)) {
      likes.push_back(i2);
      // cout<<i2<<endl;
    }
  }
}

int main() {
  unittest();

  precompute();

  int caseCount;
  cin>>caseCount;
  REP(i, 1, caseCount+1)
    solve(i);

  return 0;
}

void unittest() {
}

