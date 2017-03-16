#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define REP(i,n) for(int i = 0; i < (n); ++i)
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define FORE(it,V) for(__typeof__(V.begin()) it = V.begin(); it != V.end(); ++it)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
typedef long long LL;

void testcase() {
	LL r, t;

	LL result = 0;
	scanf("%lld%lld", &r, &t);
	r = 2*r+1;
	while (t >= r) {
		t -= r;
		r += 4;
		++result;
	}
	printf("%lld\n", result);
}

int main() {
  int t;
  scanf("%d", &t);
  FOR(i,1,t) {
  	printf("Case #%d: ", i);
  	testcase();
  }
}
