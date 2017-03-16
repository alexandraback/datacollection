#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

int T, A, B;
double P[110000], prod[110000];

int main() {
	scanf("%d", &T);
	FOR(cs, 1, T+1) {
		scanf("%d%d", &A, &B);
		FOR(i, 0, A) scanf("%lf", &P[i]);
		prod[0] = 1;
		FOR(i, 1, A+1) prod[i] = prod[i-1] * P[i-1];
		double res = min(prod[A] * (B-A+1) + (1 - prod[A]) * (2*B-A+2), (double)B+2);
		FOR(i, 0, A) res = min(res, prod[i] * (A-i+B-i+1) + (1 - prod[i]) * (A-i+B-i+1+B+1));
		printf("Case #%d: %.8lf\n", cs, res);
	}
	return 0;
}
