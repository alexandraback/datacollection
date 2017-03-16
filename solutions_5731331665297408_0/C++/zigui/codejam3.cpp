#include<stdio.h>
#include<string.h>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> way[55];
int visit[55],ZIP[55];
int* ord[55];
int N,M,T,s,cnt;

bool comp(const int* l,const int *r){
	return *l<*r;
}

void DFS(int x)
{
	int tmp=0;
	do{
		tmp = cnt;
		for(int i=0;i<way[x].size();i++){
			if(way[x][i]==visit[cnt]){
				cnt++;
				DFS(way[x][i]);
			}
		}
	}while(tmp!=cnt);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		printf("Case #%d: ",t);
		scanf("%d%d",&N,&M);
		for(int i=1;i<=10;i++)visit[i]=0;
		for(int i=1;i<=N;i++){
			scanf("%d",ZIP+i);
			ord[i] = ZIP+i;
			way[i].clear();
		}
		sort(ord+1,ord+N+1,comp);
		for(int i=1;i<=M;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			way[a].push_back(b);
			way[b].push_back(a);
		}
		int tmp[10]={0,1,2,3,4,5,6,7,8};
		do{
			cnt=2;
			for(int i=1;i<=N;i++)visit[i] = ord[tmp[i]]-ZIP;
			DFS(visit[1]);
			if(cnt==N+1)break;
		}while(next_permutation(tmp+1,tmp+N+1));
		for(int i=1;i<=N;i++)printf("%d",ZIP[visit[i]]);
		printf("\n");
	}
}
