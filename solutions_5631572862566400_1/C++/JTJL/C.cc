#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2001;

//bitset<1001> f[MAXN][MAXN], cc; 
int a[MAXN];
int vis[MAXN], _vis[MAXN];
int in[MAXN];
int ed[MAXN][MAXN];
int md[MAXN][2];

int main(){
	freopen("Cl.in", "r", stdin);
	freopen("Cl.out", "w", stdout);
	int T, n, m;
	cin>>T;
	for(int o = 1; o <= T; o++){
		printf("Case #%d: ", o);
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			for(int j = 0; j <= n; j++)
				ed[i][j] = 0;
		for(int i = 1; i <= n; i++)
			in[i] = 0, vis[i] = 0, md[i][0] = md[i][1] = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			in[a[i]]++;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
			if (!in[i]){
				for(int j = 1; j <= n; j++)
					_vis[j] = 0;
				int x = i, now = 1, pr = 0, prpr = 0, prprpr = 0;
				while(!_vis[x]){
					vis[x] = 1;
					_vis[x] = now;
					now++;
					prprpr = prpr;
					prpr = pr;
					pr = x;
					x = a[x];
				}
				ans = max(ans, now - _vis[x]);
				if (now - _vis[x] == 2){
			//		ed[x][prprpr] = max(ed[x][prprpr], now - 1);
					ed[a[x]][prprpr] = max(ed[a[x]][prprpr], now - 1);
					ed[x][0] = max(ed[x][0], 2);
					/*
					if (now - 1 >= ed[x][0]){
						ed[x][1] = ed[a[x]][1] = ed[x][0];
						ed[x][0] = ed[a[x]][0] = now - 1;
					}
					else{
						if (now - 1 >= ed[x][1])
						ed[x][1] = ed[a[x]][1] = now - 1;
					}*/
				}
			}
		for(int i = 1; i <= n; i++)
			if (!vis[i]){
				int x = i, now = 0;
				while(!vis[x]){
					vis[x] = 1;
					now++;
					x = a[x];
				}
				ans = max(ans, now);
				if (now == 2){
					ed[x][0] = 2;
					ed[a[x]][0] = 2;
				}
			}
		int sum = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= n; j++){
				if (ed[i][j] >= md[i][0]){
					md[i][1] = md[i][0];
					md[i][0] = ed[i][j];
				}
				else
					if (ed[i][j] > md[i][1])
						md[i][1] = ed[i][j];
			}
		/*	if (md[i][0] >= 2){
				if (md[i][0] > md[a[i]][0])
					sum += md[i][0] - md[a[i]][0];
			}*/
		//	cout<<md[i][0]<<' '<<md[i][1]<<endl;	
		}
	//	sum /= 2;
		for(int i = 1; i <= n; i++)
			if (md[i][0] >= 2){
				sum += md[i][0] + md[a[i]][0] - 2;
				//sum = max(sum, md[i][0] + md[a[i]][0] - 2);
			}
		sum /= 2;
		ans = max(ans, sum);
		/*
		int c2 = 0;
		cc.set();
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
				f[i][j].reset(), f[i][j].set(j), vis[j] = 0;
			vis[i] = 1;
			int x = i;
			while(!vis[a[x]]){
				f[i][a[x]] |= f[i][x];
				vis[a[x]] = 1;
				x = a[x];
			}
			ans = max(ans, (int)(f[i][x].count() - f[i][a[x]].count() + 1));
			if (a[a[x]] == x){
				cc.reset(x), cc.reset(a[x]);
			}
			if (a[x] != i && a[a[x]] != x)
				for(int j = 1; j <= n; j++)
					f[i][j].reset();
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
				if (f[j][i].count() > 1)
					for(int k = 1; k <= n; k++)
						if ((f[j][i] & f[k][i]).count() == 1)
							ans = max(ans, (int)(f[j][i].count() + f[k][i].count() - 1 + (n - (cc | (f[j][i] | f[k][i])).count())));
		}*/
		printf("%d\n", ans);
	}
	return 0;
} 

