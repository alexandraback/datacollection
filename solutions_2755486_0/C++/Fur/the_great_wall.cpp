#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 15;
const int INF = -1u/2;

#define pii pair<int, int>
#define x first
#define y second

int n;
int ni[MAX_N];
int w[MAX_N], e[MAX_N];
int d[MAX_N];
int p[MAX_N];
int dd[MAX_N];
int s[MAX_N];
int ds[MAX_N];
map<int, int> h;
vector<pii> kant;

int main() {
  int T;
  scanf("%d", &T);
  for(int __ = 1; __ <= T; __++) {
    h.clear();
    int cnt = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
      scanf("%d %d %d %d %d %d %d %d", &d[i], &ni[i], &w[i], &e[i], &s[i], &dd[i], &p[i], &ds[i]);
    }
    for(int day = *min_element(d+1, d+n+1); ;) {
      int newday = INF;
      kant.clear();
      for(int i = 1; i <= n; i++) {
	if(ni[i] > 0) {
	  if(d[i] == day) {
	    // printf("%d %d\n", i, day);
	    bool suc = false;
	    for(int j = w[i]*2; j <= e[i]*2; j++) {
	      // printf("->%f: h = %d, s = %d\n", j/2.0, h[j], s[i]); 
	      if(h[j] < s[i]) {
		suc = true;
		kant.push_back(pii(j, s[i]));
	      }
	    }
	    cnt += suc;

	    ni[i]--;
	    d[i] += dd[i];
	    w[i] += p[i];
	    e[i] += p[i];
	    s[i] += ds[i];
	  }
	  if(ni[i] > 0) {
	    newday = min(newday, d[i]);
	  }
	}
      }
      for(; kant.size(); kant.pop_back()) {
	h[kant.back().x] = max(h[kant.back().x], kant.back().y);
      }
      if(newday == INF) {
	break;
      } else {
	day = newday;
      }
    }
    printf("Case #%d: %d\n", __, cnt);
  }
}
