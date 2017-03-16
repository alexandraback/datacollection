#include <cstdio>
#include <cstring>
bool done=0;
int t,r,c,m,cnt;
int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={-1,1,0,-1,1,0,-1,1};
bool vis[55][55],mine[55][55];
int dfs(int x, int y){
	vis[x][y]=1;
	int change=0;
	for(int z=0;z<8;z++){
		int tempx=x+dx[z],tempy=y+dy[z];
		if(tempx<0||tempx>=r) continue;
		if(tempy<0||tempy>=c) continue;
		if(!mine[tempx][tempy]) continue;
		mine[tempx][tempy]=0;
		cnt--;
		change|=(1<<z);
	}
	
	if(cnt==m){
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(i==0&&j==0) printf("c");
				else if(mine[i][j]) printf("*");
				else printf(".");
			}
			printf("\n");
		}
		return 1;
	}
	if(cnt>m){
		for(int z=0;z<8;z++){
			int tempx=x+dx[z],tempy=y+dy[z];
			if(tempx<0||tempx>=r) continue;
			if(tempy<0||tempy>=c) continue;
			if(vis[x+dx[z]][y+dy[z]]) continue;
			if(dfs(x+dx[z],y+dy[z])==1) return 1;
		}
	}
	for(int z=0;z<8;z++){
		if(change&(1<<z)){
			mine[x+dx[z]][y+dy[z]]=1;
			cnt++;
		}
	}
	vis[x][y]=0;
	return 0;
}
int main(){
	int i=0;
	scanf("%d",&t);
	while(t--){
		printf("Case #%d:\n",++i);
		scanf("%d %d %d",&r,&c,&m);
		if(m==r*c-1){
			for(int x=0;x<r;x++){
				for(int y=0;y<c;y++){
					if(x==0&&y==0) printf("c");
					else printf("*");
				}
				printf("\n");
			}
			continue;
		}
		if(r==2){
			if(m%2==1) printf("Impossible\n");
			else{
				printf("c");
				for(int y=1;y<c-m/2;y++) printf(".");
				for(int y=0;y<m/2;y++) printf("*");
				printf("\n");
				for(int y=0;y<c-m/2;y++) printf(".");
				for(int y=0;y<m/2;y++) printf("*");
				printf("\n");
			}
			continue;
		}
		if(c==2){
			if(m%2==1) printf("Impossible\n");
			else{
				printf("c.\n");
				for(int x=1;x<r-m/2;x++) printf("..\n");
				for(int x=0;x<m/2;x++) printf("**\n");
			}
			continue;
		}
		cnt=r*c-1;
		memset(vis,0,sizeof(vis));
		for(int x=0;x<r;x++) for(int y=0;y<c;y++) mine[x][y]=1;
		mine[0][0]=0;
		if(dfs(0,0)==0) printf("Impossible\n");
	}
	return 0;
}
