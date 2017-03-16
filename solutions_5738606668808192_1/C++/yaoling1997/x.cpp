#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 50,maxm= 1e2;
ll num[maxm];
int d[maxn],a[1000][50],b[1000][20],c[20];
int P[maxm],vis[maxm];
int T,la,N,J,i,j,cnt;
void update(){
	int i,j,k;
	for (i= 2;i<=10;i++){
		ll x;
		c[i]= 0;
		for (j= 1;j<=cnt;j++){
			x= 0;
			for (k= 1;k<=N;k++){
				x= x*i+d[k];
				x%= num[j];
			}
			if (x) continue;
			c[i]= num[j];
		}
		if (!c[i]) return;
	}
	la++;
	for (i= 1;i<=N;i++)
		a[la][i]= d[i];
	for (i= 2;i<=10;i++)
		b[la][i]= c[i];
}
void go(int o){
	if (o==N){
		update();
		return;
	}
	d[o]= 1;
	go(o+1);
	if (la==J) return;
	d[o]= 0;
	go(o+1);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&T);
	vis[0]= vis[1]= 1;
	for (i= 2;i<maxm;i++){
		if (vis[i]) continue;
		num[++cnt]= i;
		ll p= (ll)i*i;
		while (p<maxm){
			vis[p]= 1;
			p+= i;
		}
	}
	for (int t= 1;t<=T;t++){
		printf("Case #%d:\n",t);
		scanf("%d%d",&N, &J);
		d[1]= d[N]= 1;
		go(2);
		if (la<J){
			printf("shit\n");
			continue;
		}
		for (i= 1;i<=la;i++){
			for (j= 1;j<=N;j++)
				printf("%d",a[i][j]);
			for (j= 2;j<=10;j++)
				printf(" %d",b[i][j]);
			printf("\n");
		}			
	}
	return 0;
}
