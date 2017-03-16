#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <set>
#include <cstring>
#include <string>
#define LL long long int

#define FOR(i, s, e) for (int i=(s); i<(e); i++)
#define FOE(i, s, e) for (int i=(s); i<=(e); i++)
#define FOD(i, s, e) for (int i=(s)-1; i>=(e); i--)
#define CLR(x, a) memset(x, a, sizeof(x))

using namespace std;

char s[20], tmp[20];
int mx = 0, TT = 0, test, diff, n, pre;

int dp[4005][5], cnt[20];
char dict[11][220000][11];

int main(){
	FILE *DICT = fopen("garbled_email_dictionary.txt", "r");
	
	CLR(cnt, 0);
	
	while (fscanf(DICT, "%s", tmp) != EOF){
		int l = strlen(tmp);
		sprintf(dict[l][cnt[l]++], "%s", tmp);
	}
	fclose(DICT);
	
	scanf("%d", &test);
	
	FOR(TC, 0, test){
		
		scanf("%s", s);
		n = strlen(s);
		FOR(i, 0, n + 1) FOR(j, 0, 5) dp[i][j] = n + 1;
		dp[0][4] = 0;
		
		FOR(i, 0, n)
		FOR(t, 0, 5){
			
			if (dp[i][t] == n + 1) continue;
			
			FOR(j, 0, 10){
				
				if (i + j >= n) break;
				if (dp[i] == dp[i + j + 1]) continue;
				
				FOR(k, 0, cnt[j + 1]){
					
					diff = 0;
					pre = - t - 1;
					
					FOR(l, 0, j + 1)
						if (dict[j + 1][k][l] != s[i + l]){
							diff++;
							if (l - pre < 5) diff = 100;
							pre = l;
							if (diff > 2) break;
						}
						
					if (diff <= 2){
						pre = min(j - pre, 4);
						dp[i + j + 1][pre] = min(dp[i + j + 1][pre], dp[i][t] + diff);
					}
				}
			}
		}
		
		int ret = n + 1;
		FOR(i, 0, 5) ret = min(dp[n][i], ret);
		printf("Case #%d: %d\n", TC + 1, ret);
		
	}
	return 0;
}
