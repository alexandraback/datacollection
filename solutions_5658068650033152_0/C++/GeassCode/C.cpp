#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define maxn 25
int n,m,nd;
int a[maxn][maxn],mark[maxn][maxn];
int dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};
void init(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			a[i][j]=0;
			mark[i][j]=0;
		}
	}
}
int check(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m)return 1;
	return 0;
}
void dfs(int x,int y)
{
	if(mark[x][y])return ;
	int i;
	mark[x][y]=1;
	for(i=0;i<4;i++){
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(!check(xx,yy)||a[xx][yy])continue;
		dfs(xx,yy);
	}
}
int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("C-small-attempt1.out","w",stdout);
	int i,j,k;
	int t,cas;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++){
		scanf("%d%d%d",&n,&m,&nd);
		int nm=n*m;
		int x,y;
		int res=nd;
		for(i=0;i<(1<<nm);i++){
			init();
			int tmp=0;
			for(j=0;j<nm;j++){
				if(i&(1<<j)){
					x=j/m;y=j%m;
					a[x][y]=1;
				//	mark[x][y]=2;
					tmp++;
				}
			}
			int r,c;
			int cnt=0;
			for(r=0;r<n;r++){ 
				for(c=0;c<m;c++){
					if(r==0||r==n-1||c==0||c==m-1)
						if(!a[r][c])dfs(r,c);
					//if(mark[r][c]==2)cnt++;
					//printf("%d: %d %d %d\n",i,r,c,mark[r][c]);
				}
			}
			cnt=n*m;
			for(r=0;r<n;r++){
				for(c=0;c<m;c++){
					cnt-=mark[r][c];
				}
			}
			if(cnt>=nd)res=min(res,tmp);
		}
		printf("Case #%d: %d\n",cas,res);
	}
	return 0;
}
					
		
		
