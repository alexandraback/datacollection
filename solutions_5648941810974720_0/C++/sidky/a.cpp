#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <list>
using namespace std;
 
#define  rep(i,n)  for((i) = 0; (i) < (n); (i)++)
#define  rab(i,a,b)  for((i) = (a); (i) <= (b); (i)++)
#define all(v)    (v).begin(),(v).end()
#define  Fi(n)    rep(i,n)
#define  Fj(n)    rep(j,n)
#define  Fk(n)    rep(k,n)
#define  sz(v)    (v).size()

map<char, int> char_map;

int take(string s) {
  int m = -1,i;

  for (i = 0; i < sz(s); i++) {
    if (m == -1 || (char_map[s[i]] < m)) {
      m = char_map[s[i]];
    }
  }

  for (i = 0; i < sz(s); i++) {
    char_map[s[i]] -= m;
  }

  return m;
}

const char* numbers[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main() {
	int T,cs;
  char s[3000];
  int order[] = {0,2,6,8,4,3,5,7,1,9};
  int i,j;

	scanf("%d",&T);

	rab(cs,1,T) {
    scanf("%s",s);

    char_map.clear();

    for (i = 0; s[i]; i++) {
      char_map[s[i]]++;
    }

    vector <int> v;

    for (i = 0; i <= 9; i++) {
      int c = take(numbers[order[i]]);

      for (j = 0; j < c; j++) v.push_back(order[i]);
    }

    printf("Case #%d: ", cs);

    sort(all(v));

    for (i = 0; i < sz(v); i++) printf("%d",v[i]);
    printf("\n");
	}
  return 0;
} 
