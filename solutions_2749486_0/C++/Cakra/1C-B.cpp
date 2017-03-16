#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cassert>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define sz(a) int((a).size())
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(c) (c).begin(),(c).end()
#define uniq(c) sort(all((c))); (c).resize(unique(all((c))) - (c).begin())
#define lobo(c, x) (int) (lower_bound(all((c)), (x)) - (c).begin())
#define upbo(c, x) (int) (upper_bound(all((c)), (x)) - (c).begin())
#define mii(a, b) if(b < a) a = b
#define maa(a, b) if(b > a) a = b

#define INF 2000000000
#define EPS 1e-5
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define X first
#define Y second
#define DEBUG(x) printf("debugging.. %d\n", x);
#ifdef TEST
#define deb(...) fprintf(stderr, __VA_ARGS__)
#else 
#define deb(...)
#endif
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

string tobin(int x, int len) {
	string c;
	while(x) { c.PB(x%2+'0'); x /= 2; }
	while(sz(c) < len) c.PB('0');
	reverse(all(c));
	return c;
}
//------------------------------

int T, x, y;

int main() {
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; tc++) {
		scanf("%d%d", &x, &y);
		
		printf("Case #%d: ", tc+1);
		
		// horizontal
		for(int i = 0, bnd = abs(x); i < bnd; i++) {
			if(x > 0) {
				printf("WE");
			}
			else {
				printf("EW");				
			}
		}
		
		// vertical
		for(int i = 0, bnd = abs(y); i < bnd; i++) {
			if(y > 0) {
				printf("SN");
			}
			else {
				printf("NS");				
			}
		}
		
		puts("");
	}
	
	return 0;
}
