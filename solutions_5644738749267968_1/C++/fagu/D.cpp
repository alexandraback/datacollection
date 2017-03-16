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
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,a,n) for (int i = (a); i < (n); i++)

int T;
int N;
double a[2000];
double b[2000];

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%d", &N);
		REP(i,0,N)
			scanf("%lf", a+i);
		REP(i,0,N)
			scanf("%lf", b+i);
		sort(a, a+N);
		sort(b, b+N);
		int j = 0;
		int res1 = 0, res2 = 0;
		REP(i,0,N) {
			if (a[i] > b[j]) {
				res1++;
				j++;
			}
		}
		j = N-1;
		for (int i = N-1; i >= 0; i--) {
			if (a[i] > b[j])
				res2++;
			else
				j--;
		}
		printf("%d %d\n", res1, res2);
	}
	return 0;
}
