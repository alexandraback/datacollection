#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std; 

#define f first
#define s second
#define mp make_pair
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define forit(it,S) for(__typeof(S.begin()) it = S.begin(); it != S.end(); ++it)
#ifdef WIN32
	#define I64d "%I64d"
#else
	#define I64d "%lld"
#endif

const int inf = int(1e9);
typedef pair <int, int> pi;
int n, a[1111111];

int main() {
	int tests;
	scanf("%d", &tests);	
	for (int casenum = 1; casenum <= tests; ++casenum) {
		int x;
		scanf("%d%d", &x, &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);

		int res = n, cur = 0;
		sort(a, a + n);
		
		for (int i = 0; i < n; ++i) {
			res = min(res, cur + n - i);
			if (x == 1) break;
			while (x <= a[i]) {
				x = x + x - 1;
				++cur;
				if (x > inf) x = inf;				
			}
			x += a[i];
			res = min(res, cur + n - i - 1);
			if (x > inf) x = inf;	
		}	
		             
		printf("Case #%d: %d\n", casenum, res);
	}
	return 0;		
}
