
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

const char* DS[10] = {"ZERO", "SIX", "TWO", "EIGHT", "SEVEN", "FIVE", "FOUR", "ONE", "THREE", "NINE"};
const int ds[10] = {0, 6, 2, 8, 7, 5, 4, 1, 3, 9};
int lens[10];

char buf[10000];
int main(void) {
  map<char,int> ms[10];
  REP(i, 10){
    lens[i] = strlen(DS[i]);
    REP(j, lens[i]){
      ms[i][DS[i][j]]++;
    }
  }
  
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    scanf("%s", buf);
    int len = strlen(buf);
    map<char,int> m;
    REP(i, len){
      m[buf[i]]++;
    }

    vector<int> res(10);
    REP(i, 10){
      int num = 1000000000;
      FOR(it, ms[i]){
        num = min(num, m[it->first] / it->second);
      }
      res[ds[i]] = num;
      FOR(it, ms[i]){
        m[it->first] -= it->second * num;
      }
    }
    printf("Case #%d: ", iCase+1);
    REP(i, 10) REP(j, res[i])
      printf("%d", i);
    puts("");
  }
  return 0;
}
