#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;


/* Prewritten code begins */
#define VI          vector<int>
#define PII         pair<int,int>
#define REP(i,n)    for(int i=0; i<(n); ++i)
#define SCI(x)      scanf("%d",&x)
#define BC          __builtin_popcount
#define PB          push_back
#define MP          make_pair
#define ALL(x)      (x).begin(),(x).end()
#define FORE(i,c)   for(VAR(i,(c).begin()); i!=(c).end(); ++i)
#define VAR(i,v)    __typeof(v) i=(v)
#define X           first
#define Y           second
/* Prewritten code ends */

VI a, b, p;
vector<PII> ord;
int main() {
	p.resize(32);
	REP(i,32) p[i] = 1<<i;

	int T, N, res, stars, fail;
	SCI(T);
	REP(cs,T) {
		SCI(N);
		a.resize(N); b.resize(N);
		REP(i,N) SCI(a[i]), SCI(b[i]);
		res = INT_MAX;
		REP(mask,p[N]) if(N+BC(mask) < res) {
			ord.clear();
			REP(i,N) 
				if(mask&p[i]) ord.PB(MP(a[i],1)), ord.PB(MP(b[i],1));
				else ord.PB(MP(b[i],2));
			sort(ALL(ord));
			stars = 0, fail = 0;
			FORE(i,ord) if(stars >= i->X) stars += i->Y; else { fail = 1; break; }
			if(!fail) res = N+BC(mask);
		}
		printf("Case #%d: ", cs+1);
		if(res != INT_MAX) printf("%d\n", res);
		else printf("Too Bad\n");
	}
	return 0;
}
