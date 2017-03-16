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

const int MXL = 1000000;
int T, n, len;
char s[MXL+5];
int sum[MXL+5];

char vow[] = {'a', 'e', 'i', 'o', 'u'};

bool isConst(char c) {
	for(int i = 0; i < 5; i++)
		if(vow[i] == c) return false;
	return true;
}

inline int query(int l, int r) {
	if(l > r) return 0;
	return sum[r] - (l-1 >= 0 ? sum[l-1] : 0);
}

int main() {
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; ++tc) {
		scanf("%s%d", &s, &n);
		
		len = strlen(s);
		
		memset(sum, 0, sizeof(sum));
		
		for(int i = 0; i < len; i++) {
			if(isConst(s[i]))
				s[i] = 1;
			else
				s[i] = 0;
		}
		
		int last = -1, cons = 0;
		for(int i = 0; i < len; i++) {
			if(s[i] == last) {
				if(s[i] == 1)	cons++;
				else			cons = 0;
			}
			else {
				if(s[i] == 1)	cons = 1;
				else			cons = 0;
			}
			
			if(cons >= n) {
				sum[i] = 1;
			}
			
//			printf("~~i=%d, s=%d, last=%d, cons=%d, n=%d, sum=%d\n", i, s[i], last, cons, n, sum[i]);
						
			last = s[i];
		}
		
//		for(int i = 0; i < len; i++) printf("i=%d, s=%d, sum=%d\n", i, s[i], sum[i]); puts("");
		
		for(int i = 1; i < len; i++)
			sum[i] += sum[i-1];
		
//		for(int i = 0; i < len; i++) printf("sum[%d]=%d\n", i, sum[i]);
		
		int le = 0, ri = 0;
		ll ans = 0;
		while(ri < len) {
			while(ri < len && query(le+n-1, ri) == 0) ri++;
//			printf("~le=%d, ri=%d, sum=%d, len=%d\n", le, ri, query(le, ri), len);
			
			if(ri == len) break;
			
			ans += len-ri;
			
			le++;
		}	
		
		printf("Case #%d: %lld\n", tc+1, ans);
	}
	
	return 0;
}
