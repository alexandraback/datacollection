#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <math.h>
#define FOR(A, B) for(A=0;A<B;A++)
#define MAXN 111
using namespace std;

long long a[MAXN], A[MAXN], b[MAXN], B[MAXN];
int n,m;

long long solve(int qa, int qb)
{
	if(qa >= n) return 0;
	if(qb >= m) return 0;
	if(A[qa] == B[qb]) {
		if(a[qa] == b[qb]) return a[qa]+solve(qa+1, qb+1);
		else if(a[qa] < b[qb]) {
//			printf("reducing %lld by %lld (%d %d)\n", a[qa], b[qb], qa, qb);
			b[qb] -= a[qa];
			long long x = solve(qa+1, qb);
			b[qb] += a[qa];
			return a[qa]+x;
		} else {
//			printf("reducing %lld by %lld\n", a[qa], b[qb]);
			a[qa] -= b[qb];
			long long x = solve(qa, qb+1);
			a[qa] += b[qb];
			return b[qb]+x;
		}
	} else {
		return max(solve(qa+1, qb), solve(qa, qb+1));
	}
}

int main()
{
	int t,T,i,j;
	scanf("%d", &T);
	FOR(t, T) {
		scanf("%d %d", &n, &m);
		FOR(i, n) scanf("%lld %lld", a+i, A+i);
		FOR(i, m) scanf("%lld %lld", b+i, B+i);

		printf("Case #%d: %lld\n", t+1, solve(0, 0));
	}
	return 0;
}
