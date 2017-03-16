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

bool comp(int X, int R, int C) {
	if (C > R)
		swap(C,R);
	if (R*C%X != 0 || X > R || X > 2*C || X > 6)
		return false;
	if (X == 4 && C == 2)
		return false;
	if (X == 5 && C == 3 && R == 5)
		return false;
	if (X == 6 && C == 3)
		return false;
	return true;
}

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		int X, R, C;
		scanf("%d%d%d", &X, &R, &C);
		if (comp(X,R,C))
			printf("GABRIEL\n");
		else
			printf("RICHARD\n");
	}
	return 0;
}
