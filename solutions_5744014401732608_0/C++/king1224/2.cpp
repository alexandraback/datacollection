#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

bool slide[60][60];
int count=0;
queue< vector<int> > q;

void DFS(int B,int M){
/*	printf("road = ");
	for(int i=0;i<road.size();++i){
		printf("%d ",road[i]);
	}
	printf("\n");
//	printf("\nnow_build=%d\n",build);
*/
	vector<int> road;
	while(!q.empty()){
		road=q.front();
		q.pop();
		int len=road.size();

/*		printf("road = ");
		for(int i=0;i<road.size();++i){
			printf("%d ",road[i]);
		}
		printf("\n");*/

		if(count==M){
			return ;
		}
		if(road[len-1]==B){
			++count;
			int x,y;
			for(int i=1;i<road.size();++i){
				x=road[i-1];
				y=road[i];
				slide[x][y]=true;
			}
			continue;
		}

		bool vis[60];
		memset(vis,false,sizeof(vis));
		for(int i=0;i<len;++i){
			vis[road[i]]=true;
		}
		road.push_back(0);
		for(int i=1;i<=B;++i){
			if(!vis[i]){
				road[len]=i;
				q.push(road);
			}
		}
	}
}

int main(){
	int T;
	int B,M;//B 建築物數量, M 路徑數必須剛好
	vector<int> road;
	road.push_back(1);
	scanf("%d",&T);
	for(int z=1;z<=T;++z){
		while(!q.empty()) q.pop();
		q.push(road);
		scanf("%d %d",&B,&M);
		count=0;
		memset(slide,false,sizeof(slide));
		//DFS
		DFS(B,M);
		printf("Case #%d: ",z);
		if(count<M){
			printf("IMPOSSIBLE\n");
		}
		else{
			printf("POSSIBLE\n");
			for(int i=1;i<=B;++i){
				for(int j=1;j<=B;++j){
					if(slide[i][j])
						printf("1");
					else
						printf("0");
				}
				printf("\n");
			}
		}
	}
}
