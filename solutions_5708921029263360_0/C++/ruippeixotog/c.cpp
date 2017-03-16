#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 2000

using namespace std;

typedef long long ll;
typedef long double ld;

int j, p, s, k;

int maxT = 0;
vector<pair<int, pair<int, int>>> maxSol;

vector<pair<int, pair<int, int>>> sol;
set<pair<int, pair<int, int>>> used;
map<pair<int, int>, int> usedJP, usedJS, usedPS;

//void bf(int t) {
//  if(t > maxT) {
//    maxT = t;
//    maxSol = sol;
//  }
//
//  for(int i1 = 0; i1 < j; i1++) {
//    for(int i2 = 0; i2 < p; i2++) {
//      auto jp = make_pair(i1, i2);
//      if(usedJP[jp] >= k) continue;
//
//      for(int i3 = 0; i3 < s; i3++) {
//        auto outfit = make_pair(i1, make_pair(i2, i3));
//        auto js = make_pair(i1, i3);
//        auto ps = make_pair(i2, i3);
//
//        if(!used.count(outfit) && usedJS[js] < k && usedPS[ps] < k) {
//          used.insert(outfit);
//          usedJP[jp]++;
//          usedJS[js]++;
//          usedPS[ps]++;
//
//          sol.push_back(outfit);
//          bf(t + 1);
//          sol.pop_back();
//
//          used.erase(outfit);
//          usedJP[jp]--;
//          usedJS[js]--;
//          usedPS[ps]--;
//        }
//      }
//    }
//  }
//}

void bf() {
  maxT = 0;
  used.clear();
  usedJP.clear(); usedJS.clear(); usedPS.clear();
  maxSol.clear();

  for(int i1 = 0; i1 < j; i1++) {
    for(int i2 = 0; i2 < p; i2++) {
      for(int i3 = 0; i3 < s; i3++) {
        auto outfit = make_pair(i1, make_pair(i2, i3));
        auto jp = make_pair(i1, i2);
        auto js = make_pair(i1, i3);
        auto ps = make_pair(i2, i3);

        if(!used.count(outfit) && usedJP[jp] < k && usedJS[js] < k
           && usedPS[ps] < k) {

          used.insert(outfit);
          usedJP[jp]++;
          usedJS[js]++;
          usedPS[ps]++;

          maxT++;
          maxSol.push_back(outfit);
        }
      }
    }
  }
}

int main() {
  int t; scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    scanf("%d %d %d %d", &j, &p, &s, &k);

    bf();

    printf("Case #%d: %d\n", tc, maxT);
    for(auto o : maxSol) {
      printf("%d %d %d\n", o.first + 1, o.second.first + 1, o.second.second + 1);
    }
  }
  return 0;
}
