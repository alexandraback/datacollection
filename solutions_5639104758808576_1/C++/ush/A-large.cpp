
#include <cassert>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
using namespace std;
typedef long long ll;

char buf[10000];
int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase){
    int len;
    scanf("%d%s", &len, buf);
    int cur = 0;
    int res = 0;
    REP(i, len+1){
      int cnt = buf[i] - '0';
      while(cur+res < i){
        ++res;
      }
      cur += cnt;
    }
    printf("Case #%d: %d\n", iCase+1, res);
  }
  return 0;
}
