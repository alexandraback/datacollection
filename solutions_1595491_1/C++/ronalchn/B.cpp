#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

void solve(int t) {
  int N, S, p;

  cin >> N >> S >> p;

  int minn=p+max(p-1,0)*2; // min score with best score of p that is not surprising
  int mins=p+max(p-2,0)*2; // min score with best score of p that is surprising
//cout << minn << " " << mins << endl;
  int good=0, goods=0;
  for (int i=0;i<N;i++) {
    int score;
    cin >> score;
    if (score >= minn) good++;
    else if (score >= mins) goods++;
  }

  if (S<goods) goods = S;

  printf("Case #%d: %d\n",t,good+goods);
}

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    solve(t);
  }
  return 0;
}
