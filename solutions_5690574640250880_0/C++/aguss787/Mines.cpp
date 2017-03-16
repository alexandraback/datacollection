#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#include <climits>
#include <cstring>
#include <cassert>
#include <string>
#include <iostream>
#include <queue>
#include <stack>
#define INF INT_MAX
#define pii pair<int,int>
#define s second
#define f first
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define LL long long
#define pLL pair<LL,LL>
#define MOD 1000000007LL
using namespace std;
#ifdef _WIN32
#define getchar_unlocked getchar
#endif
#define g getchar_unlocked
inline void io(int &res){
	register char c;
	while(c=g()){if(c!=' ' && c!='\n')break;}
	res=c-'0';
	while(c=g()){
		if(c==' ' || c=='\n' || c==EOF)break;
		res=(res<<1)+(res<<3)+(c-'0');
	}
}
int y,x;
bool found;
bool vis[100][100];
char map[100][100];
void DFS(int i,int j){
	if(!vis[i][j] && i>0 && j>0 && i<=y && j<=x){
		vis[i][j]=1;
		if(	
		  map[i][j]!='*' &&
		  map[i+1][j-1]!='*' &&
		  map[i+1][j]!='*' &&
		  map[i+1][j+1]!='*' &&
		  map[i][j+1]!='*' &&
		  map[i][j-1]!='*' &&
		  map[i-1][j-1]!='*' &&
		  map[i-1][j]!='*'&&
		  map[i-1][j+1]!='*'
		){
			DFS(i+1,j+1);
			DFS(i+1,j);
			DFS(i+1,j-1);
			DFS(i-1,j+1);
			DFS(i-1,j);
			DFS(i-1,j-1);
			DFS(i,j+1);
			DFS(i,j-1);
		}
	}
}
void DFS1(int i,int j,int m){
	if(found)return;
	if(m==0){
		bool L=1;
		memset(vis,0,sizeof(vis));
		int a,b;
 	    for(int i=1;i<=y && L;i++){
			for(int j=1;j<=x && L;j++){
				if(
				  map[i][j]=='.' &&
				  map[i+1][j-1]=='.' &&
				  map[i+1][j]=='.' &&
				  map[i+1][j+1]=='.' &&
				  map[i][j+1]=='.' &&
				  map[i][j-1]=='.' &&
				  map[i-1][j-1]=='.' &&
				  map[i-1][j]=='.' &&
				  map[i-1][j+1]=='.'
				){
					L=0;
					a=i; b=j;
				}
			}
		}
		if(!L){
			bool can=1;
			DFS(a,b);
			for(int i=1;i<=y;i++){
				for(int j=1;j<=x;j++)
				  if(map[i][j]=='.' && vis[i][j]==0)can=0;
			}
			found=can;
			if(can){
				map[a][b]='c';
					for(int i=1;i<=y;i++){
						for(int j=1;j<=x;j++)
						  putchar(map[i][j]);
						putchar('\n');
					}
			}
		}
	}else{
		if(j>x){
			j=1; i++;
		}
		if(i>y)return;
		map[i][j]='*';
		DFS1(i,j+1,m-1);
		map[i][j]='.';
		DFS1(i,j+1,m);
	}
}
void open(){
	freopen("C-small-attempt3.in","r",stdin);
	freopen("out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}
int main(){
	open();
	int t,no=0; io(t);
	while(t--){
		int m;
		found=0;
 	    printf("Case #%d:\n",++no);
		scanf("%d %d %d",&y,&x,&m);
		//printf("%d %d\n",y,x);
		int T=m,c=0;
		ulang:
		  if(c==1)swap(x,y);
		  m=T;
		  memset(map,'.',sizeof map);
		if(y*x==m+1){
			memset(map,'*',sizeof map);
			map[1][1]='c';
			for(int i=1;i<=y;i++){
				for(int j=1;j<=x;j++)
				  putchar(map[i][j]);
				putchar('\n');
			}
			continue;
		}
		DFS1(1,1,m);
		if(!found)puts("Impossible");
	} 
	close();
	return 0;
}


