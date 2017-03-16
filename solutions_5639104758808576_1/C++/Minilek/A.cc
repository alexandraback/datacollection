#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]) {
  int nocases;
  cin >> nocases;
  getchar();
  for (int rr = 1; rr <= nocases; ++rr) {
    int smax, need = 0, tot = 0, cnt;
    cin >> smax;
    string r;
    cin >> r;
    for (int i = 0; i < r.size(); ++i) {
      cnt = r[i]-'0';
      if (tot < i && cnt)
	need += i - tot, tot = i;
      tot += cnt;
    }
    printf("Case #%d: %d\n", rr, need);
  }
  return 0;
}
