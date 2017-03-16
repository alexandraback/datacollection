#include<cstdio>
#include<iostream>
#include<cstring>
#define maxn 109
using namespace std;
int a[maxn][maxn];
bool vis[maxn][maxn];
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int n,m;
bool verti(int x,int y,int h)
{
	if (n==1) return 1;
	if (x==n-1) x--; else x++;
	if (a[x][y]==h) return 1;
	return 0;
}
bool horiz(int x,int y,int h)
{
	if (m==1) return 1;
	if (y==m-1) y--; else y++;
	if (a[x][y]==h) return 1;
	return 0;
}
bool fill(int h)
{
	int b[maxn][maxn];
	memcpy(b,a,sizeof(a));
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (a[i][j]==h)
			{
				bool flag=0;
				if (verti(i,j,h))
				{
					flag=1;
					for (int k=0;k<n && flag;k++) if (a[k][j]!=h) flag=0;
					for (int k=0;k<n && flag;k++) b[k][j]=h+1;
				}
				if (horiz(i,j,h) && !flag)
				{
					flag=1;
					for (int k=0;k<m && flag;k++) if (a[i][k]!=h) flag=0;
					for (int k=0;k<m && flag;k++) b[i][k]=h+1;
				}
				if (!flag) return 0;
			}
	memcpy(a,b,sizeof(b));
//	for (int i=0;i<n;i++) { for (int j=0;j<m;j++) cout<<a[i][j]<<' '; cout<<endl; }
	return 1;
}
bool solve(int max)
{
	for (int i=1;i<=max;i++)
			if (!fill(i)) return 0;
	return 1;
}
int main()
{
	int T;
	cin>>T;
	for (int run=1;run<=T;run++)
	{
		printf("Case #%d: ",run);
		cin>>n>>m;
		int max=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
			{
				cin>>a[i][j];
				if (a[i][j]>max) max=a[i][j];
			}
		if (solve(max)) puts("YES");
		else puts("NO");
	}
	return 0;
}
