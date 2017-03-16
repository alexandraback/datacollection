#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007

bool isSwaped;
char A[233][233];
int n,m,k;
void output() {
	if (isSwaped) {
		For(i,1,m) { 
			For(j,1,n) putchar(A[j][i]);
			puts("");
		}
	} else {
		For(i,1,n) {
			For(j,1,m) putchar(A[i][j]);
			puts("");
		}
	}
}

int main() {
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int T; cin >> T;
	For(TTT,1,T) {
		printf("Case #%d:\n",TTT);
		cin >> n >> m >> k;
		// n row m col k mines
		isSwaped = false;
		if (n > m) {
			isSwaped = true;
			swap(n,m);
		}
		if (n * m - k == 1) {
			For(i,1,n) For(j,1,m) A[i][j] = '*';
			A[1][1] = 'c';
			output();
			continue ;
		}
		if (n == 1) {
			A[1][1] = 'c';
			For(i,2,m - k) A[1][i] = '.';
			For(i,m - k + 1,m) A[1][i] = '*';
			output();
			continue ;
		}
		if (n == 2) {
			if (k % 2 || (m - k / 2 <= 1)) puts("Impossible");
			else {
				int t = m - k / 2;
				For(i,1,n) {
					For(j,1,t) A[i][j] = '.';
					For(j,t + 1,m) A[i][j] = '*';
				}
				A[1][1] = 'c';
				output();
			}
			continue ;
		}
		int numBlank = n * m - k;
		if (numBlank <= 3) {
			puts("Impossible");
			continue ;
		}
		bool hassol = false ;
		For(i,1,n) if (numBlank % i == 0) {
			int x = i, y = numBlank / i;
			if (1 < x && x <= n && 1 < y && y <= m) {
				For(i,1,n) For(j,1,m) A[i][j] = '*';
				For(i,1,x) For(j,1,y) A[i][j] = '.';
				A[1][1] = 'c';
				output();
				hassol = true; break ;
			}
		}
		if (hassol) continue ;
		For(x,3,n) {
			For(y,3,m) if (x * y >= numBlank) {
				int rem = k - (n * m - x * y);
				if (rem <= x + y - 5) {
					For(i,1,n) For(j,1,m) A[i][j] = '*';
					For(i,1,x) For(j,1,y) A[i][j] = '.';
					Cor(i,x,3) if (rem) A[i][y] = '*', --rem;
					Cor(i,y - 1,3) if (rem) {
						A[x][i] = '*';
						--rem;
					}
					A[1][1] = 'c';
					output();
					hassol = true; break ;
				}
			}
			if (hassol) break ;
		}
		if (!hassol) puts("Impossible");
	}		
	return 0;
}

