#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int grid[101][101];
int max_x[101];
int max_y[101];
int main(){
	int T,ct=1;
	//freopen("B-small-attempt0.in","r",stdin);
	//freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		printf("Case #%d: ",ct++);
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&grid[i][j]);
			}
		}
		for(int i=0;i<n;i++)max_x[i]=0;
		for(int j=0;j<m;j++)max_y[j]=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				max_x[i]=max(max_x[i],grid[i][j]);
				max_y[j]=max(max_y[j],grid[i][j]);
			}
		}
		int find=false;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(grid[i][j]<max_x[i]&&grid[i][j]<max_y[j])find=true;
			}
		}
		if(find)printf("NO\n");
		else printf("YES\n");
	}
}
