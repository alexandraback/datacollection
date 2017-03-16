
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

char buf[110];

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase){
    scanf("%s", buf);
    int len = strlen(buf);
    char ch = '+';
    int res = 0;
    for(int i = len-1; i >= 0; --i) {
      if(buf[i] != ch) {
        ch = buf[i];
        ++res;
      }
    }
    printf("Case #%d: %d\n", iCase+1, res);
  }
  return 0;
}
