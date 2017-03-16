#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B)	for(int I = (A); I < (B); ++I)
#define REP(I,N)	FOR(I,0,N)
#define ALL(A)		(A).begin(), (A).end()
#define DAYS 676066
using namespace std;

typedef struct
{
	int d,n;
	int w,e;
	int s;
	int dd,dp,ds;
} tr;
tr tribes[11];
int heights[1111], nheights[1111];
vector< pair< int, int> > attacks[DAYS];
int main()
{
	int currTest,T;
	scanf("%d", &T);
	REP(currTest, T) {
		REP(i, 1111) heights[i] = nheights[i] = 0;
		REP(i, DAYS) attacks[i].clear();
		int n;
		scanf("%d", &n);
		REP(i, n) {
			scanf("%d %d %d %d %d %d %d %d", &tribes[i].d, &tribes[i].n, &tribes[i].w, &tribes[i].e, &tribes[i].s, &tribes[i].dd, &tribes[i].dp, &tribes[i].ds);
			REP(j, tribes[i].n) {
				attacks[tribes[i].d+j*tribes[i].dd].push_back(make_pair(i, j));
			}
		}
		int ans = 0;
		REP(i, DAYS) {
			if(attacks[i].size() > 0) {
				REP(j, 1111) nheights[j] = heights[j];
				REP(j, attacks[i].size()) {
					int tribe = attacks[i][j].first;
					int no = attacks[i][j].second;
					int strength = tribes[tribe].s + no*tribes[tribe].ds;
					int start = tribes[tribe].w + no*tribes[tribe].dp;
					int end = tribes[tribe].e + no*tribes[tribe].dp;
					bool succ = false;
					for(int k = 2*start; k <= 2*end; k++) {
						if(heights[(k+444)] < strength) { succ = true; nheights[(k+444)] = max(nheights[(k+444)], strength); }
					}
//					printf("DAY %d: tribe %d attacks its %dth attack: \n", i, tribe, no);
	//				printf("   strength %d, from %d to %d, succ=%d\n", strength, start, end, succ);
					if(succ) ans++;
				}

				REP(j, 1111) heights[j] = nheights[j];
			}
		}		

		printf("Case #%d: %d\n", currTest+1, ans);
	}
	return 0;
}
