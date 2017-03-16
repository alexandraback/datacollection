#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)
#define FORD(i,a,b) for(int i=int(a)-1; i>=int(b); --i)
#define FORE(i,q) for(typeof((q).begin()) i=(q).begin(); i!=(q).end(); ++i)
using namespace std;

typedef long long LG;
typedef long double LD;

int a, n;
int T[1234567];
int R[111];
const int INFTY = 1234567;

void testcase(int zzz) {
	int res = 0;
	scanf("%d%d", &a, &n);
	FOR(i,0,n) scanf("%d", T + i);
	sort(T, T + n);
	FOR(i,0,n) R[i] = INFTY;
	FOR(i,0,n) {
		if(T[i] < a) {
			a += T[i];
		} else {
			if(T[i] < 2 * a - 1) {
				a += a - 1 + T[i];
				++res;
			} else {
				R[i] = res + n - i;
				while(T[i] >= a) {
					a += a - 1;
					++res;
					if(res > R[i]) goto out;
				}
				a += T[i];
			}
		}
	}
	out:
	FOR(i,0,n) res = min(res, R[i]);
	printf("Case #%d: %d\n", zzz, res);
}

int main() {
	int ZZZ; scanf("%d", &ZZZ);
	FOR(zzz,0,ZZZ) testcase(zzz + 1);
	return 0;
}
