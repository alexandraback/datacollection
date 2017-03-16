#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

int n, cx, cy;
int v[20][20];
double prob[25][20][20];
double ret;

void dfs(int n, double p){
	FOE(i,0,6) FOE(j,0,6){
		if (v[i][j]) prob[n][i][j] += p;
	}
	if (n < 20){
		int m = 0;
		FOE(i,0,6) FOE(j,0,6){
			if (v[i][j]) continue;
			if (i + j == 6){
				int t = i;
				if (t > 3) t = 6 - t;
				if (v[t+1][t+1]) ++m;
			}
			else{
				if (v[i+1][j] && v[i][j+1]) ++m;
			}
		}
		
		FOE(i,0,6) FOE(j,0,6){
			if (v[i][j]) continue;
			if (i + j == 6){
				int t = i;
				if (t > 3) t = 6 - t;
				if (v[t+1][t+1]){
					v[i][j] = 1;
					dfs(n + 1, p * 1. / m);
					v[i][j] = 0;
				}
			}
			else{
				if (v[i+1][j] && v[i][j+1]){
                 	v[i][j] = 1;
					dfs(n + 1, p * 1. / m);
					v[i][j] = 0;
				}
			}
		}
	}
}

void solve(int tc){
	printf("Case #%d: ", tc);
	scanf("%d%d%d", &n, &cx, &cy);

	int sum, diff;
	sum = 6 - cy;
	diff = cx;
	
	cy = (sum + diff) / 2;
	cx = sum - cy;
	
	if (cx < 0 || cy < 0 || cx > 6 || cy > 6) ret = 0.0;
	else ret = prob[n][cx][cy];
	printf("%.9f\n", ret);
}

int main(){
	v[3][3] = 1;
	dfs(1, 1.0);

	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
