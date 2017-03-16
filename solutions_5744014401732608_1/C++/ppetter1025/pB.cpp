#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MAXN = 50 + 10;

int e[MAXN][MAXN];

int main() {
	int t;
	scanf("%d", &t);
	for(int kase=1; kase<=t; kase++) {
		ll b, m;
		scanf("%lld%lld", &b, &m);

		ll x = 1ll << (b-2);
		printf("Case #%d: ", kase);
		if(x < m) {
			puts("IMPOSSIBLE");
			continue;
		}
		
		puts("POSSIBLE");
		m = x-m;
		fill(e[0], e[b+1], 0);
		for(int i=1; i<=b; i++)
			for(int j=i+1; j<=b; j++)	e[i][j] = 1;

		for(int i=b-1; i>1; i--) {
			if((m >> (i-2)) & 1) {
				e[i][b] = 0;
			}
		}

		for(int i=1; i<=b; i++) {
			for(int j=1; j<=b; j++)	printf("%d", e[i][j]);
			putchar('\n');
		}
	}
    
    return 0;
}
