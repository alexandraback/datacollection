#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <algorithm>

#define sz(a) int((a).size())
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(c) (c).begin(),(c).end()
#define INF 2000000000
#define EPS 1e-5
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define X first
#define Y second
#define DEBUG(x) printf("debugging.. %d\n", x);
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int MXN = 1000;
int T, n, a[MXN+5], b[MXN+5];

int ans, star, done[MXN+5], s1[MXN+5];

bool rampung() {
	for(int i = 0; i < n; ++i)
		if(!done[i])
			return 0;
			
	return 1;
}

ii cari() {
	// 2 star murni
	for(int i = 0; i < n; ++i)
		if(!done[i] && !s1[i] && b[i] <= star)
			return ii(i, 2);
			
	// 2 star --
	for(int i = 0; i < n; ++i)
		if(!done[i] && b[i] <= star)
			return ii(i, 2);
			
	// 1 star
	int ma = -INF, idx = -1;
	for(int i = 0; i < n; ++i)
		if(!done[i] && !s1[i] && a[i] <= star) {
			if(b[i] > ma) {
				ma = b[i];
				idx = i;
			}
		}
		
	if(ma != INF) return ii(idx, 1);
			
	return ii(-1, -1);
}

int main() {
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; ++tc) {
		printf("Case #%d: ", tc + 1);
		
		scanf("%d", &n);
		
		for(int i = 0; i < n; ++i)
			scanf("%d%d", &a[i], &b[i]);
			
		
		ans = 0;
		star = 0;
		memset(done, 0, sizeof(done));
		memset(s1, 0, sizeof(s1));
		
		while(true) {
			ii id = cari();
//			printf("id=(%d,%d)=(%d, %d), star=%d, ans=%d\n", id.F, id.S, a[id.F], b[id.F], star, ans);
			if(id.F == -1) { ans = -1; break; }
			
			if(id.S == 1) {	// star 1
				star++;
				ans++;
				
				s1[id.F] = 1;
			}
			else {	// star 2
				if(s1[id.F])	star++;
				else			star += 2;
				
				ans++;
				
				done[id.F] = 1;
			}
			
			if(rampung()) break;
		}
		
		if(ans == -1) 	printf("Too Bad\n");
		else			printf("%d\n", ans);
	}
	
	return 0;
}
