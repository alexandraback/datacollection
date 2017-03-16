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

int tc;
int r, t;
//float a, b;
int tot[1005];

int solve() {
	int i = r;
	int temp = 0;
	int ret = 0;

	//cout << "i = " << i << " tot = " << tot[i] <<endl;
	while (temp + tot[i] <= t) {
		//cout << "temp = " << temp << endl;
		temp += tot[i];
		i += 2;
		ret++;
	}
	return ret;
}

int main () {
	scanf("%d", &tc);
	tot[1] = 3;
	FOR(i, 2, 1000)
		tot[i] = tot[i - 1] + 2;

	FOR(test, 1, tc) {
		scanf("%d %d", &r, &t);

		//a = -1.00 + sqrt(1.00 + 4.00 * t * (r + 1.00));
		//b = 2.00 * (r + 1.00);

		//cout << "a = " << a << endl;
		//cout << "b = " << b << endl;
		//a /= b;
		printf("Case #%d: %d\n", test, solve());
	}
}








