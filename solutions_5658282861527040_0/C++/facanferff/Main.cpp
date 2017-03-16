#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sz(v) (int)v.size()
#define all(c) (c).begin(), (c).end()

typedef long long int ll;

// %I64d for ll in CF

int main() {
	int t;
	scanf("%d", &t);
	int test = 1;
	while (t--) {
		int a, b, k;
		scanf("%d %d %d", &a, &b, &k);
		int res = 0;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if ((i & j) < k) res++;
			}
		}
		printf("Case #%d: ", test);
		printf("%d", res);
		printf("\n");
		test++;
	}
	return 0;
}
