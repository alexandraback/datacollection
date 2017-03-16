#include <cstdlib>
#include <cstdio>

class Graph{
	public:
		int nVertex;
		int edges[2000][1000];
		int degree[2000];
		int color[2000];
		int ok;
		
		Graph(){}
		
		void init(){
			for(int i=0; i<nVertex; i++){
				degree[i]=0;
				color[i]=0;
			}
			ok = 0;
		}
		
		void insertEdge(int a, int b){
			//printf("%d %d\n",a,b);
			edges[a][degree[a]++] = b;
		}
		
		void dfs(int origin){
		//	printf("-->%d\n",origin);
			color[origin] = 1;
			for(int i=0; i<degree[origin]; i++){
				int next = edges[origin][i];
				if(color[next]==0){
					dfs(next);
				}else if (color[next]==2){
					ok = 1;
				}
			}
			color[origin] = 2;
		//	printf("<--%d\n",origin);
		}

	
};


int main(){
	int T,cases;
	
	Graph g;
	int m;
	int aux;
	int origin[10000];
	int top;
	
	scanf("%d\n",&T);
	cases = 0;
	while(cases < T){
		scanf("%d\n", &g.nVertex);
		top = 0;
		g.init();
		for(int i=0; i<g.nVertex; i++){
			scanf("%d\n",&m);
			if(m==0){
				origin[top++] = i;
			}
			for(int j=0; j<m; j++){
				scanf("%d\n", &aux);
				g.insertEdge(aux-1, i);
			}
		}
		
		for(int i=0; i<top; i++){
			for(int j=0; j<g.nVertex; j++){
				g.color[j]=0;
				
			}
			g.dfs(origin[i]);
		}
		
		printf("Case #%d: ",++cases );
		if(g.ok){
			printf("Yes\n");
		} else {
			printf("No\n");		
		}
		
	}
}
