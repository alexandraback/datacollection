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

const int MAXN = 10000;
LL acts[MAXN];

LL must_min[MAXN]; // po zakonczeniu, przed R
LL can_max[MAXN]; // przed rozpoczeciem wydawania
bool selected[MAXN];

void testcase() {
	LL e, r, n;
	scanf("%lld%lld%lld", &e, &r, &n);
	vector< pair<int,int> > pary;
	REP(i,n) {
		scanf("%lld", acts+i);
		pary.PB(MP(acts[i], -i));
	}
	sort(pary.begin(), pary.end());
	reverse(pary.begin(), pary.end());

	REP(i,n) {
		can_max[i] = e;
		must_min[i] = 0;
		selected[i] = false;
	}

	REP(i,n) {
		int index = -pary[i].SE;
		int latacz = index-1, odjac = 1;
		while (latacz >= 0) {
			if (!selected[latacz]) {
				must_min[latacz] = max(can_max[index] - r*odjac, 0LL);
			} else {
				break;
			}
			--latacz;
			++odjac;
		}
		odjac = 1;
		latacz = index+1;
		while (latacz < n) {
			if (!selected[latacz]) {
				can_max[latacz] = min(must_min[index] + r*odjac, e*1LL);
			} else {
				break;
			}
			++latacz;
			++odjac;
		}
		selected[index] = true;
	}

	LL result = 0;
	LL to_spend = e;
	REP(i,n) {
		result += (to_spend-must_min[i])*(LL)acts[i];
		to_spend = min(must_min[i] + r, e);
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
