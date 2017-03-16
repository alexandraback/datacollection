#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <complex>
#include <algorithm>
using namespace std;
const int N = 101;
typedef long long ll;
 
int t,n,r,c,m;
int fdr[4] = {0,1,0,-1};
int fdc[4] = {1,0,-1,0};
int dr[8] = {-1,-1,0,1,1,1,0,-1};
int dc[8] = {0,1,1,1,0,-1,-1,-1};
char g[N][N];
bool vis[N][N];
struct node{
	int r,c;
	node(){}
	node(int a,int b){
		r=a;
		c=b;
	}
};
int bfs(int fr,int fc){
	int num=1;
	queue<node> q;
	q.push(node(fr,fc));
	while(!q.empty()){
		node s = q.front();
		q.pop();
		vis[s.r][s.c]=true;
		bool can=true;
		for(int i=0;i<8;++i){
			int nr = dr[i]+s.r;
			int nc = dc[i]+s.c;
			if(nr<0||nc<0||nr>=r||nc>=c||vis[nr][nc])continue;
			if(g[nr][nc]=='*'){
				can = false;
				break;
			}
		}
		if(can)
			for(int i=0;i<8;++i){
				int nr = dr[i]+s.r;
				int nc = dc[i]+s.c;
				if(nr<0||nc<0||nr>=r||nc>=c||vis[nr][nc])continue;
				vis[nr][nc]=true;
				q.push(node(nr,nc));
				++num;
			}
	}
	return num;
}
bool Ok=false;
bool calc(int i,int j,int num){
	if(Ok)
		return true;
	if(i>=r)
		return 0;
	if(num==m){
		for(int e=0;e<r;++e){
			for(int f=0;f<c;++f){
				memset(vis,0,sizeof(vis));
				if(g[e][f]=='.' && bfs(e,f)==r*c-m){
					g[e][f]='c';
					for(int k=0;k<r;++k){
						for(int l=0;l<c;++l){
							printf("%c",g[k][l]);
						}
						printf("\n");
					}
					Ok = true;
					return true;
				}
			}
		}
		return false;
	}
	if(j==c-1){
		g[i][j]='*';
		if(calc(i+1,0,num+1))
			return 1;
		g[i][j]='.';
		if(calc(i+1,0,num))
			return 1;
	}
	else{
		g[i][j]='*';
		if(calc(i,j+1,num+1))
			return 1;
		g[i][j]='.';
		if(calc(i,j+1,num))
			return 1;
	}
	return 0;
}
bool calc2(int i,int j,int num){
	if(Ok)
		return true;
	if(i>=r||j>=c||num>m)
		return false;
	/*if(num==m){
		for(int e=0;e<r;++e){
			for(int f=0;f<c;++f){
				memset(vis,0,sizeof(vis));
				if(g[e][f]=='.' && bfs(e,f)==r*c-m){
					g[e][f]='c';*/
					if(num==m)
					for(int k=0;k<r;++k){
						for(int l=0;l<c;++l){
							printf("%c",g[k][l]);
						}
						printf("\n");
					}
					printf("\n\n\n\n\n\n");
				/*	Ok = true;
					return true;
				}
			}
		}
		return false;
	}*/
	bool x=false;
	g[i][j] = '.';
	x|=calc2(i+1,j,num);
	if(x)
		return true;
	x|=calc2(i,j+1,num);
	if(x)
		return true;
	g[i][j] = '*';
	x|=calc2(i+1,j,num+1);
	if(x)
		return true;
	x|=calc2(i,j+1,num+1);
	if(x)
		return true;
	g[i][j] = '.';
	return x;
}
int main(){
 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	for(int k=1;k<=t;++k){
		scanf("%d %d %d",&r,&c,&m);
		for(int i=0;i<r;++i)
			for(int j=0;j<c;++j)
				g[i][j] = '.';
		printf("Case #%d:\n",k);
		if(!calc(0,0,0))
			puts("Impossible");
		Ok=false;
	}
 
    return 0;
}
