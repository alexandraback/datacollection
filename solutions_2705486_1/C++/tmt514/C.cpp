#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define SZ(c) ((int)(c).size())

int cs;
int dp[4005][5];
char s[4005];
string a[531196];
int lens[531196];
int n;
const int INF = 100000;

inline void update(int &x, int v) {
	if(v==-1) return;
	if(x>v||x==-1) x=v;
}
inline int add(int x, int v) {
	if(x==-1||v==-1) return -1;
	return x+v;
}
inline bool match(char *S, string &A, int l, int &dfront, int &dback, int &dtotal) {
	dfront=-1;
	dtotal=0;
	dback=-1;
	int last=-5;
	for(int i=0;i<l;i++)
		if(S[i]!=A[i]) {
			if(dfront==-1) dfront=i;
			dback=l-i-1;
			dtotal++;
			if(i-last<5) return false;
			last=i;
		}
	return true;
}
void solve() {
	scanf("%s", s+1);
	int m = strlen(s+1);
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for(int i=1;i<=m;i++) {
		for(int j=0;j<n;j++) {
			int len = lens[j];
			if(len > i) continue;
			int dfront, dback, dtotal;
			bool ok = match(s+i-len+1, a[j], len, dfront, dback, dtotal);
			if(!ok) continue;
			if(dtotal==0) {
				for(int z=0;z<5;z++) update(dp[i][max(z-len,0)], dp[i-len][z]);
			} else {
				for(int z=0;z<=min(dfront,4);z++) update(dp[i][max(4-dback,0)], add(dp[i-len][z],dtotal));
			}
		}
		for(int z=1;z<5;z++) update(dp[i][z], dp[i][z-1]);
//		for(int z=0;z<5;z++) printf("%5d", dp[i][z]);
//		puts("");
	}
	int best=-1;
	for(int i=0;i<5;i++) update(best, dp[m][i]);
	printf("Case #%d: %d\n", cs, best);
	fprintf(stderr, "Case #%d: %d\n", cs, best);
}

int main(void) {
	int T;
	scanf("%d", &T);
	FILE *file = fopen("dictionary.txt", "r");
	while(fscanf(file, "%s", s)!=EOF) {
		a[n] = string(s);
		lens[n] = strlen(s);
		n++;
	}
	fclose(file);
	for(cs=1;cs<=T;cs++) solve();
	return 0;
}
