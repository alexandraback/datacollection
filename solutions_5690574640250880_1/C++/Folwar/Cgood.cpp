#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

#include<algorithm>
#include<utility>
#include<string>

#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>

using namespace std;

#define FOR(i,N) for (int i = 0; i < (N); i++)
#define FORI(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, b, a) for (int i = (b) - 1; i >= a; i--)
#define DP(arg...) fprintf(stderr, ## arg) //COMPILER SPECIFIC!!!


typedef long long ll;

int t,T;
int R,S,M;

void solve() {
	printf("Case #%d:\n", t);
	if (R == 1) {
		putchar('c');
		FOR(i,S - M - 1) putchar('.');
		FOR(i,M) putchar('*');
		putchar('\n');
		return;
	}
	if (S == 1) {
		putchar('c');
		putchar('\n');
		FOR(i,R - M - 1) { putchar('.'); putchar('\n'); }
		FOR(i,M) { putchar('*'); putchar('\n'); }
		return;
	}
	if (M == 0) {
		FOR(r,R) {
			FOR(s,S) {
				if (r == 0 && s ==0) putchar('c');
				else putchar('.');
			}
			putchar('\n');
		}
		return;
	}
	if (R * S - M == 1) {
		FOR(r,R) {
			FOR(s,S) {
				if (r == 0 && s ==0) putchar('c');
				else putchar('*');
			}
			putchar('\n');
		}
		return;
	}

	if (R * S - M == 2 || R * S - M == 3)
		goto bad;


	if (R == 2) {
		if ((R * S - M) % 2 == 1)
			goto bad;
		int l = (R * S - M) / 2;
		putchar('c');
		FOR(i,l-1) putchar('.');
		FOR(i,M/2) putchar('*');
		putchar('\n');
		FOR(i,l) putchar('.');
		FOR(i,M/2) putchar('*');
		putchar('\n');
		return;
	}
	if (S == 2) {
		if ((R * S - M) % 2 == 1)
			goto bad;
		int l = (R * S - M) / 2;
		putchar('c'); putchar('.'); putchar('\n');
		FOR(i,l-1) printf("..\n");
		FOR(i,M/2) printf("**\n");
		return;
	}

	if (R * S - M == 5 || R * S - M == 7)
		goto bad;
	
	{
		int xo = R * S - M;
		bool liche = xo % 2;

		if (liche) xo -= 3;
		if (xo <= 2*S) {
			putchar('c');
			for (int i = 1; i < xo/2; i++)
				putchar('.');
			for (int i = 0; i < S-xo/2; i++)
				putchar('*');
			putchar('\n');
			for (int i = 0; i < xo/2; i++)
				putchar('.');
			for (int i = 0; i < S - xo/2; i++)
				putchar('*');
			putchar('\n');
			if (liche) {
				printf("...");
				FOR(s,S-3) putchar('*');
				putchar('\n');
			}
			else {
				FOR(s,S) putchar('*');
				putchar('\n');
			}
			FOR(r,R-3) {
				FOR(s,S) putchar('*');					
				putchar('\n');
			}
		}
		else {
			if (liche) xo += 3;
			putchar('c');
			for (int i = 1; i < S; i++)
				putchar('.');
			putchar('\n');
			xo -= S;
			if (xo % S == 1) {
				int Rx = xo / S;
				FOR(r,Rx-1) {
					FOR(s,S) putchar('.');
					putchar('\n');
				}
				FOR(s,S-1) putchar('.');
				putchar('*'); putchar('\n');
				printf("..");
				FOR(s,S-2) putchar('*');
				putchar('\n');
				FOR(r,R - Rx - 2) {
					FOR(s,S) putchar('*');					
					putchar('\n');
				}
			}
			else {
				FOR(r,R-1) {
					FOR(s,S) {
						if (xo) { putchar('.'); xo--; }
						else putchar('*');
					}
					putchar('\n');
				}
			}

		}
		return;
	}

	bad:
	printf("Impossible\n");

}

int main() {
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d%d%d", &R, &S, &M);
		solve();
	}
	return 0;
}
