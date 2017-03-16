#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <stack>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long LL;

#define REP(i, a) for (int i = 0; i < (int)(a); i++)
#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define REPD(i, a) for (int i = (int)(a - 1); i >= 0; i--)
#define FORD(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define CLEAR(x, val) memset(x, val, sizeof(x))

int tc, e, r, n;
int v[100];
int memo[20][20];

int dp(int id, int sisa) {
	if (memo[id][sisa] != -1)
		return memo[id][sisa];

	if (id == n) 
		return memo[id][sisa] = 0;

	int ret = 0;
	FOR(i, 0, sisa) {
		ret = max(ret, dp(id + 1, min(sisa - i + r, e)) + v[id] * i);
	}	

	return memo[id][sisa] = ret;
}


int main () {
	scanf("%d", &tc);
	FOR(test, 1, tc) {
		CLEAR(memo, -1);

		cin >> e >> r >> n;
		REP(i, n)
			cin >> v[i];

		printf("Case #%d: %d\n", test, dp(0, e));
	}
}








