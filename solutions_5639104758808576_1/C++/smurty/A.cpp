#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <utility>
#include <vector>
using namespace std;

#define FORIT(it, obj) for(__typeof(obj.begin()) it=obj.begin();it!=obj.end();++it)
#define REP(i, N) for(int i = 0; i < N; i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define mp make_pair
#define pb push_back
#define bpc __builtin_popcount
typedef pair<int,int> pii;
typedef long long ll;

int main() {
  //freopen("c.in", "r", stdin);
  int T; 
  scanf("%d", &T);
  REP(i, T) {
    printf("Case #%d: ", i + 1);
    int Sm; scanf("%d", &Sm);
    string digs;
    cin >> digs;
    static int di[1050];
    REP(j, Sm+1) di[j] = digs[j] - '0';
    int ans = 0;
    int ps = di[0];
    FOR(j, 1, Sm) {
      //      printf("di[%d] = %d, ps=%d\n", j, di[j], ps);
      if (di[j] == 0) continue;

      if (ps < j)  {
	ans += j - ps;
	ps += j - ps;
      }
      ps += di[j];
    }
    printf("%d\n", ans);
  }


  return 0;
}
