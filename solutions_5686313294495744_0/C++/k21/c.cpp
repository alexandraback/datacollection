#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

vector<pair<string, string>> topics;
map<string, vector<int>> firstGroups;
map<string, vector<int>> secondGroups;
vector<int> firstRepresentants;
vector<int> secondRepresentants;

bool advanceRepresentants(vector<int>& representants, const map<string, vector<int>>& groups) {
  int i = 0;
  for (const auto& p : groups) {
    ++representants[i];
    if (representants[i] < (int)p.second.size()) {
      return true;
    }
    representants[i] = 0;
    ++i;
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  REP(t,T) {
    int N;
    scanf("%d ", &N);
    topics.clear();
    REP(i,N) {
      char word1[100], word2[100];
      scanf("%s %s ", word1, word2);
      topics.push_back(make_pair(word1, word2));
    }
    firstGroups.clear();
    secondGroups.clear();
    REP(i, (int)topics.size()) {
      const auto& p = topics[i];
      firstGroups[p.first].push_back(i);
      secondGroups[p.second].push_back(i);
    }
    REP(i, (int)firstGroups.size()) {
      firstRepresentants.push_back(0);
    }
    REP(i, (int)secondGroups.size()) {
      secondRepresentants.push_back(0);
    }
    int best = 0;
    do {
      do {
        unordered_set<int> representants;
        int iii = 0;
        for (const auto& p : firstGroups) {
          int ii = firstRepresentants[iii];
          int i = p.second[ii];
          representants.insert(i);
          ++iii;
        }
        iii = 0;
        for (const auto& p : secondGroups) {
          int ii = secondRepresentants[iii];
          int i = p.second[ii];
          representants.insert(i);
          ++iii;
        }
        best = max(best, (int)topics.size() - (int)representants.size());
      } while (advanceRepresentants(secondRepresentants, secondGroups));
    } while (advanceRepresentants(firstRepresentants, firstGroups));
    printf("Case #%d: %d\n", t+1, best);
  }
  return 0;
}
