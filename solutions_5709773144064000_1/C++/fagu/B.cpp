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

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		double C, F, X;
		scanf("%lf%lf%lf", &C, &F, &X);
		double su = 0, res = 1E9;
		for (int k = 0; su < res; k++) {
			res = min(res, su+X/(2.+k*F));
			su += C/(2.+k*F);
// 			fprintf(stderr, "%d\n", k);
		}
		printf("%.7f\n", res);
	}
	return 0;
}
