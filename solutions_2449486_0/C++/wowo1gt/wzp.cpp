//#pragma comment(linker, "/STACK:102400000,102400000")
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
using namespace std;
#define ll long long
#define inf 1000000007
#define esp 0.000001
int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}
double max(double x,double y){return x>y?x:y;}
double min(double x,double y){return x<y?x:y;}
int abs(int x) {return x<0?-x:x;}
const int N=105;
const int M=400005;
int mp[N][N];
int n,m;
bool judge1(int x,int y)
{
	int i;
	for(i=x+1;i<=n;i++)
		if(mp[i][y]>mp[x][y]) return 1;
	for(i=x-1;i>=1;i--)
		if(mp[i][y]>mp[x][y]) return 1;
	return 0;
}
bool judge2(int x,int y)
{
	int i;
	for(i=y+1;i<=m;i++)
		if(mp[x][i]>mp[x][y]) return 1;
	for(i=y-1;i>=1;i--)
		if(mp[x][i]>mp[x][y]) return 1;
	return 0;
}
bool judge()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(judge1(i,j)&&judge2(i,j)) return 1;
	return 0;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.out","w",stdout);
    int i,j,k=1,tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				scanf("%d",&mp[i][j]);
			printf("Case #%d: ",k++);
		if(judge()) printf("NO\n");
		else printf("YES\n");

	}
    return 0;
}