#include <cstdio>
#include <cstring>
struct rec{int x,y;};
rec b[910];
int a[30][30] = {{0}},d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool v[30][30];
int f[30][30][30] = {{{0}}},t,n,m,k,ans;
int max(int a,int b){
	return a > b ? a : b;
}
int count(int n,int m){
	memset(v,0,sizeof v);
	int p,q,x,y;
	p = q = 1;
	b[1].x = 0;
	b[1].y = 0;
	v[0][0] = 1;
	while (p <= q){
		for (int k = 0;k < 4;k++){
			x = b[p].x + d[k][0];
			y = b[p].y + d[k][1];
			if (x < 0 || x > n + 1 || y < 0 || y > m + 1 || v[x][y] || a[x][y]) continue;
			v[x][y] = 1;
			q++;
			b[q].x = x;
			b[q].y = y;
		}
		p++;
	}
	int ret = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++) if (!v[i][j]) ret++;
	return ret;
}
int num(int n,int m){
	int ret = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++) ret += a[i][j];
	return ret;
}
void put(int n,int m,int x,int y,int k){
	a[x][y] = k;
	if (x == n && y == m){
		int p = count(n,m),q = num(n,m);
		if (f[n][m][q] < p) f[n][m][q] = p;
		return;
	}
	if (y < m){
		put(n,m,x,y + 1,0);
		put(n,m,x,y + 1,1);
	}else{
		put(n,m,x + 1,1,0);
		put(n,m,x + 1,1,1);
	}
}
void work(int n,int m){
	put(n,m,1,1,0);
	put(n,m,1,1,1);
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	for (int i = 1;i <= 4;i++)
		for (int j = i;i * j <= 20;j++){
			memset(a,0,sizeof a);
			work(i,j);
		}
	scanf("%d",&t);
	for (int T = 1;T <= t;T++){
		scanf("%d%d%d",&n,&m,&k);
		if (n > m){
			int tmp = n;
			n = m;
			m = tmp;
		}
		for (int i = 0;i <= n * m;i++) if (f[n][m][i] >= k){
			printf("Case #%d: %d\n",T,i);
			break;
		}
	}
}
