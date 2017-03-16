#include<iostream>
#include <algorithm>
using namespace std;

int main() {
  int T, cases, N, a[150], A;
  cin >> T;
  for (int cases = 1; cases <= T; cases++) {
    cin >> A >> N;
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    sort(a, a+N);
    int ans = N;
    int cur = A;
    int val = 0;
    for (int i = 0; i < N; i++) {
      if (a[i] < cur) {
	cur += a[i];
	ans <?= val + N-i-1;
      } else {
	if (cur == 1) break;
	else {
	  while (a[i] >= cur) {
	    val++;
	    cur += cur-1;
	  }
	  cur += a[i];
	  ans <?= val + N-i-1;
	}
      }
    }
    printf("Case #%d: %d\n", cases, ans);
  }
  return 0;
}
