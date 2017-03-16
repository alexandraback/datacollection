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

int T;
ll A, B;
vector <ll> fs;

int main() {
	fs.PB(1LL);
	fs.PB(4LL);
	fs.PB(9LL);
	fs.PB(121LL);
	fs.PB(484LL);
	fs.PB(10201LL);
	fs.PB(12321LL);
	fs.PB(14641LL);
	fs.PB(40804LL);
	fs.PB(44944LL);
	fs.PB(1002001LL);
	fs.PB(1234321LL);
	fs.PB(4008004LL);
	fs.PB(100020001LL);
	fs.PB(102030201LL);
	fs.PB(104060401LL);
	fs.PB(121242121LL);
	fs.PB(123454321LL);
	fs.PB(125686521LL);
	fs.PB(400080004LL);
	fs.PB(404090404LL);
	fs.PB(10000200001LL);
	fs.PB(10221412201LL);
	fs.PB(12102420121LL);
	fs.PB(12345654321LL);
	fs.PB(40000800004LL);
	fs.PB(1000002000001LL);
	fs.PB(1002003002001LL);
	fs.PB(1004006004001LL);
	fs.PB(1020304030201LL);
	fs.PB(1022325232201LL);
	fs.PB(1024348434201LL);
	fs.PB(1210024200121LL);
	fs.PB(1212225222121LL);
	fs.PB(1214428244121LL);
	fs.PB(1232346432321LL);
	fs.PB(1234567654321LL);
	fs.PB(4000008000004LL);
	fs.PB(4004009004004LL);
	fs.PB(100000020000001LL);
	fs.PB(100220141022001LL);
	fs.PB(102012040210201LL);
	fs.PB(102234363432201LL);
	fs.PB(121000242000121LL);
	fs.PB(121242363242121LL);
	fs.PB(123212464212321LL);
	fs.PB(123456787654321LL);
	fs.PB(400000080000004LL);

	scanf("%d", &T);
	
	for(int tc = 0; tc < T; tc++) {
		scanf("%lld%lld", &A, &B);
		
		int lobo = (int) (lower_bound(all(fs), A) - fs.begin()),
			upbo = (int) (upper_bound(all(fs), B) - fs.begin());
		
		printf("Case #%d: %d\n", tc+1, upbo-lobo);
	}
	
	return 0;
}
