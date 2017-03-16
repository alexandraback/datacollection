#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 1e2 + 11;
char P[N];
char key[N];
int next[N];
int n;
int cp[N][N];
double p[N][N];
double dp[N][N];
int f[N][N];
double dfs(int cur, int step){
	if(f[cur][step])	return dp[cur][step];
	f[cur][step] = 1;
	if(step==0){
		if(cur==n)	return dp[cur][step] = 1.0;
		else	return dp[cur][step] = 0.0;
	}
	double ans = cur==n;
	for(int i=0; i<=n; i++){
		ans += p[cur][i] * dfs(i, step-1);
		// ans += i==n;
	}
	return dp[cur][step] = ans;
}
void cal_next()
{
    next[1] = 0;
    int k = 0;
    for(int i=2; i<=n; i++)
    {
        while(k>0 && P[k+1]!=P[i])  k = next[k];
        if(P[k+1]==P[i])    k++;
        next[i] = k;
    }
}
void get_p(){
	// for(int i=0; i<=n; i++){
	// 	printf("%d ", next[i]);
	// }
	// printf("%s\n", P+1);
	// printf("%s\n", key);
	// printf("end\n");
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			p[i][j] = 0.0;
			cp[i][j] = 0;
		}
		for(int j=0; key[j]; j++){
			int k = i;
			// printf("P[k+1]:%c\n", P[k+1]);
			// if(P[k+1]==key[j])
			// printf("%c %c\n", P[k+1], key[j]);
			while(k>0 && P[k+1]!=key[j])  k = next[k];
			if(P[k+1]==key[j])	k++;
			p[i][k] += 1.0;
			cp[i][k] += 1;
			// break;
			// printf("%d %d\n", i, k);
		}
	}
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			p[i][j] /= strlen(key);
			// printf("%d ", cp[i][j]);
		}
		// printf("\n");
	}
}
int get_max(int step){
	int c[33];
	memset(c, 0, sizeof(int)*33);
	for(int i=1; i<=n; i++){
		int k = P[i] - 'A';
		c[k] = 1;
	}
	for(int i=0; key[i]; i++){
		int k = key[i] - 'A';
		c[k] = 0;
	}
	for(int i=0; i<26; i++){
		if(c[i])	return 0;
	}
	int cur = n;
	int ans = 1;
	for(int k=n; k<step; k++){
		int t;
		for(int i=n; i>=0; i--){
			if(cp[cur][i]){
				t = i;
				break;
			}
		}
		cur = t;
		if(cur==n)	ans++;
	}
	return ans;
}
int main()
{
	// freopen("in.txt", "r", stdin);
	// freopen("bb.txt", "w", stdout);
	int t, kase=0;
	scanf("%d", &t);
	while(t--){
		int K, L, S;
		scanf("%d%d%d", &K, &L, &S);
		scanf("%s", key);
		scanf("%s", P+1);
		n = strlen(P+1);
		cal_next();
		get_p();
		memset(f, 0, sizeof(f));
		printf("Case #%d: %.7f\n", ++kase, get_max(S) - dfs(0, S));
	}
	return 0;
}