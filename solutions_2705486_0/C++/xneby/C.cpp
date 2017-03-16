#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 521196;
//const int N = 2;

char ss[N][20];
int len[N];

char s[57];
int dp[57][5];

int test(){
	scanf("%s", s);
	int l = strlen(s);

	for(int i=0; i<l; i++) for(int j=0; j<5; j++) dp[i][j] = 57;
	for(int i=0; i<5; i++) dp[l][i] = 0;

	for(int i=l-1; i>=0; i--){
		for(int j=0; j<5; j++){
			for(int t=0; t<N; t++){
				if(len[t] + i > l) continue;
				bool ok = true;
				for(int x=0; x < min(len[t], j); x++){
					if(s[x+i] != ss[t][x]){
						ok = false;
						break;
					}
				}
				if(!ok) continue;
				if(j >= len[t]){
					dp[i][j] = min(dp[i][j], dp[i+len[t]][j - len[t]]);
				} else {
					int last = -5;
					int roz = 0;
					for(int x = j; x < len[t]; x++){
						if(s[x+i] == ss[t][x]) continue;
						if(last + 5 > x){
							ok = false;
							break;
						}
						last = j;
						roz ++;
					}
					if(!ok) continue;
					int st = max( 5  - len[t] + last, 0);
					dp[i][j] = min(dp[i][j], dp[i+len[t]][st]+roz);
				}
			}
//			printf("%d %d %d\n", i, j, dp[i][j]);
		}
	}
	return dp[0][0];
}

int main(){
	FILE* file = fopen("garbled_email_dictionary.txt", "r");
	for(int i=0; i<N; i++){
		fscanf(file, "%s", ss[i]);
		len[i] = strlen(ss[i]);
	}
	fclose(file);

	int t;
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		printf("Case #%d: %d\n", i, test());
	}
}
