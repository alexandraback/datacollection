#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int t, m, a[1001], f[1001][1001], n;

void init(){
	memset(f,127,sizeof(f));
	for(int bar = 1; bar <= 1000; bar++)
		for(int i = 0; i <= 1000; i++)
			if(i<=bar)
				f[bar][i]=0;
			else{
				for(int j = 1; j<= i - 1; j++)
					f[bar][i] = min(f[bar][i], f[bar][j] + f[bar][i-j] + 1);
			}
}

int reduceNum(int bar){
	int ans = 0;
	for(int i = 1; i<= n; i++)
		ans+=f[bar][a[i]];
	return ans;
}

void solve(){
	int ans = 2000000000;
	for(int i = 1; i<=m; i++){
		ans = min(ans, i + reduceNum(i));
	}
	printf("%d\n", ans);
}

int main(){
	freopen("t2.in","r",stdin);
	freopen("t2.out","w",stdout);
	init();
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		m = 0;
		printf("Case #%d: ", i);
		scanf("%d",&n);
		for(int j = 1; j <= n; j++){
			scanf("%d", &a[j]);
			m = max(m, a[j]);
		}
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
