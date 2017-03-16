#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

#include<algorithm>
#include<utility>
#include<string>

#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>

using namespace std;

#define REP(i,N) for (int i = 0; i < (N); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, b, a) for (int i = (b) - 1; i >= a; i--)
#define DP(arg...) fprintf(stderr, ## arg) //COMPILER SPECIFIC!!!

typedef long long ll;

int T;
int K,L,S;
char tar[110];
char key[110];
int H[1000];


void solve(int _case) {
	scanf("%d%d%d", &K, &L, &S);
	scanf(" %s %s", key, tar);

	double sol = 0.0;
	for (int x = 'A'; x <= 'Z'; x++) H[x] = 0;
	REP(k,K) { H[key[k]]++; }
	if (L <= S) {
		double zisk = 1.0;
		REP(l,L) {
			if (H[tar[l]] == 0) goto hotov;
			zisk *= (double)H[tar[l]] / (double)K; }
		zisk *= (double)(S-L+1);
		int worst_case = 0;
		int opak = L;
		for (int i = 1; i < L; i++) {
			bool OK = true;
			for (int j = i; j < L; j++) {
				if (tar[j] != tar[j-i])
					OK = false;
			}
			if (OK) { opak = i; break; }
		}
		worst_case = 1 + (S - L) / opak;
		//printf("zisk %lf -- worst case %d\n", zisk, worst_case);
		sol = (double)worst_case - zisk;
	}

	hotov:
	printf("Case #%d: %lf\n", _case, sol);
}

int main() {
	scanf("%d", &T);
	REP(t,T) solve(t+1);
	return 0;
}
