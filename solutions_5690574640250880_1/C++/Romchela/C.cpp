#include <bits/stdc++.h>
using namespace std;

typedef long long        ll;
typedef long double      ld;
typedef double           dbl;

#define mp               make_pair
#define pb               push_back
#define sz(x)            (int)(x).size()
#define X                first
#define Y                second
#define all(x)           x.begin(),x.end()
#define y1               y11

#ifdef ROMCHELA
    #define dout(x)        {cout<<#x<<" = ";cout<<(x)<<'\n';}
    #define darr(a, s, n)  {cout<<#a<<" = ";for(int _=s;_<=n;_++)cout<<a[_]<<' ';cout<<'\n';}
    #define dspace()       {for(int _=0;_<10;_++)cout<<'-';cout<<'\n';}
#else
    #define dout(x)        (void)42
    #define darr(a, s, n)  (void)42
    #define dspace()       (void)42
#endif

const int maxn = 100 * 200 + 10;

int r, c, m;
pair<int, int> turn[10] = {mp(0, 1), mp(1, 0), mp(0, -1), mp(-1, 0), mp(1, 1), mp(-1, -1), mp(-1, 1), mp(1, -1)};
bool used[maxn][maxn];
bool correct(int x, int y) {
	return (x >= 0 && y >= 0 && x < r && y < c);
}

int main() {
#ifdef ROMCHELA
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
	int n;
	scanf("%d", &n);
	for (int q = 0; q < n; q++) {
		memset(used, 0, sizeof(used));
		scanf("%d%d%d", &r, &c, &m);

		printf("Case #%d:\n", q + 1);
		int need = r * c - m;
		if (need == 0) {
			printf("Impossible\n");
			continue;
		}
		/*if (m == 1){
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (!i && !j) printf("c");
					else if (i == r - 1 && j == c - 1) printf("*");
					else printf(".");
				}
				puts("");
			}
			continue;
		}*/

		if (m == 0) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++)
					if (!i && !j) printf("c"); else printf(".");
				puts("");
			}
			continue;
		}
		if (need == 1) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (!i && !j) printf("c"); else printf("*");
				}
				puts("");
			}
			continue;
		}

		if (r == 1) {
			for (int i = 0; i < need; i++) 
				if (!i) printf("c");
				else printf(".");
			for (int i = 0; i < m; i++)
				printf("*");
			puts("");
			continue;
		}

		if (c == 1) {
			for (int i = 0; i < need; i++)
				if (!i) printf("c\n");
				else printf(".\n");
			for (int i = 0; i < m; i++)
				printf("*\n");
			continue;
		}

		bool flag = false;
		for (int j = 2; j <= r; j++) {
			for (int p = 2; p <= c; p++) {
				if (j * p == need) {
					for (int i = 0; i < j; i++)
						for (int t = 0; t < p; t++)
							used[i][t] = 1;
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		
		if (!flag) {
			for (int i = 2; i <= r; i++) {
				for (int j = 2; j <= c; j++) {
					if (i * j < need) {
						int diff = need - i * j;
						if (diff == 1) continue;
						int can = 0;
						if (i + 1 <= r) can += j;
						if (j + 1 <= c) can += i;
						if (can >= diff) {
							for (int x = 0; x < j; x++) {
								if (x == 1) continue;
								if (x > 0 && i + 1 > r) continue;
								for (int y = 0; y < i; y++) {
									if (y == 1) continue;
									if (y > 0 && j + 1 > c) continue;
									if (x + y == diff) {
										flag = true;
										for (int ii = 0; ii < i; ii++)
											for (int jj = 0; jj < j; jj++)
												used[ii][jj] = 1;		

										for (int ii = 0; ii < x; ii++)
											used[i][ii] = 1;
										for (int ii = 0; ii < y; ii++)
											used[ii][j] = 1;
									}
								}
								if (flag) break;
							}
						}
					}
					if (flag) break;
				}
				if (flag) break;
			}
		}

		if (!flag) {
			printf("Impossible\n");
			continue;
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (!i && !j) printf("c");
				else if (used[i][j]) printf(".");
				else printf("*");
			}
			puts("");
		}
		

	}

    return 0;
}
