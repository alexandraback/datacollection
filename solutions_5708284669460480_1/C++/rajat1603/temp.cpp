#include<bits/stdc++.h>
#define author rajat1603
#define pb push_back
#define mp make_pair
using namespace std;
const int mod = 1e9 + 7;
int lps[105];//FROM GEEKS for GEEKS
void cla(string pat, int len){
	int i = 1, j = 0;
	lps[0] = 0;
	while(i < len){
		if(pat[i] == pat[j]){
			j++;
			lps[i] = j;
			i++;
		}
		else{
			if(j != 0)
				j = lps[j - 1];
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
}
double dp[105][105];
int dp2[105][105];
int n, m, s;
string a,b;
double solve(int pos, int pre){
	if(dp[pos][pre] != -1.0)
		return dp[pos][pre];
	if(pos == s)
		return 0.0;
	double res = 0.0;
	int i;
	for(int i = 0;i<n;++i){
		double val = 0.0;
		int tmp = pre;
		while((b[tmp] != a[i]) && tmp > 0)
			tmp = lps[tmp - 1];
		if(tmp == 0 && b[0] != a[i])
			tmp = 0;
		else
			tmp++;
		if(tmp == m){
			val = 1.0;
			tmp = lps[tmp - 1];
		}
		res = res + (1.0 / n) * (val + solve(pos + 1, tmp));
	}
	return dp[pos][pre] = res;
}
int solve1(int pos, int pre){
	if(dp2[pos][pre] != -1)
		return dp2[pos][pre];
	if(pos == s)
		return 0;
	int res = 0;
	for(int i = 0;i<n;++i){
		int val = 0;
		int tmp = pre;
		while((b[tmp] != a[i]) && tmp > 0)
			tmp = lps[tmp - 1];
		if(tmp == 0 && b[0] != a[i])
			tmp = 0;
		else
			tmp++;
		if(tmp == m){
			val = 1;
			tmp = lps[tmp - 1];
		}
		res = max(res, val + solve1(pos + 1, tmp));
	}
	return dp2[pos][pre] = res;
}
int main(){
	int t;
	cin>>t;
	int tc = 0;
	while(t--){
		printf("Case #%d: ",++tc);
		cin>>n>>m>>s;
		cin>>a>>b;
		for(int i =0;i<105;++i){
			for(int j= 0;j<105;++j){
				dp[i][j]=-1.0;
				dp2[i][j] = -1;
			}
		}
		cla(b, b.length());
		double res1 = solve(0, 0);
		int res2 = solve1(0, 0);
		double res3 = fabs(res2 * 1.0 - res1);
		printf("%.6lf\n", res3);
	}
}