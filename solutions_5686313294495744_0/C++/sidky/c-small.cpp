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

int main() {
	int T,cs;
  set <string> first, second;
  string s1[20],s2[20];
  int N;

  cin >> T;

	rab(cs,1,T) {
    cin >> N;

    int i,j;

    for (i = 0; i < N; i++) {
      cin >> s1[i] >> s2[i];
    }

    int max_fake = 0,c;

    for (j = 0; j < (1 << N); j++) {
      first.clear();
      second.clear();

      Fi(N) {
        if (j & (1 << i)) continue;
        first.insert(s1[i]);
        second.insert(s2[i]);
      }

      c = 0;

      Fi(N) {
        if (j & (1 << i)) {
          if (first.find(s1[i]) == first.end() || second.find(s2[i]) == second.end()) {
            break;
          }
          c++;
        }
      }

      if (i >= N) {
        if (c > max_fake) max_fake = c;
      }
    }

    printf("Case #%d: %d\n", cs, max_fake);
	}

} 
