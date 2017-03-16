#include <cmath>
#include <cstdio>
typedef long long LL;

const int M = 1e3, N = 50;
int T, n, J;
LL a[N], ans1[M][N], ans2[M][N], div[11];

void Dfs(int num){
	if(J == 0) return;
	if(num == n){
		bool b = 1;
		for(int i = 2; i <= 10; i ++){
			LL t = 0, tt = 1;
			for(int j = n; j >= 1; j --)
				{t += tt * a[j]; tt *= i;}
			div[i] = 0;
			for(int j = 2; j <= floor(sqrt(t)); j ++)
				if(t % j == 0){div[i] = j; break;}
			if(div[i] == 0){b = 0; break;}
		}
		if(b){
			for(int i = 2; i <= 10; i ++) ans1[J][i] = div[i];
			for(int i = 1; i <= n; i ++) ans2[J][i] = a[i];
			J--;
		}
		return;
	}
	
	Dfs(num + 1);
	a[num] = 1;
	Dfs(num + 1);
	a[num] = 0;
}

int main(){
	freopen("c.in", "r", stdin), freopen("c.out", "w", stdout);
	
	scanf("%d", &T);
	scanf("%d %d", &n, &J);
	int J2 = J;
	printf("Case #1: \n");
	
	a[1] = a[n] = 1;
	Dfs(2);
	for(int i = 1; i <= J2; i ++){
		for(int j = 1; j <= n; j ++) printf("%d", ans2[i][j]);
		for(int j = 2; j <= 10; j ++) printf(" %d", ans1[i][j]);
		printf("\n");
	}
	
	return 0;
}