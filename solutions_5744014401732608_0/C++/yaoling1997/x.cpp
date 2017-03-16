#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
int a[10][10];
int B,M,cnt,bl,now,T,i,j;
void check(int o){
	if (o==B){
		now++;
		return;
	}
	int i;
	for (i= o+1;i<=B;i++)
		if (a[o][i]){
			check(i);
			if (now>M) return;
		}
}
void get(int o,int i){
	if (i>B){
		o++;
		i= o+1;
	}
	if (o==B){
		now= 0;
		check(1);
		if (now==M) bl= 1;
		return;
	}
	a[o][i]= 1;
	get(o,i+1);
	if (bl) return;
	a[o][i]= 0;
	get(o,i+1);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int tt= 1;tt<=T;tt++){
		printf("Case #%d: ",tt);
		memset(a,0,sizeof(a));
		scanf("%d%d",&B, &M);
		bl= 0;
		get(1,2);
		if (bl){
			printf("POSSIBLE\n");
			for (i= 1;i<=B;i++){
				for (j= 1;j<=B;j++)
					printf("%d",a[i][j]);
				printf("\n");
			}
		}else printf("IMPOSSIBLE\n");
	}return 0;
}
