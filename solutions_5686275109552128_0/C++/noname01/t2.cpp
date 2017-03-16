#include<iostream>
#include<cstdio>
using namespace std;

int t, a[10001], n, res;

void solve(){

	int u, m = 0, tm = 0, ans = 2000000000, t = 0;


	for(int i = 1; i <= n; i++)
		if(a[i]>m){
			m=a[i];
			u=i;
			tm=1;
		}
		else if(a[i]==m)
			tm++;
	ans = min(ans, m);


	while(m>1){
//		if(m % 2 == 1){
//			for(int i = 1; i <= n; i++)
//				a[i]--;
//			t++;
//
//			m = 0; tm = 0;
//			for(int i = 1; i <= n; i++)
//				if(a[i]>m){
//					m=a[i];
//					u=i;
//				}
//			ans = min(ans, m+t);
//			continue;
//		}
		a[u]=(a[u]+1)/2;
		t++;
		m = 0; tm = 0;
		for(int i = 1; i <= n; i++)
			if(a[i]>m){
				m=a[i];
				u=i;
			}
		ans = min(ans, m+t);

	}
	printf("%d\n",ans);


}

void dfs(int t){
	//printf("%d %d\n",t,n);
	if(t >= res) return;
	int m = -1, u;
	for(int i = 1; i <= n; i++)
		if(a[i]>m){
			m=a[i];
			u=i;
		}
	if(m == 0){
		res = min(res, t);
		return;
	}
	for(int i = 1; i <= n; i++)
		a[i]--;
	dfs(t+1);
	for(int i = 1; i <= n; i++)
		a[i]++;

	if(m <= 1) return;
	int temp = a[u];
	for(int i = 1; i <= a[u] - 1; i++){
		a[u] = i;
		n++;
		a[n]=m-i;
		dfs(t+1);
		a[u] = temp;
		a[n]=0;
		n--;
	}
}

int main(){
	freopen("t2.in","r",stdin);
	freopen("t2.out","w",stdout);
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		res = 2000000000;
		printf("Case #%d: ", i);
		scanf("%d", &n);
		for(int j = 1; j <= n; j++)
			scanf("%d", &a[j]);
//		solve();
		dfs(0);
		printf("%d\n", res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
