#include<iostream>
using namespace std;

const int N= 104;
int a[N][N];
int mp[N][N];

int row[N], col[N];

int findmax(int u, int v){
	if(u > v)
		return u;
	else
		return v;
}

int findmin(int u, int v){
	if(u < v)
		return u;
	else
		return v;
}

int main(){
	freopen("B.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int cas= 1; cas <= t; cas++){
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i= 1; i <= n; i++)
			for(int j= 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		for(int i= 1; i <= n; i++){
			row[i]= 0;
			for(int j= 1; j <= m; j++)
				row[i]= findmax(row[i], a[i][j]);
		}
		for(int j= 1; j <= m; j++){
			col[j]= 0;
			for(int i= 1; i <= n; i++)
				col[j]= findmax(col[j], a[i][j]);
		}
		for(int i= 1; i <= n; i++)
			for(int j= 1; j <= m; j++)
				mp[i][j]= findmin(row[i], col[j]);
		bool flag= true;
		for(int i= 1; i <= n; i++)
			for(int j= 1; j <= m; j++)
				if(mp[i][j] != a[i][j])
					flag= false;
		if(flag)
			printf("Case #%d: YES\n", cas);
		else
			printf("Case #%d: NO\n", cas);
	}
	return 0;
}