#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005

int main() {
  freopen("input", "r", stdin);
  //freopen("output", "w", stdout);
  int cs;
  cin >> cs;
  REP(csn, 1, cs + 1) {
    printf("Case #%d:", csn);
    //cerr << csn << endl;
    int N;
    cin >> N;
    map<int,int> cnt;
    REP(i,0,2*N-1) {
      int x;
      REP(j,0,N) {
        scanf("%d", &x);
        cnt[x]++;
      }
    }
    VI ans;
    for(map<int,int>::iterator r=cnt.begin();r!=cnt.end();r++) {
      if (r->second % 2) ans.push_back(r->first);
    }
    sort(ans.begin(), ans.end());
    REP(i,0,N) printf(" %d", ans[i]);
    puts("");
  }
  return 0;
}
