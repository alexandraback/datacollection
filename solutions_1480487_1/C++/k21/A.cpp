#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define DEBUG(x) cout << ">>> " << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

#define INF (1<<29)
typedef long long ll;

int T, N;
int S[250];
vector<int> events[120];

int main() {
	scanf("%d", &T);
	REP(t,T) {
		scanf("%d", &N);
		REP(i,N) scanf("%d", S+i);
		int sum = 0;
		REP(i,120) events[i].clear();
		REP(i,N) {
			sum += S[i];
			events[S[i]].push_back(i);
		}
		int rsum = sum;
		int add = 0;
		int s = 0;
		while(s<110) {
			REP(i,(int)events[s].size()) {
				++add;
			}
			if (add > sum) break;
			sum -= add;
			++s;
		}
		double res = s;
		if (sum) {
			res += (double)sum/add;
		}
		printf("Case #%d: ", t+1);
		REP(i,N) {
			printf("%.10lf", max(0.0,100*(res-S[i])/rsum));
			if (i == N-1) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
