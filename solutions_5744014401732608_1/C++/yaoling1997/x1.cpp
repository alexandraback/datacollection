#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const ll maxn= 100;
ll d[maxn],a[maxn][maxn];
ll T,B,M,i,j,k;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	d[0]= 1;
	for (i= 1;i<=50;i++)
		d[i]= d[i-1]*2;
	scanf("%I64d",&T);
	for (ll tt= 1;tt<=T;tt++){
		printf("Case #%I64d: ",tt);
		scanf("%I64d%I64d",&B, &M);
		memset(a,0,sizeof(a));
		if (d[B-2]>=M){
			printf("POSSIBLE\n");
			for (i= 1;i<B;i++)
				if (d[B-i+1-2]<=M) break;
			if (d[B-i+1-2]<M) i--;
			for (j= 1;j<i;j++)
				a[j][i]= 1;
			for (j= i+1;j<B;j++)
				for (k= j+1;k<=B;k++)
					a[j][k]= 1;
			for (j= i+1;j<B;j++)
				if (d[B-j+1-2]<=M){
					M-= d[B-j+1-2];
					a[i][j]= 1;
				}
			if (d[0]<=M){
				M--;
				a[i][B]= 1;
			}
			for (i= 1;i<=B;i++){
				for (j= 1;j<=B;j++)
					printf("%I64d",a[i][j]);
				printf("\n");
			}
		}else printf("IMPOSSIBLE\n");
	}return 0;
}
