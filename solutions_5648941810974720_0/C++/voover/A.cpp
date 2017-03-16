#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <complex>
#include <sstream>
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

string names[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
map<char, int> digit_to_letters[10];

vector<int> get(map<char, int>& all_letters) {
  set<int> candidates;
  FOREACH(it, all_letters) {
    set<int> candidates_per_letter;
    REP(i, 10) {
      FOREACH(it2, digit_to_letters[i])
        if (all_letters[it2->first] < it2->second) goto fail;
      candidates_per_letter.insert(i);
      fail:;
    }
    if (candidates_per_letter.size() < candidates.size() || candidates.size() == 0) {
      candidates = candidates_per_letter;
    }
  }
  FOREACH(it, candidates) {
    map<char, int> all_letters_nested;
    FOREACH(it2, all_letters) {
      if (it2->second > digit_to_letters[*it][it2->first]) {
        all_letters_nested[it2->first] = it2->second - digit_to_letters[*it][it2->first];
      }
    }
    if (all_letters_nested.size() == 0) {
      return vector<int>(1, *it);
    }
    vector<int> nested_result = get(all_letters_nested);
    if (nested_result.empty()) {
      continue;
    }
    nested_result.push_back(*it);
    return nested_result;
  }

  return vector<int>();
}

char data[3000];

char data_cmp[3000];

void scase() {
  scanf("%s", data);
  sort(data, data + strlen(data));
  
  map<char, int> all_letters;
  REP(i, strlen(data)) {
    all_letters[data[i]]++;
  }

  vector<int> result = get(all_letters);

  int k = 0;
  REP(i, result.size()) {
    FOREACH(it, digit_to_letters[result[i]])
      REP(j, it->second)
        data_cmp[k++] = it->first;
  }
  data_cmp[k] = 0;
  sort(data_cmp, data_cmp + k);
  if (string(data) != string(data_cmp)) {
    printf("!!%s %s\n", data, data_cmp);
  }
    
  sort(result.begin(), result.end());
  REP(i, result.size()) {
    printf("%d", result[i]);
  }
  printf("\n");
}

int main() {
    REP(i,10) {
      REP(j, names[i].size()) {
        digit_to_letters[i][names[i][j]]++;
      }
    }

    int C;
    scanf("%d",&C);
    FOR(i,1,C+1) {
        printf("Case #%d: ", i);
        scase();
    }
} 
