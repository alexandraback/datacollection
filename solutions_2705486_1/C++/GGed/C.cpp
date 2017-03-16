#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
#define N 5000
#define W 521196
#define INF 100000
using namespace std;

int n, l, x, y, cnt;
char s[N];
char word[W][12];
int dp[N][10], len[W], rem[12][12][12], clr[12];
int st[300][300], ed[300][300];

void solve(int tc){
	printf("Case #%d: ", tc);
	scanf("%s", s);
	n = strlen(s);
	CLR(dp, 63);
	dp[0][4] = 0;
	FOE(i,1,n){
		CLR(rem, 63);
		CLR(clr, 0);
		if (s[i-1] == 'a' || s[i-1] == 'i') clr[1] = 1;
		else rem[1][0][0] = 1;
		FOE(l,2,10){
			if (l > i) continue;
			char c1 = s[i-l], c2 = s[i-l+1];
			
			for (char c='a'; c<='z'; c++){
				FOE(j,st[c][c2],ed[c][c2]){
					if (j == -1) continue;
					if (len[j] != l) continue;
					x = y = -1;
					cnt = 0;
					FOR(k,0,l) if (word[j][k] != s[i-l+k]){
						if (x == -1) x = k;
						else if (k - y < 5) cnt = 99;
						y = k;
						++cnt;
					}
					if (cnt < 99){
						if (x == -1) clr[l] = 1;
						else rem[l][x][y] = min(rem[l][x][y], cnt);
					}
				}
				FOE(j,st[c1][c],ed[c1][c]){
					if (j == -1) continue;
					if (len[j] != l) continue;
					x = y = -1;
					cnt = 0;
					FOR(k,0,l) if (word[j][k] != s[i-l+k]){
						if (x == -1) x = k;
						else if (k - y < 5) cnt = 99;
						y = k;
						++cnt;
					}
					if (cnt < 99){
						if (x == -1) clr[l] = 1;
						else rem[l][x][y] = min(rem[l][x][y], cnt);
					}
				}
			}
		}

		FOE(j,1,10){
			if (i < i) break;
			FOR(k,0,5) if (dp[i-j][k] < INF){
				if (clr[j]){
					int kk = min(4, k + j);
					dp[i][kk] = min(dp[i][kk], dp[i-j][k]);
				}
				FOR(x,0,j) FOR(y,x,j) if (rem[j][x][y] < INF){
					if (x + k < 4) continue;
					int kk = min(4, j - 1 - y);
					dp[i][kk] = min(dp[i][kk], dp[i-j][k] + rem[j][x][y]);
				}
			}
		}
		// FOR(j,0,5) printf("%d|%d =  %d\n", i, j, dp[i][j]);
	}

	int ret = n;
	FOR(i,0,5) ret = min(ret, dp[n][i]);
	printf("%d\n", ret);
}

int main(){
	CLR(st, -1);
	CLR(ed, -1);
	FILE *F = fopen("dict.txt", "r");
	FOR(i,0,W){
		fscanf(F, "%s", word[i]);
		len[i] = strlen(word[i]);
		if (len[i] >= 2){
			char c1 = word[i][0], c2 = word[i][1];
			if (st[c1][c2] == -1) st[c1][c2] = i;
			ed[c1][c2] = i;
		}
	}
	fclose(F);

	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
