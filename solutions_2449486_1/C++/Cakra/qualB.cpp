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

int T, N, M, a[105][105];

int main() {
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; tc++) {
		scanf("%d%d", &N, &M);
		
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				scanf("%d", &a[i][j]);
		
		bool used[105][105];
		memset(used, false, sizeof(used));
		
		// baris
		for(int i = 0; i < N; i++) {
			int ma = -1;
			for(int j = 0; j < M; j++)
				ma = max(ma, a[i][j]);
			
			for(int j = 0; j < M; j++)
				if(a[i][j] == ma)
					used[i][j] = true;
		}
		
		// kolom
		for(int j = 0; j < M; j++) {
			int ma = -1;
			for(int i = 0; i < N; i++)
				ma = max(ma, a[i][j]);
			
			for(int i = 0; i < N; i++)
				if(ma == a[i][j])
					used[i][j] = true;
		}
		
		bool valid = true;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				if(!used[i][j])
					valid = false;
		
		printf("Case #%d: %s\n", tc+1, valid ? "YES" : "NO");
	}
	
	return 0;
}
