#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <sstream>
#include <stdlib.h>
using namespace std;

char seen[1<<20];
int needs[20], has[20][201], ans[20];
stack< pair<int, int> > S;

int pc(int x) { return !x?0:(x&1)+pc(x>>1); }

int main(int argc, char* argv[]) {
  int nocases, n, k;
  cin >> nocases;
  for (int rr = 1; rr <= nocases; ++rr) {
    cin >> k >> n;
    int cnt[201], t;
    memset(cnt, 0, sizeof(cnt));
    memset(seen, 0, sizeof(seen));
    memset(needs, 0, sizeof(needs));
    memset(has, 0, sizeof(has));
    for (int i = 0; i < k; ++i) {
      cin >> t;
      cnt[t]++;
    }
    for (int i = 0; i < n; ++i) {
      cin >> needs[i] >> k;
      for (int j = 0; j < k; ++j) {
	cin >> t;
	has[i][t]++;
      }
    }
    S = stack< pair<int, int> >();
    S.push(make_pair(0, 0));
    seen[0] = 1;
    int found = 0;
    while (S.size()) {
      pair<int, int> z = S.top();
      S.pop();
      int x = z.first, last = z.second;
      int p = pc(x);
      if (p)
	ans[p-1] = last;
      if (p == n) {
	found = 1;
	break;
      }
      int have[201];
      for (int i = 1; i <= 200; ++i)
	have[i] = cnt[i];
      for (int i = 0; i < n; ++i)
	if (x & (1<<i)) {
	  have[needs[i]]--;
	  for (int j = 1; j <= 200; ++j)
	    have[j] += has[i][j];
	}
      for (int i = n-1; i >= 0; --i)
	if (!(x&(1<<i)) && have[needs[i]]) {
	  int y = x | 1<<i;
	  if (!seen[y]) {
	    S.push(make_pair(y, i));
	    seen[y] = 1;
	  }
	}
    }
    if (!found)
      printf("Case #%d: IMPOSSIBLE\n", rr);
    else {
      printf("Case #%d:", rr);
      for (int i = 0; i < n; ++i)
	cout << " " << (ans[i]+1);
      cout << endl;
    }
  }
  return 0;
}
