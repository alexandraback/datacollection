
#include <cassert>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <limits>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
using namespace std;
typedef long long ll;

char buf[10][30];
int len;


bool canMerge() {
  REP(i, len) {
    if(buf[0][i] != '?' && buf[1][i] != '?' && buf[0][i] != buf[1][i])
      return false;
  }
  return true;
}


void merge0(char* res, int bg, int ed) {
  for(int i = bg; i < ed; ++i) {
    res[i] = buf[0][i] != '?' ? buf[0][i] : buf[1][i] != '?' ? buf[1][i] : '0';
  }
}
void fill9(const char* base, char* res, int bg, int ed) {
  for(int i = bg; i < ed; ++i) {
    res[i] = base[i] != '?' ? base[i] : '9';
  }
}
void fill0(const char* base, char* res, int bg, int ed) {
  for(int i = bg; i < ed; ++i) {
    res[i] = base[i] != '?' ? base[i] : '0';
  }
}

int main(void) {
  
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    scanf("%s%s", buf[0], buf[1]);
    len = strlen(buf[0]);
    buf[2][len] = buf[3][len] = buf[6][len] = buf[7][len] = 0;
    
    if(canMerge()) {
      merge0(buf[6], 0, len);
      merge0(buf[7], 0, len);
      
    } else {
      ll ra, rb, rc = numeric_limits<ll>::max();
      REP(d, len) {
        if(buf[0][d] == buf[1][d] && buf[0][d] != '?') { // must be same
          continue;
        }
        merge0(buf[2], 0, d);
        merge0(buf[3], 0, d);
        REP(i, 10) if(buf[0][d] == '?' || buf[0][d] == '0' + i) {
          REP(j, 10) if(buf[1][d] == '?' || buf[1][d] == '0' + j) {
            if(i == j)
              continue;
            buf[2][d] = '0' + i;
            buf[3][d] = '0' + j;
            if(i < j){
              fill9(buf[0], buf[2], d+1, len);
              fill0(buf[1], buf[3], d+1, len);
            } else {
              fill0(buf[0], buf[2], d+1, len);
              fill9(buf[1], buf[3], d+1, len);
            }
            ll a, b, c;
            sscanf(buf[2], "%lld", &a);
            sscanf(buf[3], "%lld", &b);
            c = abs(a-b);
            // cerr << "> " << d << " " << a << " " << b << " " << c << endl;
            if(c < rc || (c == rc && (a < ra || (a == ra && b < rb)))) {
              ra = a;
              rb = b;
              rc = c;
              strcpy(buf[6], buf[2]);
              strcpy(buf[7], buf[3]);
            }
          }
        }
        if(buf[0][d] != '?' && buf[1][d] != '?' && buf[0][d] != buf[1][d]) { // must be different
          break;
        }
      }
    }
    printf("Case #%d: %s %s\n", iCase+1, buf[6], buf[7]);
  }
  return 0;
}
