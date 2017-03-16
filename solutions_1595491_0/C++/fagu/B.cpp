#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <assert.h>
#include <math.h>
#include <string.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define FOREACH(it,vec) for(typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); it++)
#define MOD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,n) for (int i = 0; i < (n); i++)

int T;
int N, S, P;

int main() {
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%d %d %d", &N, &S, &P);
		int sowieso = 0, wackel = 0;
		REP(i,N) {
			int s;
			scanf("%d", &s);
			int b1 = (s+2)/3;
			int b2 = (s+4)/3;
			if (b2-2 < 0)
				b2 = -1;
			if (b1 >= P)
				sowieso++;
			else if (b2 >= P)
				wackel++;
		}
		printf("%d\n", sowieso+min(wackel,S));
	}
	return 0;
}
