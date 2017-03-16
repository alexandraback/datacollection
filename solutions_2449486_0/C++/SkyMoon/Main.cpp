#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int Max=110;
int map[Max][Max];
int n,m;
void solve()
{
	int i,j, k;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
		{
			for(k = 1; k <= m; k ++){
				if(map[i][j] < map[i][k]) break;
			}
			if(k > m) continue;
			for(k = 1; k <= n; k ++){
				if(map[i][j] < map[k][j]) {
					cout<<"NO"<<endl;
					return;
				}
			}
		}
	}
		printf("YES\n");
}
int main()
{
	freopen("Input.txt","r",stdin);
    freopen("1.txt","w",stdout);
	int i,j,t,h;
	scanf("%d",&t);
	for(h=1;h<=t;h++)
	{
		memset(map,0,sizeof(map));
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				scanf("%d",&map[i][j]);
		printf("Case #%d: ",h);
		solve();
	}
	return 0;
}