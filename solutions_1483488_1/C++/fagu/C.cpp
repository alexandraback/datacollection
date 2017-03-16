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

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		int A, B;
		scanf("%d %d", &A, &B);
		ll erg = 0;
		for (int n = A; n < B; n++) {
			int e = 1, d = 0;
			while(e <= n) {
				e *= 10;
				d++;
			}
			e /= 10;
			int m = n;
			set<int> se;
			for (int k = 1; k < d; k++) {
				m = m/10 + (m%10)*e;
				if (n < m && m <= B)
					se.insert(m);
			}
			erg += se.size();
		}
		printf("%lld\n", erg);
	}
	return 0;
}
